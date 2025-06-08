#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1, vector<int>(N+1, 0));
    for (int i = 0, u, v; i < M; ++i) {
        cin >> u >> v;
        adj[u][v] = 1; // u가 v보다 무겁다
    }

    // Floyd-Warshall로 도달 가능 여부 계산
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (adj[i][k] && adj[k][j])
                    adj[i][j] = 1;

    int impossible = 0;
    int half = (N + 1) / 2;

    // 각 구슬 i에 대해 무거운 구슬(greater)과 가벼운 구슬(lesser) 수를 센다
    for (int i = 1; i <= N; ++i) {
        int heavier = 0, lighter = 0;
        for (int j = 1; j <= N; ++j) {
            if (adj[i][j]) ++lighter;   // i보다 가벼운 j
            if (adj[j][i]) ++heavier;   // i보다 무거운 j
        }
        if (heavier >= half || lighter >= half)
            ++impossible;
    }

    cout << impossible << "\n";
    return 0;
}
