#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> S, W;
int ans = 0;

void dfs(int idx) {
    if (idx == N) {
        // Count broken eggs
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] <= 0) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    
    // If current egg is already broken or no other unbroken egg to hit, skip
    if (S[idx] <= 0) {
        dfs(idx + 1);
        return;
    }
    
    // Check if there is any target to hit
    bool hit = false;
    for (int j = 0; j < N; j++) {
        if (j == idx) continue;
        if (S[j] > 0) {
            hit = true;
            // Simulate hit
            int ori_si = S[idx];
            int ori_sj = S[j];
            
            S[idx] -= W[j];
            S[j]   -= W[idx];
            
            dfs(idx + 1);
            
            // Backtrack
            S[idx] = ori_si;
            S[j]   = ori_sj;
        }
    }
    
    // If no hit was possible, move to next
    if (!hit) {
        dfs(idx + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    S.resize(N);
    W.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> W[i];
    }

    dfs(0);
    cout << ans;
    return 0;
}
