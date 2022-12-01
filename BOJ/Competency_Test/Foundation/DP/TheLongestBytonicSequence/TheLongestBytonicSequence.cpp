#include <cstdio>
#include <algorithm>
using namespace std;


int main() {
    int n;
    int ar[1000 + 1] = { 0, };
    int dp[1000 + 1][2] = { 0 };
    scanf("%d", &n);
    for (int a = 1; a <= n; ++a) {
        scanf("%d", &ar[a]);
    }
    for (int a = 2; a <= n; ++a) {
        for (int b = 1; b < a; ++b) {
            if (ar[b] < ar[a]) {
                dp[a][0] = max(dp[a][0], dp[b][0] + 1);
            }
        }
    }
   for (int a = n-1; a >= 1; --a) {
        for (int b = n; b > a; --b) {
            if (ar[b] < ar[a]) {
                dp[a][1] = max(dp[a][1], dp[b][1] + 1);
            }
        }
    }
    int big = 0;
    for (int a = 1; a <= n; ++a) {
        if (big < dp[a][1] + dp[a][0]){
            big = dp[a][1] + dp[a][0];
        }
    }
    printf("%d\n", big+1);
    return 0;
}
