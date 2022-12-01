#include <cstdio>
using namespace std;

#define M 10007

int dp[2][10] = { 0, };
int main() {
    int n;
    scanf("%d", &n);
    for (int a = 1; a < 10; ++a) {
        dp[1][a] = 1;
    }
    int sum = 10;

    for (int a = 2; a <= n; ++a) {
        int index = a % 2;
        for (int b = 1; b < 10; ++b) {
            dp[index][b] = (dp[index][b - 1] + dp[!index][b])%M;
            sum = (sum + dp[index][b]) % M;
        }
    }

    printf("%d", sum);
    return 0;
}
