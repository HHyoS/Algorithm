#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Game {
    int x;
    int y;
    int idx;
};

struct Infomation {
    int bottom;
    int top;
    int cnt;
};
bool operator<(Game a, Game b) {
    return a.idx > b.idx;
}
int map[13][13];
Infomation chess[13][13];
int arrowMemo[11];
priority_queue<Game> info;
int mov[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
int N, K;


bool isBlue(int nx, int ny) {
    if (nx > N || nx <=0 || ny > N || ny <= 0 || map[nx][ny] == 2) {
        return 1;
    }
    return 0;
}
bool isRed(int nx, int ny) {
    if (map[nx][ny] == 1)
        return 1;
    return 0;
}

bool isWhite(int nx, int ny) {
    if (map[nx][ny] == 0)
        return 1;
    return 0;
}

void print() {
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            cout << "(" << chess[a][b].bottom << "," << chess[a][b].top << ","<<chess[a][b].cnt << ") ";
        }
        cout << "\n";
    }
    cout << "\n";
}
int run() {

    int time = 1;

    while (time <= 1000) {
        int blueCnt = 0;
        vector<Game> temp;
        while (!info.empty()) {
            Game now = info.top();
            int count = chess[now.x][now.y].cnt;
            info.pop();
            
            int arrow = arrowMemo[now.idx];
            int nx = now.x + mov[arrow][0];
            int ny = now.y + mov[arrow][1];


            if (isBlue(nx,ny)) {
                switch (arrow) {
                case 1 :
                    arrowMemo[now.idx] = 2;
                    break;
                case 2:
                    arrowMemo[now.idx] = 1;
                    break;
                case 3 :
                    arrowMemo[now.idx] = 4;
                    break;
                case 4:
                    arrowMemo[now.idx] = 3;
                    break;
                }
                arrow = arrowMemo[now.idx];
                nx = now.x + mov[arrow][0];
                ny = now.y + mov[arrow][1];
            }

            if (isBlue(nx, ny)) {
                ++blueCnt;
                temp.push_back({ now.x,now.y,chess[now.x][now.y].bottom });
            }
            else if(isRed(nx, ny)) {
                if (chess[nx][ny].cnt == 0) {
                    chess[nx][ny] = { chess[now.x][now.y].top,chess[now.x][now.y].bottom,count };
                    if (chess[nx][ny].bottom > chess[nx][ny].top) {
                        info.push({ nx,ny,chess[nx][ny].bottom });
                    }
                    else {
                        temp.push_back({ nx,ny,chess[nx][ny].bottom });
                    }
                }
                else {
                    chess[nx][ny] = { chess[nx][ny].bottom,chess[now.x][now.y].bottom,chess[nx][ny].cnt + count };
                }
                chess[now.x][now.y] = { 0,0,0 };
            }
            else if (isWhite(nx, ny)) {
                if (chess[nx][ny].cnt == 0) {
                    chess[nx][ny] = chess[now.x][now.y];
                    temp.push_back({ nx,ny,chess[nx][ny].bottom });
                }
                else {
                    chess[nx][ny] = { chess[nx][ny].bottom,chess[now.x][now.y].top,chess[nx][ny].cnt + count };
                }
                chess[now.x][now.y] = { 0,0,0 };
            }
            if (chess[nx][ny].cnt >= 4) {
                return time;
            }
        }
        if (temp.size() == blueCnt)
            return -1;
        for (int a = 0; a < temp.size(); ++a) {
            info.push({ temp[a].x,temp[a].y,temp[a].idx });
        }
        print();
        ++time;
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    cin >> N >> K;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            cin >> map[a][b];
        }
    }
    for (int a = 1; a <= K; ++a) {
        int x, y, arrow;
        cin >> x >> y >> arrow;
        info.push({x,y,a});
        chess[x][y] = { a,a,1 };
        arrowMemo[a] = arrow;
    }
    print();
    cout << run();

    return 0;

}
