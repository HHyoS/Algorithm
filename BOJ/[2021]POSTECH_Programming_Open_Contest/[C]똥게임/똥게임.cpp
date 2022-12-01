#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
int n;
int dp[2][2];
	int main() {

		/*	ios::sync_with_stdio(0);
			cin.tie(0);
			cout.tie(0);*/

	//	freopen("Input.txt", "r", stdin);
		scanf("%d", &n);

	int dp[2][2];

	dp[0][0] = 1;
	dp[0][1] = 1;

	char command[2];
	int num[2];

	for (int a = 1; a <= n; ++a) {
		int now = a % 2;
		int before = (a + 1) % 2;
		scanf(" %c%d", &command[0], &num[0]);
		scanf(" %c%d", &command[1], &num[1]);
		dp[now][0] = 0;
		dp[now][1] = 0;
		for (int b = 0; b < 2; ++b) {
			if (command[b] == '+') {
				if (dp[before][0] > 0)
					dp[now][0] = max(dp[before][0] + num[b], dp[now][0]);
				if (dp[before][1] > 0)
					dp[now][1] = max(dp[before][1] + num[b], max(dp[now][1],dp[before][0]));
			}
			else if (command[b] == '-') {
				if (dp[before][0] > 0)
					dp[now][0] = max(dp[before][0] - num[b], dp[now][0]);
				if (dp[before][1] > 0)
					dp[now][1] = max(dp[before][1] - num[b], max(dp[now][1], dp[before][0]));
			}
			else if (command[b] == '*') {
				if (dp[before][0] > 0)
					dp[now][0] = max(dp[before][0] * num[b], dp[now][0]);
				if (dp[before][1] > 0)
					dp[now][1] = max(dp[before][1] * num[b], max(dp[now][1], dp[before][0]));
			}
			else {
				if (dp[before][0] > 0)
					dp[now][0] = max(dp[before][0] / num[b], dp[now][0]);
				if (dp[before][1] > 0)
					dp[now][1] = max(dp[before][1] / num[b], max(dp[now][1], dp[before][0]));
			}
		}
		if ((dp[now][0] <= 0) && (dp[now][1] <= 0)){
			printf("ddong game");
			return 0;
		}
	}
	printf("%d", max(dp[n%2][0], dp[n%2][1]));
	return 0;
}
