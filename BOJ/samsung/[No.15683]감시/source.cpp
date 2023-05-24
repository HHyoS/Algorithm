#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

struct Node {
    int x;
    int y;
};
vector<int>cctv[6];
Node mov[4] = {{-1,0},{0,1},{1,0},{0,-1} };
int map[9][9];
int test[9][9];
int N, M;
vector<Node> location;
int path[10];
int mini = 21e8;

void simul() {
    memset(test, 0, sizeof(test));

    for (int a = 0; a < location.size(); ++a) {
        int x = location[a].x;
        int y = location[a].y;
        test[x][y] = 1;

        int stat = map[location[a].x][location[a].y];
        for (int b = 0; b < cctv[stat].size(); ++b) {
            int nx = x;
            int ny = y;
            int index = (cctv[stat][b] + path[a]) % 4;
            while (1) {
                nx = nx + mov[index].x;
                ny = ny + mov[index].y;
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
                if (map[nx][ny] == 6) break;
                test[nx][ny] = 1;
            }
        }
    }
    int cnt = 0;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            if (test[a][b] == 0 && map[a][b] != 6)
                ++cnt;
        }
    }
    mini = min(mini, cnt);
        
}
void dfs(int deep) {
    if (deep == location.size()) {
        simul();
        return;
    }

    for (int a = 0; a < 4; ++a) {
        path[deep] = a;
        dfs(deep + 1);
    }
}
void init() {
    cctv[0].push_back(1);
    cctv[1].push_back(1);
    cctv[1].push_back(3);
    cctv[2].push_back(0);
    cctv[2].push_back(1);
    cctv[3].push_back(0);
    cctv[3].push_back(1);
    cctv[3].push_back(2);
    cctv[4].push_back(0);
    cctv[4].push_back(1);
    cctv[4].push_back(2);
    cctv[4].push_back(3);
}

void solve() {
    if (location.size() != 0) {
        for (int a = 0; a < 4; ++a) {
            path[0] = a;
            dfs(1);
        }
    }
    else {
        mini = 0;
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < M; ++b) {
                if (map[a][b] == 0)
                    ++mini;
            }
        }
    }
    cout << mini;
}
void input() {
    init();
    cin >> N >> M;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            cin >> map[a][b];
            if (map[a][b] >= 1 && map[a][b] < 6) {
                map[a][b]--;
                location.push_back({ a,b });
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    solve();
    return 0;
}
