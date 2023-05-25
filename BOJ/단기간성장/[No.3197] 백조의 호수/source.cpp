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
    int cnt;
};

bool operator<(Node a, Node b){
    if (a.cnt == b.cnt) {
        if (a.x == b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
    return a.cnt > b.cnt;
}
int N, M;
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
char map[1501][1501];
priority_queue<Node> leftGoose;
priority_queue<Node> water;
bool leftVisit[1501][1501];
bool waterVisit[1501][1501];
int waterCnt[1501][1501];
int leftCnt[1501][1501];
int answerX, answerY;
int mini = 21e8;
void waterBFS() {

    while (!water.empty()) {
        Node now = water.top();
        water.pop();

        for (int a = 0; a < 4; ++a) {
            int x = now.x + mov[a][0];
            int y = now.y + mov[a][1];

            if (x < 0 || x >= N || y < 0 || y >= M) continue;
            if (waterVisit[x][y]) continue;

            if (map[x][y] == 'X') {
                waterVisit[x][y] = 1;
                waterCnt[x][y] = now.cnt + 1;
                water.push({ x,y,now.cnt + 1 });
            }
            else {
                waterVisit[x][y] = 1;
                waterCnt[x][y] = now.cnt;
                water.push({ x,y,now.cnt });
            }
        }
    }
}

void leftGooseBFS() {

    while (!leftGoose.empty()) {
        Node now = leftGoose.top();
        leftGoose.pop();

        for (int a = 0; a < 4; ++a) {
            int x = now.x + mov[a][0];
            int y = now.y + mov[a][1];

            if (x < 0 || x >= N || y < 0 || y >= M) continue;
            if (leftVisit[x][y]) continue;

            if (waterCnt[x][y] <= now.cnt){
                leftVisit[x][y] = 1;
                leftCnt[x][y] = now.cnt;
                leftGoose.push({ x,y,now.cnt });

                if (answerX == x && answerY == y) {
                    mini = now.cnt;
                    return;
                }
            }
            else {
                leftVisit[x][y] = 1;
                leftCnt[x][y] = waterCnt[x][y];
                leftGoose.push({ x,y,waterCnt[x][y] });
            }
        }
    }
}
void solve() {
    waterBFS();
    leftGooseBFS();
    cout << mini;
}
void input() {
    cin >> N >> M;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            cin >> map[a][b];
            if (map[a][b] == '.' ) {
                waterVisit[a][b] = 1;
                water.push({ a,b,0 });
            }
            else if (map[a][b] == 'L') {
                map[a][b] = '.';
                waterVisit[a][b] = 1;
                water.push({ a,b,0 });
                if (leftGoose.empty()) {
                    leftGoose.push({ a,b,0 });
                    leftVisit[a][b] = 1;
                }
                else {
                    answerX = a;
                    answerY = b;
                }
            }
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
