#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int N,L;
int dp[21][1001];
int cal[21];
int happy[21];
void solve() {

    for (int a = 1; a <= N; ++a) {
        for (int b = L; b >= 0; --b){
            if (b < cal[a]) {
                dp[a][b] = dp[a - 1][b];
            }
            else {
                dp[a][b] = max(dp[a - 1][b], dp[a - 1][b - cal[a]] + happy[a]);
            }
        }
    }
    int maxi = -1;
    for (int a = L; a >= 0; --a) {
        maxi = max(dp[N][a], maxi);
    }
    cout << maxi << "\n";
}
void input() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> L;
        for (int a = 1; a <= N; ++a) {
            cin >> happy[a] >> cal[a];
        }
        solve();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  //  freopen("input.txt", "r", stdin);

    input();
    return 0;
}
