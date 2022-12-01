#include <cstdio>
#include <algorithm>
using namespace std;


int dp[3][100000+1] = { 0, };
int arr[3][100000+1] = { 0, };
int main() {
    int n;
    int m;
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &n);
        for (int b = 1; b < 3; ++b) {
            for (int a = 1; a <= n; ++a) {
                scanf("%d", &arr[b][a]);
            }
        }
        dp[1][1] = arr[1][1];
        dp[2][1] = arr[2][1];

        for (int a = 2; a <= n; ++a) {
            dp[1][a] = max(dp[0][a - 1] + arr[1][a], dp[2][a - 1] + arr[1][a]);
            dp[2][a] = max(dp[0][a - 1] + arr[2][a], dp[1][a - 1] + arr[2][a]);
            dp[0][a] = max(dp[1][a - 1], dp[2][a - 1]);
        }
        printf("%d\n", max(dp[1][n], dp[2][n]));
    }
    return 0;
}
