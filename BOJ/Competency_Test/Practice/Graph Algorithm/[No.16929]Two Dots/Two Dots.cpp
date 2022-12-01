#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int N, M;
char map[50][50];
bool check[50][50];
int mov[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
int ck = 0;
void dfs(int x, int y, int t_x, int t_y, int leng) {
    if ((x == t_x) && (y == t_y)) {
        if (leng < 4)
            return;
        ck = 1;
        return;
    }
    else {
        for (int a = 0; a < 4; ++a) {
            int xx = x + mov[a][0];
            int yy = y + mov[a][1];

            if ((xx >= 0) && (xx < N) && (yy >= 0) && (yy < M) && (map[xx][yy] == map[x][y]) && (!check[xx][yy])) {
                check[xx][yy] = 1;
                dfs(xx, yy, t_x, t_y, leng + 1);
                if (ck)
                    return;
                check[xx][yy] = 0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("Input.txt","r", stdin);

    cin >> N >> M;
    char temp[51];
    for (int a = 0; a < N; ++a) {
        cin >> temp;
        for (int b = 0; temp[b]; ++b) {
            map[a][b] = temp[b];
        }
    }
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            for (int c = 0; c < 4; ++c) {
                int x = a + mov[c][0];
                int y = b + mov[c][1];
                if ((x >= 0) && (x < N) && (y >= 0) && (y < M) && (map[x][y] == map[a][b])) {
                    check[x][y] = 1;
                    dfs(x, y, a, b, 1);
                    if (ck) {
                        a = N;
                        b = M;
                        break;
                    }
                    check[x][y] = 0;
                }
            }
        }
    }
    if (ck)
        cout << "Yes";
    else
        cout << "No";
    return 0;

}
