#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[11];
bool check[11];
int answer = 0;
void dfs(int count, int sum) {
	if (count == (n-2)) {
		if (sum > answer)
			answer = sum;
		return;
	}

	int left = 0, right = 0;
	for (int a = 2; a < n; ++a) {
		if (check[a])
			continue;
		check[a] = 1;
		for (int b = a-1; b > 0; --b) {
			if (!check[b]) {
				left = arr[b];
				break;
			}
		}
		for (int b = a + 1; b <= n; ++b) {
			if (!check[b]) {
				right = arr[b];
				break;
			}
		}
		dfs(count + 1, sum + (left*right));

		check[a] = 0;
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("Input.txt", "r", stdin);
	cin >> n;
	for (int a = 1; a <= n; ++a) {
		cin >> arr[a];
	}
	for (int a = 2; a < n; ++a) {
		int sum;
		check[a] = 1;
		sum = arr[a - 1] * arr[a + 1];
		dfs(1,sum);
		check[a] = 0;

	}
	cout << answer;
	return 0;
}
