#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int dp[101][100001];
int W[101];
int V[101];

void solve(){

	for (int a = 1; a <= N; ++a) {
		for (int b = 1; b <= K; ++b) {
			if (b >= W[a]) {
				dp[a][b] = max(dp[a - 1][b], dp[a - 1][b - W[a]] + V[a]);
			}
			else
				dp[a][b] = dp[a - 1][b];
		}
	}
	cout << dp[N][K];

}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);

	cin >> N >> K;

	for (int a = 1; a <= N; ++a) {
		cin >> W[a] >> V[a];
	}

	solve();
	return 0;
}
