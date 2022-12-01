#include <cstdio>
#include <queue>
using namespace std;
bool arr[1000][1000];
int n, m;
int big = -1;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int ct = -1;
int check = 0;
queue<int> que;

int main() {
      // freopen("Input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int input;
    for (int a = 0; a < m; ++a) {
        for (int b = 0; b < n; ++b) {
            scanf("%d", &input);
            if (input == 1) {
                arr[a][b] = 1;
                que.push(10000 * a + b);
            }
            else if (input == -1)
                arr[a][b] = 1;
            else {
                ++check;
            }
        }
    }
    while (!que.empty()) {
        int size = que.size();
        for (int a = 0; a < size; ++a) {
            int x = que.front() / 10000;
            int y = que.front() % 10000;
            que.pop();
            for (int b = 0; b < 4; ++b) {
                if ((x + dir[b][0] >= 0) && (x + dir[b][0] < m) && (y + dir[b][1] >= 0) && (y + dir[b][1] < n)) {
                    if (arr[x + dir[b][0]][y + dir[b][1]] == 0) {
                        --check;
                        arr[x + dir[b][0]][y + dir[b][1]] = 1;
                        que.push(10000 * (x + dir[b][0]) + y + dir[b][1]);
                    }
                }
            }
        }
        ++ct;
    }

    if (check == 0)
        printf("%d", ct);
    else
        printf("-1");
    return 0;
}
