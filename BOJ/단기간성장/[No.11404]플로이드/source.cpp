#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int map[101][101];
int N,M;

void solve() {
    for (int b = 1; b <= N; ++b) {
        for (int a = 1; a <= N; ++a) {
            if (a == b) continue;
            if (map[a][b] == 21e8) continue;
            for (int c = 1; c <= N; ++c) {
                if (b == c) continue;
                if (map[b][c] == 21e8) continue;
                map[a][c] = min(map[a][c], map[a][b] + map[b][c]);
            }
        }
    }
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            if (map[a][b] == 21e8)
                cout << "0 ";
            else
                cout << map[a][b] << " ";
        }
        cout << "\n";
    }
}
void input() {
    cin >> N >> M;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            if (a == b) {
                map[a][b] = 0;
            }
            else {
                map[a][b] = 21e8;
            }
        }
    }
    for (int a = 0; a < M; ++a) {
        int from, to, cost;
        cin >> from >> to >> cost;
        if(map[from][to] > cost)
            map[from][to] = cost;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   // freopen("input.txt", "r", stdin);
    input();
    solve();
    return 0;
}
