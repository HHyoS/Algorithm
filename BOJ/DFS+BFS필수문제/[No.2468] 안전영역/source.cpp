#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Node {
    int x;
    int y;
};
int N;
int map[101][101];
int mov[4][2] = { {-1,0},{0,1 },{1,0},{0,-1} };
bool visited[101][101];
int mini = 21e8;
int maxi = -1;


void bfs(int x, int y,int deep) {
    queue<Node> que;
    que.push({ x,y });
    visited[x][y] = 1;

    while (!que.empty()) {
        Node now = que.front();
        que.pop();

        for (int a = 0; a < 4; ++a) {
            int nx = now.x + mov[a][0];
            int ny = now.y + mov[a][1];

            if (visited[nx][ny]) continue;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (map[nx][ny] <= deep) continue;

            visited[nx][ny] = 1;
            que.push({ nx,ny });
        }
    }
}
void solve() {
    int safeArea = 1;
    for (int a = mini; a < maxi; ++a) {
        int cnt = 0;
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (visited[x][y] == 0 && map[x][y] > a){
                    ++cnt;
                    bfs(x, y, a);
                }
            }
        }
        safeArea = max(safeArea, cnt);
        memset(visited, 0, sizeof(visited));
    }
    cout << safeArea;
}

void input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            cin >> map[a][b];
            mini = min(mini, map[a][b]);
            maxi = max(maxi, map[a][b]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    return 0;
}
