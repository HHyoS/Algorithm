#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;



long long dp[35][35][3];
int N;
long long map[35][35];
int state[2][2] = { {0,-1},{-1,0}};



bool check(int x, int y) {
    for (int a = 0; a < 2; ++a) {
        int nx = x + state[a][0];
        int ny = y + state[a][1];
        if (map[nx][ny] == 1)
            return 0;
    }
    return 1;
}
long long solve() {
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            if (a == 1 && b < 3)continue;
            if (map[a][b] == 1) continue;
            dp[a][b][0]= dp[a][b - 1][0] + dp[a][b - 1][2];
            dp[a][b][1] = dp[a - 1][b][1] + dp[a - 1][b][2];
            if (check(a, b)) {
                dp[a][b][2] = dp[a - 1][b - 1][2] + dp[a - 1][b - 1][0] + dp[a-1][b - 1][1];
            }
        }
    }
    return dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
}
void input() {
    cin >> N;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            cin >> map[a][b];
        }
    }
    dp[1][2][0] = 1;
 }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    cout << solve();
    return 0;
}
