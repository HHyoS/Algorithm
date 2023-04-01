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
int ans = -1;
void dfs(int idx, int calo, int manjok) {
    if (idx == N + 1) {
        ans = max(ans, manjok);
        return;
    }
    for (int a = idx + 1; a <= N; ++a) {
        if (calo + cal[a] <= L) {
            dfs(a, calo + cal[a], manjok + happy[a]);
        }
    }
    dfs(idx + 1, calo, manjok);
}
void solve() {
    memset(dp, 0, sizeof(dp));
    ans = -1;
    for (int a = 1; a <= N; ++a) {
        dfs(a, cal[a], happy[a]);
    }
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
        cout << "#" << t << " " << ans << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   // freopen("input.txt", "r", stdin);

    input();
    return 0;
}
