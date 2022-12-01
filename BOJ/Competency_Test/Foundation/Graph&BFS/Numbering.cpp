#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;
int arr[26][26];
int n;
int dange = 0;
int dangesu[625];
int dir[4][2]= { {1,0},{0,1},{-1,0},{0,-1} };
void dfs(int x,int y) {
    ++dangesu[dange];
    arr[x][y] = '0';

    for (int a = 0; a < 4; ++a) {
        int dx = x + dir[a][0];
        int dy = y + dir[a][1];
        if (dx >= 1 && dx <= n && dy >= 1 && dy <= n && arr[dx][dy] == 1)
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
 //   freopen("Input.txt", "r", stdin);
    scanf("%d", &n);
    for (int b = n; b > 0; --b) {
        for (int a = 1; a <= n ; ++a) {
            scanf("%1d", &arr[a][b]);
        }
    }

    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            if (arr[a][b] == 1) {
                dfs(a, b);
                ++dange;
            }
        }
    }
    sort(dangesu, dangesu + dange);
    printf("%d\n", dange);
    for (int a = 0; a < dange; ++a) {
        printf("%d\n", dangesu[a]);
    }
    return 0;
}
