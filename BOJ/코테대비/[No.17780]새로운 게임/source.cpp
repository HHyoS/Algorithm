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
    return a.idx > b.idx;
}
int chese[13][13];
Mal map[13][13];
int mov[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
int saveArrow[13];
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
    while (cnt <= 1000) {
        vector<Node> save;
        int totalCnt = 0;
        int blueCnt = 0;
        while(!que.empty()){
            ++totalCnt;
            Node temp = que.top();
            int arrow = temp.arrow;
            Mal now = map[temp.x][temp.y];
            que.pop();
            int nextX = temp.x + mov[arrow][0];
            int nextY = temp.y + mov[arrow][1];
            if (check(nextX, nextY) == BLUE) {
                int nextArrow;
                if (arrow == 1) {
                    nextX = temp.x + mov[2][0];
                    nextY = temp.y + mov[2][1];
                    arrow = 2;
                }
                else if (arrow == 2) {
                    nextX = temp.x + mov[1][0];
                    nextY = temp.y + mov[1][1];
                    arrow = 1;
                }
                else if (arrow == 3) {
                    nextX = temp.x + mov[4][0];
                    nextY = temp.y + mov[4][1];
                    arrow = 4;
                }
                else {
                    nextX = temp.x + mov[3][0];
                    nextY = temp.y + mov[3][1];
                    arrow = 3;
                }
            }
            saveArrow[map[temp.x][temp.y].bottom] = arrow;
            if (check(nextX, nextY) == WHITE) {
                if (map[nextX][nextY].cnt == 0) {
                    map[nextX][nextY] = now;
                    save.push_back({ nextX,nextY,map[nextX][nextY].bottom,arrow });
                }
                else {
                    map[nextX][nextY].top = now.top;
                    map[nextX][nextY].cnt += now.cnt;
                    if (map[nextX][nextY].cnt >= 4)
                        return cnt + 1;
                }
                map[temp.x][temp.y] = { 0,0,0 };

            }
            else if (check(nextX, nextY) == RED) {
                if (map[nextX][nextY].cnt == 0) {
                    map[nextX][nextY] = { now.top,now.bottom,now.cnt };
                    if (now.top > now.bottom) {
                        que.push({ nextX,nextY,map[nextX][nextY].bottom,saveArrow[map[nextX][nextY].bottom] });
                    }
                    else
                        save.push_back({ nextX,nextY,map[nextX][nextY].bottom,saveArrow[map[nextX][nextY].bottom] });
                }
                else {
                    map[nextX][nextY].top = now.bottom;
                    map[nextX][nextY].cnt += now.cnt;
                    if (map[nextX][nextY].cnt >= 4)
                        return cnt + 1;
                }
                map[temp.x][temp.y] = { 0,0,0 };
            }
            else {
                ++blueCnt;
                save.push_back({ temp.x,temp.y,map[temp.x][temp.y].bottom,temp.arrow });
            }
            
        }
        if (totalCnt == blueCnt)
            return -1;
        for (int a = 0; a < save.size(); ++a) {
            que.push(save[a]);
        }
        ++cnt;
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
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
        saveArrow[a] = arrow;
    }
    cout << bfs();
    return 0;

}
