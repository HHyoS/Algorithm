#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
struct Node {
    int x;
    int y;
};
int N, M;
int map[101][101];
int windCnt[101][101];
int iceCnt;
queue<Node> que; // 임시 큐
queue<Node> out; // 얼음 근처의 벽돌
int visited[101][101];
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };



void init() {
    que.push({ 0,0 });
    visited[0][0] = 1;
    while (!que.empty()) {

        Node now = que.front();
        que.pop();

        for (int a = 0; a < 4; ++a) {
            int x = now.x + mov[a][0];
            int y = now.y + mov[a][1];

            if (x < 0 || x >= N || y < 0 || y >= M) continue;
            if (visited[x][y] != 0) continue;
            if (map[x][y] == 2) continue;

            if (map[x][y] == 1) {
                if (map[now.x][now.y] == 0) {
                    map[now.x][now.y] = 2;
                    out.push({ now.x,now.y });
                }
            }
            else {
                que.push({ x,y });
                visited[x][y] = 1;
            }
            
        }
    }
}

void bfs(int x, int y) {
    que.push({ x,y });
    out.push({ x,y });
    map[x][y] = 2;

    while (!que.empty()) {
        Node now = que.front();
        que.pop();

        for (int a = 0; a < 4; ++a) {
            int nx = now.x + mov[a][0];
            int ny = now.y + mov[a][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (map[nx][ny] != 0) continue;

            que.push({ nx,ny });
            out.push({ nx,ny });
            map[nx][ny] = 2;
        }
    }

}

int solve() {
    int time = 0;
    while (iceCnt != 0) {
        int size = out.size();

        for (int s = 0; s < size; ++s) {
            Node now = out.front();
            out.pop();

            int flag = 0;
            for (int a = 0; a < 4; ++a) {
                int x = now.x + mov[a][0];
                int y = now.y + mov[a][1];

                if (x < 0 || x >= N || y < 0 || y >= M) continue;
                if (map[x][y] != 1) continue;
                
                flag = 1;
                windCnt[x][y]++;
                if (windCnt[x][y] == 2) {
                    --iceCnt;
                    bfs(x, y);
                }
            }
            if (flag != 0) {
                out.push(now);
            }
        }
        memset(windCnt, 0, sizeof(windCnt));
        ++time;
    }
    return time;
}

void input() {
    cin >> N >> M;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            cin >> map[a][b];
            if (map[a][b] == 1) {
                ++iceCnt;
            }
        }
    }
    init();
}

int main(int argc, char** argv)
{
	input();
    cout << solve();
	return 0;
}
