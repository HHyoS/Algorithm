#include <iostream>
using namespace std;
int coin[101];
int dp[10001];
int main() {
	int n, k;
	scanf("%d %d",&n,&k);
	for (int a = 1; a <= n; ++a)
    scanf("%d",&coin[a]);
	dp[0] = 1;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= k; ++b) {
			if (b - coin[a] >= 0)
				dp[b] += dp[b - coin[a]];
		}
	}
	printf("%d",dp[k]);
	return 0;
}
