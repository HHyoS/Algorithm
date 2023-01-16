#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
int N, M, K;
int first[3001];
int second[3001];
int dp[3001][3001];
int solve() {
    int ans = 0;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            if (first[a] != second[b]) {
                continue;
            }
            if (a == 0 || b == 0) {
                dp[a][b] = 1;
            }
            else {
                dp[a][b] = dp[a - 1][b - 1] + 1;
            }
            ans = max(ans, dp[a][b]);
        }
    }
    return ans;
}
void input() {
    cin >> N >> M >> K;
    for (int a = 0; a < N; ++a) {
        cin >> first[a];
    }
    for (int b = 0; b < M; ++b) {
        cin >> second[b];
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    input();
    cout << solve();
	return 0;
}
