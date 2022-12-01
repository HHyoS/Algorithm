#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int mov[3][2] = { {1,0},{0,1},{1,1} };
int arr[1000][1000];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("Input.txt", "r", stdin);

	cin >> n >> m;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			cin >> arr[a][b];
		}
	}
	for (int a = 1; a < m; ++a) {
		arr[0][a] = arr[0][a - 1] + arr[0][a];
	}
	for (int a = 1; a < n; ++a) {
		arr[a][0] = arr[a - 1][0] + arr[a][0];
	}
	for (int a = 1; a < n; ++a) {
		for (int b = 1; b < m; ++b) {
			arr[a][b] = max(arr[a - 1][b], max(arr[a][b - 1], arr[a - 1][b - 1])) + arr[a][b];
		}
	}
	cout << arr[n-1][m-1];
	return 0;
}

