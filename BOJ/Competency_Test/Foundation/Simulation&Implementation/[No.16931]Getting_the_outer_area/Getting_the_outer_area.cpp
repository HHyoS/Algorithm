#include <iostream>
#include <vector>
using namespace std;
int n , m ;
int arr[102][102];


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("Input.txt", "r", stdin);
	cin >> n >> m;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= m; ++b) {
			cin >> arr[a][b];
		}
	}
	int answer = 0;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= m; ++b) {
			answer += (arr[a][b] * 4 + 2);
			if (arr[a][b + 1] >= arr[a][b])
				answer -= arr[a][b];
			else
				answer -= arr[a][b + 1];

			if (arr[a][b - 1] >= arr[a][b])
				answer -= arr[a][b];
			else
				answer -= arr[a][b-1];

			if (arr[a + 1][b] >= arr[a][b])
				answer -= arr[a][b];
			else
				answer -= arr[a + 1][b];

			if (arr[a - 1][b] >= arr[a][b])
				answer -= arr[a][b];
			else
				answer -= arr[a - 1][b];
		}
	}
	cout << answer;
	return 0;
}
