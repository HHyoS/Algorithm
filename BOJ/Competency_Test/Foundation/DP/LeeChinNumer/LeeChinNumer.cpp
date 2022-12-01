#include <cstdio>
using namespace std;


long long dp[2][2] = { 0, };
int main() {
    int n;
    scanf("%d", &n);
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int a = 2; a <= n; ++a) {
        int m = a % 2;
        dp[m][0] = dp[!m][0] + dp[!m][1];
        dp[m][1] = dp[!m][0];
    }



    printf("%lld", dp[n % 2][0] + dp[n % 2][1]);
    return 0;
}
