#include <cstdio>
#include <algorithm>
using namespace std;


int main() {
    int n;
    int ar[1000 + 1] = { 0, };
    scanf("%d", &n);
    for (int a = 1; a <= n; ++a) {
        scanf("%d", &ar[a]);
    }
    int dp[1000 + 1] = { 0 };
    for (int a = 2; a <= n; ++a) {
        for (int b = 1; b < a; ++b) {
            if (ar[b] < ar[a]) {
                dp[a] = max(dp[a], dp[b] + 1);
            }
        }
    }
    printf("%d", *max_element(dp,dp+n+1)+1);
    return 0;
}
