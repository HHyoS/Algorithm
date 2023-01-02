#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int R, C, K;
string map[6];
int visited[6][6];
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int ans = 0;
int homeX, homeY;
int startX, startY;
void dfs(int x, int y, int deep) {
    if (x == homeX && y == homeY) {
        if(deep == K)
            ++ans;
        return;
    }
    if (deep >= K)
        return;
    
    for (int a = 0; a < 4; ++a) {
        int nx = x + mov[a][0];
        int ny = y + mov[a][1];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C)continue;
        if (map[nx][ny] == 'T' || visited[nx][ny] == 1) continue;
        visited[nx][ny] = 1;
        dfs(nx, ny, deep + 1);
        visited[nx][ny] = 0;
    }
}
void solve() {
    
    visited[startX][startY] = 1;
    for (int a = 0; a < 2; ++a) {
        int x = startX + mov[a][0];
        int y = startY + mov[a][1];
        if (map[x][y] == 'T') continue;
        visited[x][y] = 1;
        dfs(x, y, 2);
        visited[x][y] = 0;
    }

    cout << ans;
}
void input() {
    cin >> R >> C >> K;
    for (int a = 0; a < R; ++a) {
        cin >> map[a];
    }
    homeX = 0;
    homeY = C - 1;
    startX = R-1;
    startY = 0;
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
