#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;

bool visited[11];
vector<int> arr[11];
int maxi = -1;
void dfs(int idx, int leng) {

    for (int a = 0; a < arr[idx].size(); ++a) {
        if (visited[arr[idx][a]] == 0) {
            visited[arr[idx][a]] = 1;
            dfs(arr[idx][a], leng + 1);
            visited[arr[idx][a]] = 0;
        }
    }
    maxi = max(maxi, leng);
}
void solve() {

    for (int a = 1; a <= N; ++a) {
        visited[a] = 1;
        dfs(a, 1);
        visited[a] = 0;
    }
}
void input() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> M;
        for (int a = 0; a < M; ++a) {
            int from, to;
            cin >> from >> to;
            arr[from].push_back(to);
            arr[to].push_back(from);
        }
        solve();
        cout << "#" << t << " " << maxi << "\n";
        maxi = 0;
        for (int a = 1; a <= N; ++a) {
            arr[a].clear();
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 //   freopen("input.txt", "r", stdin);

    input();
    return 0;
}
