#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int x;
    int y;
};
Node bumarang[4][3] = { {{0,0},{0,1},{1,1}},{{0,0},{0,1},{-1,1}},{{0,0},{1,0},{1,1}}, {{1,0},{0,0},{0,1} } };
int N, M;
int map[6][6];
int memo[6][6][4];
int maxi = 0;
bool used[6][6];

void paint(int x, int y, int type, int value) {
    int sum = 0;
    for (int a = 0; a < 3; ++a) {
        int nx = x + bumarang[type][a].x;
        int ny = y + bumarang[type][a].y;
        used[nx][ny] = value;
    }
}
bool isOk(int x, int y, int type) {
    for (int a = 0; a < 3; ++a) {
        int nx = x + bumarang[type][a].x;
        int ny = y + bumarang[type][a].y;
        if (nx >= N || nx < 0 || ny >= M || ny < 0) return 0;
        if (used[nx][ny] == 1) return 0;
    }
    return 1;
}
void run(int x, int y,int sum) {
    ++y;
    if (y >= M) {
        y = 0;
        ++x;
        if (x >= N) {
            if (sum > maxi)
                maxi = sum;
            return;
        }
    }

    run(x, y, sum);
    
    for (int a = 0; a < 4; ++a) {
        if (isOk(x, y, a)) {
            paint(x, y, a, 1);
            run(x, y, sum + memo[x][y][a]);
            paint(x, y, a, 0);
        }
    }
}

void init() {
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            for (int c = 0; c < 4; ++c) {
                if (isOk(a, b, c)) {
                    int sum = 0;
                    for (int d = 0; d < 3; ++d) {
                        int nx = a + bumarang[c][d].x;
                        int ny = b + bumarang[c][d].y;
                        if (d == 1) {
                            sum = sum + (map[nx][ny] << 1);
                        }
                        else {
                            sum += map[nx][ny];
                        }
                    }
                    memo[a][b][c] = sum;
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

    cin >> N >> M;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            cin >> map[a][b];
        }
    }

    init();
    if (N < 2 || M < 2)
        cout << 0;
    else {
        run(0, -1, 0);
        cout << maxi;
    }
   
    return 0;

}
