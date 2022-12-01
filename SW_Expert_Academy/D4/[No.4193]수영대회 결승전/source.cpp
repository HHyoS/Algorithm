                                       #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
 
int T;
int map[16][16];
int used[16][16];
int sX, sY;
int tX, tY;
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int N;
struct Node {
    int x;
    int y;
};
int bfs() {
    queue<Node> que;
    que.push({ sX,sY });
 
    int time = 1;
    while (!que.empty()) {
        int size = que.size();
 
        for (int s = 0; s < size; ++s) {
            int x = que.front().x;
            int y = que.front().y;
            que.pop();
 
            if (used[x][y] + 2 >= time) {
                que.push({ x,y });
            }
            for (int a = 0; a < 4; ++a) {
                int nx = x + mov[a][0];
                int ny = y + mov[a][1];
 
                if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
                if (used[nx][ny]) continue;
                if (nx == tX && ny == tY) {
                    return time;
                }
                if (map[nx][ny] == 1) continue;
                if (map[nx][ny] == 2) {
                    if (time % 3 == 0) {
                        used[nx][ny] = time;
                        que.push({ nx,ny });
                    }
                }
                if (map[nx][ny] == 0) {
                    used[nx][ny] = time;
                    que.push({ nx,ny });
                }
            }
        }
        ++time;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("input.txt", "r", stdin);
 
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < N; ++b) {
                cin >> map[a][b];
            }
        }
        cin >> sX >> sY >> tX >> tY;
        cout << "#"<<t<<" "<<bfs() << "\n";
        memset(used, 0, sizeof(used));
    }
    return 0;
 
}
