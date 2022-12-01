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
    int mp[1000 + 1] = { 0 };
    for (int a = 2; a <= n; ++a) {
        for (int b = 1; b < a; ++b) {
            if (ar[b] < ar[a]) {
                if (dp[a] < dp[b] + 1) {
                    dp[a] = max(dp[a], dp[b] + 1);
                    mp[a] = b;
                }
            }
        }
    }
    int big = *max_element(dp, dp + n + 1) + 1;
    printf("%d\n", big);
    int aa = big;
    int ch = 0;
    for (int a = n; a >= 1; --a) {
        if (big == dp[a]+1) {
            ch = a;
            break;
        }
    }
    while (big--) {
        dp[big] = ch;
        ch = mp[ch];
    }
    for (int a = 0; a < aa; ++a) {
        printf("%d ", ar[dp[a]]);
    }
    return 0;
}
