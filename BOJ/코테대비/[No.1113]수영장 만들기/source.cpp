#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;


struct Node {
    int x;
    int y;
};


int N, M;
int map[52][52];
int maxiHight = -1;
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void bfs(int hight) {
    queue<Node> que;

    que.push({ 0,0 });
    map[0][0] = hight;

    while (!que.empty()) {
        Node now = que.front();
        que.pop();

        for (int a = 0; a < 4; ++a) {
            int x = now.x +mov[a][0];
            int y = now.y + mov[a][1];

            if (x < 0 || x > N+1 || y < 0 || y > M+1) continue;
            if (map[x][y] >= hight) continue;

            map[x][y] = hight;
            que.push({ x,y });
        }
    }
}

void solve() {

    int cnt = 0;
    for (int a = 2; a <= maxiHight; ++a) {
        bfs(a);

        for (int b = 1; b <= N; ++b) {
            for (int c = 1; c <= M; ++c) {
                if (map[b][c] < a) {
                    ++cnt;
                }
            }
        }
    }

    cout << cnt;
}
void input() {
    cin >> N >> M;
    for (int a = 1; a <= N; ++a) {
        string temp;
        cin >> temp;
        for (int b = 1; b <= M; ++b) {
            map[a][b] = temp[b - 1] - '0';
            maxiHight = max(maxiHight, map[a][b]);
        }
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
