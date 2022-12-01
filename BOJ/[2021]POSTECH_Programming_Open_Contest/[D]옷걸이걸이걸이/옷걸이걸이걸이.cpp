#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int n, m;

int dp[5001][10001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);
	cin >> n >> m;
	for (int a = 0; a <= n; ++a) {
		for (int b = 0; b <= m; ++b) {
			if (b == 0)
				dp[a][b] = 0;
			else
				dp[a][b] = -1;
		}
	}
	dp[1][1] = 1;
	dp[1][3] = 2;
	dp[1][7] = 4;
	dp[1][15] = 0;
	for (int a = 2; a <= n; ++a) {
		for (int b = 1; b <= m; ++b) {
			int big = -1;
			if ((b - 15 >= 0) && (dp[a - 1][b - 15] >= 0))
				big = max(big, dp[a - 1][b - 15]);
			if ((b - 1 >= 0) && dp[a - 1][b - 1] >= 0)
				big = max(big,dp[a - 1][b - 1] + 1);
			if ((b - 3 >= 0) && (dp[a - 1][b - 3] >= 0))
				big = max(big, dp[a - 1][b - 3] + 2);
			if ((b - 7 >= 0) && (dp[a - 1][b - 7]  >= 0))
				big = max(big, dp[a - 1][b - 7] + 4);
			dp[a][b] = big;
		}
	}
	int big = -1;
	for (int a = 1; a <= n; ++a) {
		big = max(big, dp[a][m]);
	}
	cout << big;
	return 0;
}

