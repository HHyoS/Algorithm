#include <cstdio>
using namespace std;

int dp[100000 + 1][3] = { 0, };
int main() {
    int n;
    scanf("%d", &n);
    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    int num;
    int index = 3;
    while (n--) {
        scanf("%d", &num);
        if (num > index) {
            for (int a = index+1; a <= num; ++a) {
                dp[a][0] = (dp[a - 1][1] + dp[a - 1][2]) % 1000000009;
                dp[a][1] = (dp[a - 2][0] + dp[a - 2][2]) % 1000000009;
                dp[a][2] = (dp[a - 3][0] + dp[a - 3][1]) % 1000000009;
            }
            index = num;
        }
        printf("%d\n", ((dp[num][0] + dp[num][1]) % 1000000009 + dp[num][2]) % 1000000009);
    }
    return 0;
}
