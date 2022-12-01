#include <cstdio>
#include <algorithm>
using namespace std;


int dp[10000 + 1][3] = { 0, };
int arr[10000 + 1] = { 0, };
int main() {
    int n;

    scanf("%d", &n);
    for (int a = 1; a <= n; ++a) {
        scanf("%d", &arr[a]);
    }
    dp[1][1] = arr[1];
    dp[2][1] = arr[2];
    dp[2][2] = arr[1] + arr[2];

    
    for (int a = 3; a <= n; ++a) {
        for (int b = 0; b < 3; ++b) {
            if (b == 0)
                dp[a][b] = max({dp[a - 1][1], dp[a - 1][2],dp[a-2][1],dp[a-2][2]});

            else if (b == 1)
                dp[a][b] = max({dp[a-1][0]+arr[a],dp[a-2][1]+arr[a],dp[a-2][2]+arr[a]});

            else
                dp[a][b] = dp[a - 1][1] + arr[a];
        }
    }
    printf("%d", max({ dp[n - 1][2],dp[n][2],dp[n][1] }));
    return 0;
}
