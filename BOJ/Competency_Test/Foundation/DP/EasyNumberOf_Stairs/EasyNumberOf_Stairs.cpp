#include <cstdio>
using namespace std;

#define M 1000000000

int dp[2][12] = { 0, };
int main() {
    int n;
    scanf("%d", &n);
    for (int a = 2; a <= 10; ++a) {
        dp[0][a] = 1;
    }

    int index = 1;
    for (int a = 2; a <= n; ++a) {
        for (int b = 1; b <= 10; ++b) {
            if (index == 1) {
                dp[1][b] = (dp[0][b - 1] + dp[0][b + 1]) % M;
            }
            else if (index == 0) {
                dp[0][b] = (dp[1][b - 1] + dp[1][b + 1]) % M;
            }
        }
        index = !index;
    }

    int sum = 0;
    for (int a = 1; a <= 10; ++a) {
        sum = (sum + dp[!index][a]) % M;
    }
    printf("%d", sum);
    return 0;
}
