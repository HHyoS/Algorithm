#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
int dp[1001][2];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("Input.txt", "r", stdin);
	cin >> N;
	for (int a = 1; a <= N; ++a)
		cin >> dp[a][0];
	
	for (int a = 1; a <= 1000; ++a) {
		dp[a][1] = 2000;
	}
	dp[1][1] = 0;
	for (int a = 1; a < N; ++a) {
		for (int b = 1; b <= dp[a][0]; ++b) {
			if (dp[a + b][1] > (dp[a][1] + b))
				dp[a + b][1] = dp[a][1] + 1;
		}
	}
	if (dp[N][1] != 2000)
		cout << dp[N][1];
	else
		cout << -1;
	return 0;
}
