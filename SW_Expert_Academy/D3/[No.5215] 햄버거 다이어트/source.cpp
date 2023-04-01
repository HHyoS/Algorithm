#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, l;
pair<int, int> p[30];
int dp[10004];

int main() {
    int t;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++) {
        scanf("%d %d", &n, &l);

        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p[i].first, &p[i].second);

            for (int j = l; j >= p[i].second; j--) {
                if (dp[j] < p[i].first + dp[j - p[i].second])
                    dp[j] = p[i].first + dp[j - p[i].second];
            }
        }
        printf("#%d %d\n", tc, dp[l]);
    }
}
