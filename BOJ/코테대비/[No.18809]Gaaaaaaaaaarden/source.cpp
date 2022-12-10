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

struct Flower {
    int x;
    int y;
    int state;
};

struct Garden {
    int state;
    int time;
};
int N, M, G, R;
int map[51][51];
Garden garden[51][51];
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool visited[11];
vector<Node> hwangto;
vector<Node> red;
vector<Node> green;
int maxi = -1;
int tot = 0;
void choice(int rCounter, int gCounter,int index) {
    if (rCounter > 0) {
        for (int a = index + 1; a < hwangto.size(); ++a) {
            visited[a] = 1;
            red.push_back(hwangto[a]);
            if (rCounter == 1) {
                choice(rCounter - 1, gCounter, -1);
            }
            else {
                choice(rCounter - 1, gCounter, a);
            }
            red.pop_back();
            visited[a] = 0;
        }
    }
    else if(gCounter > 0){
        for (int a = index + 1; a < hwangto.size(); ++a) {
            if (visited[a] == 0) {
                visited[a] = 1;
                green.push_back(hwangto[a]);
                choice(rCounter, gCounter - 1, a);
                green.pop_back();
                visited[a] = 0;
            }
        }
    }
    else {
        memset(garden, 0, sizeof(garden));

        queue<Flower> que;
        int paint = 0;
        for (int a = 0; a < green.size(); ++a) {
            garden[green[a].x][green[a].y].time = 1;
            garden[green[a].x][green[a].y].state = 1;
            que.push({ green[a].x,green[a].y,1 });
            ++paint;
        }
        for (int a = 0; a < red.size(); ++a) {
            garden[red[a].x][red[a].y].time = 1;
            garden[red[a].x][red[a].y].state = 2;
            que.push({ red[a].x, red[a].y,2 });
            ++paint;
        }
        int time = 2;
        int cnt = 0;
        while (!que.empty()) {

            int size = que.size();
            if (tot - paint + cnt <= maxi)
                return;
            for (int s = 0; s < size; ++s) {
                Flower now = que.front();
                que.pop();

                if (garden[now.x][now.y].state == -1)
                    continue;
                for (int a = 0; a < 4; ++a) {
                    int x = now.x + mov[a][0];
                    int y = now.y + mov[a][1];

                    if (x >= N || x < 0 || y >= M || y < 0) continue;
                    if (garden[x][y].time != 0 && garden[x][y].time < time) continue;
                    if (garden[x][y].state == now.state) continue;
                    if (garden[x][y].state == -1) continue;
                    if (map[x][y] == 0)continue;

                    if (garden[x][y].time == 0) {
                        ++paint;
                        garden[x][y].time = time;
                        garden[x][y].state = now.state;
                        que.push({ x,y,now.state });
                    }
                    else {
                        garden[x][y].state = -1;
                        ++cnt;
                    }
                }
            }
            ++time;
        }

        if (maxi < cnt) {
            maxi = cnt;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    
    cin >> N >> M >> G >> R;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            cin >> map[a][b];
            if (map[a][b] == 2) {
                hwangto.push_back({ a,b });
            }
            if (map[a][b] != 0) {
                tot++;
            }
        }
    }
    choice(R, G,-1);
    cout << maxi;
    return 0;

}
