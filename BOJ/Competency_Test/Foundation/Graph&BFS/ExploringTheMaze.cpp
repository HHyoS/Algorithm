#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
bool arr[100][100];
int n, m;
int xx, yy;
int big = -1;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1}};
void dfs(queue<pair<int,int>> que,int count) {
    int size = que.size();
    for (int a = 0; a < size; ++a) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int b = 0; b < 4; ++b) {
            int dx = x + dir[b][0];
            int dy = y + dir[b][1];
            if (dx >= 0 && dx < n && dy >= 0 && dy < m && arr[dx][dy]) {
                if (dx == xx && dy == yy) {
                    big = count;
                    return;
                }
                arr[dx][dy] = 0;
                que.push({ dx,dy });
            }
        }
    }
    if (!que.empty())
        dfs(que, count + 1);
}

int main() {
    //   freopen("Input.txt", "r", stdin);
        scanf("%d%d", &n, &m);
        xx = n - 1;
        yy = m - 1;
        for (int a = 0; a < n  ; ++a) {
            for (int b = 0; b < m; ++b) {
                scanf("%1d", &arr[a][b]);
            }
        }
        queue<pair<int,int>> que;
        que.push({ 0,0 });
        arr[0][0] = 0;
        dfs(que, 2);
        printf("%d", big);
    return 0;
}
