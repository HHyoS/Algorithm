#include <iostream>
#include <vector>
#include <queue>

using namespace std;
char map[51][51];
bool check[51][51]; 

int main(void) {
  // freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    int ar[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    queue<pair<int, int>> S;
    pair<int, int> D;
    queue<pair<int, int>> water;
    int count = 0;

    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= m; ++b) {
            scanf(" %c", &map[a][b]);
            if (map[a][b] == 'D') {
                D = { a,b };
            }
            else if (map[a][b] == 'S') {
                check[a][b] = 1;
                S.push({ a,b });
            }
            else if (map[a][b] == '*') {
                check[a][b] = 1;
                water.push({ a,b });
            }
        }
    }
    if (D == S.front())
        printf("%d",count);

    while (!S.empty()) {
        ++count;
        int size = water.size();
        for (int a = 0; a < size; ++a) {
            pair<int, int> w = water.front();
            water.pop();
            for (int b = 0; b < 4; ++b) {
                int x = w.first + ar[b][0];
                int y = w.second + ar[b][1];
                if (x >= 1 && x <= n &&y >= 1 && y <= m) {
                    if (map[x][y] == '.') {
                        check[x][y] = 1;
                        map[x][y] = '*';
                        water.push({ x,y });
                    }
                }
            }
        }
        int ssize = S.size();
        for (int a = 0; a < ssize; ++a) {
            pair<int, int> g = S.front();
            S.pop();
            for (int b = 0; b < 4; ++b) {
                int x = g.first + ar[b][0];
                int y = g.second + ar[b][1];
                if (x >= 1 && x <= n && y >= 1 && y <= m && !check[x][y]) {
                    if (map[x][y] == 'D') {
                        printf("%d", count);
                        return 0;
                    }
                    else if (map[x][y] == '.') {
                        check[x][y] = 1;
                        S.push({ x,y });
                    }
                }
            }
        }
    }
    printf("KAKTUS");
    return 0;

}


