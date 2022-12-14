#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;


struct Boom {
    int x;
    int y;
    int time;
};
struct Node {
    int x;
    int y;
};
bool operator<(Boom a, Boom b) {
    if (a.time == b.time) {
        if (a.x == b.x) {
            return a.y > b.y;
        }
        return a.x > b.x;
    }
    return a.time > b.time;
}

int R, C, N;
char map[202][202];
priority_queue<Boom> que;
int distroy[202][202];
queue<Node> wait;
int mov[5][2] = { {0,0}, {-1,0},{0,1},{1,0},{0,-1} };

void print() {
    for (int a = 0; a < R; ++a) {
        for (int b = 0; b < C; ++b) {
            cout << map[a][b];
        }
        cout << "\n";
    }
    cout << "\n";
}
void run() {


    for (int time = 2; time <= N; ++time) {
        if (time % 2 == 0) {
            while (!wait.empty()) {
                Node now = wait.front();
                wait.pop();
                map[now.x][now.y] = 'O';
                distroy[now.x][now.y] = time + 3;
                que.push({ now.x,now.y,time });
            }
        }
        else {
            while (que.top().time == time - 3) {
                Boom nowBoom = que.top();
                que.pop();
                if (distroy[nowBoom.x][nowBoom.y] != time) continue;
                for (int a = 0; a < 5; ++a) {
                    int x = nowBoom.x + mov[a][0];
                    int y = nowBoom.y + mov[a][1];

                    if (x >= R || x < 0 || y >= C || y < 0) continue;
                    if (map[x][y] == 'O') {
                        map[x][y] = '.';
                        wait.push({ x,y });
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    cin >> R >> C >> N;
    for (int a = 0; a < R; ++a) {
        for (int b = 0; b < C; ++b) {
            cin >> map[a][b];
            if (map[a][b] == 'O') {
                que.push({ a,b,0 });
                distroy[a][b] = 3;
            }
            else {
                if (N % 2 == 0)
                    map[a][b] = 'O';
                else {
                    wait.push({ a,b });
                }
            }
        }
    }

    if (N == 1 || (N%2 == 0))
        print();
    else {
        if (N % 4 == 1) {
            N = 5;
        }
        else if (N % 4 == 3) {
            N = 3;
        }
        run();
        print();
    }
    return 0;

}
