#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int N, K;
int nums[21];
int ans = 0;
void dfs(int idx,int sum) {
    if (idx == N) {
        if (sum == K)
            ++ans;
        return;
    }
    if (sum == K) {
        ++ans;
        return;
    }
    
    for (int a = idx + 1; a <= N; ++a) {
        int temp = sum + nums[a];
        if (temp > K)
            continue;
        dfs(a, sum + nums[a]);
    }
}
void solve() {
    int ans = 0;
    for (int a = 1; a <= N; ++a) {
        dfs(a, nums[a]);
    }
}
void input() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> K;
        for (int a = 1; a <= N; ++a) {
            cin >> nums[a];
        }
        solve();
        cout << "#" << t << " " << ans << "\n";
        ans = 0;
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
