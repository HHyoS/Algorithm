#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;



struct Mal {
    int x;
    int y;
};


vector<int> info[13][13];
int map[13][13];
int arrowMemo[11];
Mal gps[11];
int mov[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
int N, K;


int Find(int x, int y, int idx) {
    for (int a = 0; a < info[x][y].size(); ++a) {
        if (info[x][y][a] == idx)
            return a;
    }
}

bool isBlue(int x, int y) {
    if (x <= 0 || x > N || y > N || y <= 0 || map[x][y] == 2) {
        return 1;
    }
    return 0;
}
bool isRed(int x, int y) {
    if (map[x][y] == 1)
        return 1;
    return 0;
}
bool isWhite(int x, int y) {
    if (map[x][y] == 0)
        return 1;
    return 0;
}


void bokboot(int sourceX, int sourceY, int targetX, int targetY, int index) {
    for (int a = index; a < info[sourceX][sourceY].size(); ++a) {
        int idx = info[sourceX][sourceY][a];
        gps[idx] = { targetX,targetY };
        info[targetX][targetY].push_back(idx);
    }
    info[sourceX][sourceY].erase(info[sourceX][sourceY].begin() + index, info[sourceX][sourceY].end());
}

int run() {
    int time = 1;

    while (time <= 1000) {
        int blueCnt = 0;
        for (int a = 1; a <= K; ++a) {
            int x = gps[a].x;
            int y = gps[a].y;
            int arrow = arrowMemo[a];

            int idx = Find(x, y, a);

            int nx = x + mov[arrow][0];
            int ny = y + mov[arrow][1];

            if (isBlue(nx, ny)) {
                switch (arrow) {
                case 1:
                    arrowMemo[a] = 2;
                    break;
                case 2:
                    arrowMemo[a] = 1;
                    break;
                case 3:
                    arrowMemo[a] = 4;
                    break;
                case 4:
                    arrowMemo[a] = 3;
                    break;
                }
                arrow = arrowMemo[a];
                nx = x + mov[arrow][0];
                ny = y + mov[arrow][1];
            }

            if (isBlue(nx, ny)) {
                continue;
            }
            else if (isRed(nx, ny)) {
                reverse(info[x][y].begin() + idx, info[x][y].end());
                bokboot(x, y, nx, ny, idx);
            }
            else if (isWhite(nx, ny)) {
                bokboot(x, y, nx, ny, idx);
            }
            if (info[nx][ny].size() >= 4)
                return time;

        }
        if (blueCnt == K)
            return -1;
        ++time;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    cin >> N >> K;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            cin >> map[a][b];
        }
    }
    for (int a = 1; a <= K; ++a) {
        int x, y, arrow;
        cin >> x >> y >> arrow;
        info[x][y].push_back(a);
        arrowMemo[a] = arrow;
        gps[a] = { x,y };
    }
    cout << run();

    return 0;

}
