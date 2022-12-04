#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define WHITE 0
#define RED 1
#define BLUE 2

struct Node {
    int x;
    int y;
    int idx;
    int arrow;
};
struct Mal {
    int bottom;
    int top;
    int cnt;
};
bool operator<(Node a, Node b) {
    return a.idx < b.idx;
}
int chese[13][13];
Mal map[13][13];
int mov[5][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int N, K;
priority_queue<Node> que;


int check(int x, int y) {
    if (x <= 0 || x > N || y <= 0 || y > N || chese[x][y] == BLUE) {
        return BLUE;
    }
    return chese[x][y];
}
int bfs() {
    int cnt = 0;
    while (cnt < 1000) {
        int size = que.size();

        for (int s = 0; s < size; ++s) {
            Node temp = que.top();
            int arrow = temp.arrow;
            que.pop();

            int nextX = temp.x + mov[arrow][0];
            int nextY = temp.y + mov[arrow][1];

            if (check(nextX, nextY) == WHITE) {
                Mal now = map[temp.x][temp.y];
                if (map[nextX][nextY].cnt == 0) {
                    map[nextX][nextY] = now;
                    que.push({nextX,nextY,now.bottom,now.cnt,arrow})
                }
                else {

                }
            }
            else if (check(nextX, nextY) == RED) {
                Mal now = map[temp.x][temp.y];

            }
            else {
                
            }
            map[now.x][now.y] = { 0,0,0 };

        }
        ++cnt;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   // freopen("input.txt", "r", stdin);
    cin >> N >> K;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            cin >> chese[a][b];
        }
    }
    for (int a = 1; a <= K; ++a) {
        int x, y, arrow;
        cin >> x >> y >> arrow;
        map[x][y] = { a,a,1 };
        que.push({ x,y,a,arrow });
    }

    bfs();
    return 0;

}
