#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int n, m;

int dp[2][10001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);
	cin >> n >> m;
	for (int a = 0; a <= 1; ++a) {
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
    int bbig = dp[1][m];
	for (int a = 2; a <= n; ++a) {
		int now = a % 2;
		int before = (a + 1) % 2;
		for (int b = 1; b <= m; ++b) {
			if (b > a * 15)
				break;
			int big = -1;

			if (b >= 15) {
				if (dp[before][b - 15] >= 0)
					big = max(big, dp[before][b - 15]);
				if (dp[before][b - 1] >= 0)
					big = max(big, dp[before][b - 1] + 1);
				if (dp[before][b - 3] >= 0)
					big = max(big, dp[before][b - 3] + 2);
				if (dp[before][b - 7] >= 0)
					big = max(big, dp[before][b - 7] + 4);
			}
			else if (b >= 7) {
				if (dp[before][b - 1] >= 0)
					big = max(big, dp[before][b - 1] + 1);
				if (dp[before][b - 3] >= 0)
					big = max(big, dp[before][b - 3] + 2);
				if (dp[before][b - 7] >= 0)
					big = max(big, dp[before][b - 7] + 4);
			}
			else if (b >= 3) {
				if (dp[before][b - 1] >= 0)
					big = max(big, dp[before][b - 1] + 1);
				if (dp[before][b - 3] >= 0)
					big = max(big, dp[before][b - 3] + 2);
			}
			else {
				if (dp[before][b - 1] >= 0)
					big = max(big, dp[before][b - 1] + 1);
			}
			dp[now][b] = big;
            if(b==m){
                bbig = max(bbig,dp[now][b]);
            }
		}
	}
	cout << bbig;
	return 0;
}

