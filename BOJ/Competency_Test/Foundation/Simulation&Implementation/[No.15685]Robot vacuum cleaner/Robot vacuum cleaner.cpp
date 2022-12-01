#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int N, M;
bool map[50][50];
bool check[50][50];
int mov[4][2] = { {0,-1}, {-1,0},{0,1},{1,0} };
int bak[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };

bool able(int x, int y) {
    if ((x >= 0) && (x < N) && (y >= 0) && (y < M) && !map[x][y])
        return 1;
    else
        return 0;
}
void dfs(int x, int y, int head, int answer) {
    if (!check[x][y]) {
        check[x][y] = 1;
        ++answer;
    }                         
    for (int a = 4; a > 0; --a) {
        int xx = x+mov[(head + a) % 4][0];
        int yy = y+mov[(head + a) % 4][1];
        if (able(xx,yy))
            if (!check[xx][yy]) {
                dfs(xx, yy, (head + a+3) % 4, answer);
                return;
            }
    }

    if (able(x + bak[head][0], y + bak[head][1])) {
        dfs(x + bak[head][0], y + bak[head][1], head, answer);
    }
    else {
        cout << answer;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("Input.txt","r", stdin);
    cin >> N >> M;

    int x, y, head;
    cin >> x >> y >> head;
    
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            cin >> map[a][b];
        }
    }

    dfs(x, y, head,0);
    return 0;

}
