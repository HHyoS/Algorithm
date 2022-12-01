#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool map[1001][1001];
bool check[1001][1001][2];

int main(void) {
    int n, m;
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);

    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= m; ++b) {
            scanf("%1d", &map[a][b]);
        }
    }
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> que;


    que.push({ { 1,1 }, { 1,1 } });
    check[1][1][0] = 1;


    int mini = -1;
    while (!que.empty()) {

        int count = que.top().first.first;
        int able = que.top().first.second;
        int x = que.top().second.first;
        int y = que.top().second.second;

        que.pop();

        if (x == n && y == m) {
            if (mini == -1 || mini > count) {
                printf("%d", count);
                return 0;
            }
        }
        ++count;
        if (x < n && !check[x + 1][y][able]) {
            if (!map[x + 1][y]) {
                check[x + 1][y][able] = 1;
                que.push({ { count,able}, {x + 1,y} });
            }
            else {
                if (able) {
                    check[x + 1][y][able] = 1;
                    que.push({ { count,0 }, { x + 1,y } });
                }
            }
        }
        if (x > 1 && !check[x - 1][y][able]) {
            if (!map[x - 1][y]) {
                check[x - 1][y][able] = 1;
                que.push({ {count,able},{x - 1,y} });
            }
            else {
                if (able) {
                    check[x - 1][y][able] = 1;
                    que.push({ { count,0},{x - 1,y} });
                }
            }
        }
        if (y < m && !check[x][y + 1][able]) {
            if (!map[x][y + 1]) {
                check[x][y + 1][able] = 1;
                que.push({ { count,able }, { x,y + 1 } });
            }
            else {
                if (able) {
                    check[x][y + 1][able] = 1;
                    que.push({ { count,0 }, { x,y + 1 } });
                }
            }
        }
        if (y > 1 && !check[x][y - 1][able]) {
            if (!map[x][y - 1]) {
                check[x][y - 1][able] = 1;
                que.push({ { count,able }, { x,y - 1 } });
            }
            else {
                if (able) {
                    check[x][y - 1][able] = 1;
                    que.push({ { count,0 }, { x,y - 1 } });
                }
            }
        }
    }
    printf("-1");
    return 0;

}


