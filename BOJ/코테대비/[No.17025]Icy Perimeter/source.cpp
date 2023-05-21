#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

struct Node {
    int x;
    int y;
};

char map[1010][1010];
bool visited[1010][1010];
int N;
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int answerCnt =  -1;
int answerLeng= -1;
void bfs(int x, int y) {
    queue<Node> que;
    
    que.push({ x,y });
    int cnt = 1;
    int leng = 0;
    while (!que.empty()) {
        Node now = que.front();
        que.pop();

        for (int a = 0; a < 4; ++a) {
            int nx = now.x + mov[a][0];
            int ny = now.y + mov[a][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || map[nx][ny] == '.') {
                ++leng;
                continue;
            }
            if (visited[nx][ny])continue;
            
            que.push({ nx,ny });
            visited[nx][ny] = 1;
            ++cnt;
        }
    }
    if (cnt > answerCnt) {
        answerCnt = cnt;
        answerLeng = leng;
    }
    else if (cnt == answerCnt) {
        answerLeng = min(answerLeng, leng);
    }
}
void solve() {
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            if (map[a][b] == '#' && visited[a][b] == 0) {
                visited[a][b] = 1;
                bfs(a, b);
            }
        }
    }
    cout << answerCnt << " " << answerLeng;
}
void input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            cin >> map[a][b];
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
