#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;


int T, N;
int x, y;
int mov[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int dalpang[11][11];
int nowNumber;
bool right() {
    int check = 0;
    int nx = x, ny = y;
    for (int a = 0; a <= N; ++a) {
        nx = nx +mov[0][0];
        ny = ny +mov[0][1];
        if (ny >= N || dalpang[nx][ny] != 0) break;
        dalpang[nx][ny] = nowNumber++;
        if (check == 0)
            check = 1;
    }
    x = nx -mov[0][0];
    y=  ny -mov[0][1];
    if (check == 1)
        return 0;
    else
        return 1;
}
bool down() {
    int check = 0;
    int nx = x, ny = y;
    for (int a = 0; a <= N; ++a) {
        nx = nx + mov[1][0];
        ny = ny + mov[1][1];
        if (nx >= N || dalpang[nx][ny] != 0) break;
        dalpang[nx][ny] = nowNumber++;
        if (check == 0)
            check = 1;
    }
    x = nx - mov[1][0];
    y = ny - mov[1][1];
    if (check == 1)
        return 0;
    else
        return 1;
}
bool left() {
    int check = 0;
    int nx = x, ny = y;
    for (int a = 0; a <= N; ++a) {
        nx = nx +mov[2][0];
        ny = ny+ mov[2][1];
        if (ny < 0 || dalpang[nx][ny] != 0) break;
        dalpang[nx][ny] = nowNumber++;
        if (check == 0)
            check = 1;
    }
    x = nx - mov[2][0];
    y = ny - mov[2][1];
    if (check == 1)
        return 0;
    else
        return 1;
}
bool up() {
    int check = 0;
    int nx = x, ny = y;
    for (int a = 0; a <= N; ++a) {
        nx = nx +mov[3][0];
        ny = ny + mov[3][1];
        if (nx < 0 || dalpang[nx][ny] != 0) break;
        dalpang[nx][ny] = nowNumber++;
        if (check == 0)
            check = 1;
    }
    x = nx - mov[3][0];
    y = ny - mov[3][1];
    if (check == 1)
        return 0;
    else
        return 1;
}
void solve() {
    x = 0;
    y = -1;
    nowNumber = 1;
    while (1) {
        if (right()) {
            break;
        }
        if (down()) {
            break;
        }
        if (left())
            break;
        if (up())
            break;
    }
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            cout << dalpang[a][b] << " ";
        }
        cout << "\n";
    }
}
void input() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        cout << "#"<<t<<"\n";
        solve();
        memset(dalpang, 0, sizeof(dalpang));
    }
 }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  //  freopen("input.txt", "r", stdin);

    input();
    return 0;
}
