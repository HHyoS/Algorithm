#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Node {
    int x;
    int y;
};
int N,M,H, W;
int map[1001][1001];
bool visited[1001][1001];
Node mov[4];
int mv[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
Node start;
Node target;

bool check(int x, int y, int arrow) {
    if (visited[x + mv[arrow][0]][y + mv[arrow][1]] == 1) return 0;
    int startX = x + mov[arrow].x; 
    int startY = y + mov[arrow].y;
    if (arrow == 0 || arrow == 2) {
        for (int a = 0; a < W; ++a) {
            int nx = startX;
            int ny = startY + a;
            if (nx<= 0 || nx > N || ny <= 0 || ny > M) return 0;
            if (map[nx][ny] == 1) return 0;
        }
    }
    else {
        for (int a = 0; a < H; ++a) {
            int nx = startX + a;
            int ny = startY;
            if (nx <= 0 || nx > N || ny <= 0 || ny > M) return 0;
            if (map[nx][ny] == 1) return 0;
        }
    }

    return 1;
}
int solve() {

    queue<Node> que;
    que.push({ start.x,start.y });
    int time = 1;
    while (!que.empty()) {

        int size = que.size();
        for (int s = 0; s < size; ++s) {
            Node now = que.front();
            que.pop();
            for (int a = 0; a < 4; ++a) {

                if (check(now.x, now.y, a) == 0) continue;
                int x = now.x + mv[a][0];
                int y = now.y + mv[a][1];
                if (target.x == x && target.y == y) return time;
                visited[x][y] = 1;
                que.push({ x,y });

            }
        }
        ++time;
    }

    return -1;
}
void input() {
    cin >> N >> M;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= M; ++b) {
            cin >> map[a][b];
        }
    }
    cin >> H >> W >> start.x >> start.y >> target.x >> target.y;
    mov[0] = {-1,0};
    mov[1] = { 0,W };
    mov[2] = { H,0 };
    mov[3] = { 0,-1 };
    visited[start.x][start.y] = 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    clock_t start, finish;
    double duration;
    freopen("input.txt", "r", stdin);
    start = clock();
    input();
    cout << solve() << "\n";
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
    return 0;
}
