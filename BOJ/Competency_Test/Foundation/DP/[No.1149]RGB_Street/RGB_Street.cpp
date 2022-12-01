#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000][3];
int dp[1000][3];


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("Input.txt", "r", stdin);
	cin >> n;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < 3; ++b) {
			cin >> arr[a][b];
		}
	}
	for (int a = 0; a < n; ++a)
		dp[0][a] = arr[0][a];
	int index = 1;
	for (int a = 1; a < n; ++a) {
			dp[a][0] = min(dp[a - 1][1], dp[a - 1][2]) + arr[a][0];
			dp[a][1] = min(dp[a - 1][0], dp[a - 1][2]) + arr[a][1];
			dp[a][2] = min(dp[a-1][0], dp[a - 1][1]) + arr[a][2];
	}
	cout << min(dp[n-1][0], min(dp[n - 1][1], dp[n - 1][2])) << "\n";
	return 0;
}
