#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;
int arr[51][51];
int n,m;
int dange = 0;
int dir[8][2] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1,},{-1,1} };
void dfs(int x,int y) {
    arr[x][y] = 0;

    for (int a = 0; a < 8; ++a) {
        int dx = x + dir[a][0];
        int dy = y + dir[a][1];
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && arr[dx][dy] == 1)
            dfs(dx, dy);
    }
 /*   if (x > 1) {
        if (arr[x - 1][y] ==1)
            dfs(x - 1,y);
    }
    if (x < n) {
        if (arr[x + 1][y] == 1)
            dfs(x + 1, y);
    }
    if (y > 1) {
        if (arr[x][y - 1] == 1)
            dfs(x, y - 1);
    }
    if (y < n) {
        if (arr[x][y + 1] == 1)
            dfs(x, y + 1);
    }*/
}

int main() {
//    freopen("Input.txt", "r", stdin);
    while (true) {
        dange = 0;
        scanf("%d%d", &n,&m);
        if ((n == 0) && (m == 0)) {
            return 0;
        }
        for (int b = m; b > 0; --b) {
            for (int a = 1; a <= n; ++a) {
                scanf("%d", &arr[a][b]);
            }
        }

        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= m; ++b) {
                if (arr[a][b] == 1) {
                    dfs(a, b);
                    ++dange;
                }
            }
        }
        printf("%d\n", dange);
    }
    return 0;
}
