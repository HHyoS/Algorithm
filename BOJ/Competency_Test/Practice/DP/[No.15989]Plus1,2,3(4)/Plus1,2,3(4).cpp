#include <iostream>
using namespace std;

int dp[10001][4] = { 0, };
int cur = 0;
int t;

void solution() {
	dp[0][1] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 10000; i++) {
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		if (i >= 3)
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}
}

int main() {
	int n;
	scanf("%d", &t);
	solution();
	cur = 3;
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", dp[n][1] + dp[n][2] + dp[n][3]);
	}
	return 0;
}
