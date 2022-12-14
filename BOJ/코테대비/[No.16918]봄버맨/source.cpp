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
        cout << "[" << time << "]\n";
        if (time % 2 == 0) {
            while (!wait.empty()) {
                Node now = wait.front();
                wait.pop();
                map[now.x][now.y] = 'O';
                que.push({ now.x,now.y,time});
            }
        }
        else {
            cout << que.top().time << "\n";
            while (que.top().time == time - 3) {
                Boom nowBoom = que.top();
                que.pop();
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
        print();
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
                que.push({a,b,0});
            }
            else {
                wait.push({ a,b });
            }
        }
    }
    run();

    return 0;

}
