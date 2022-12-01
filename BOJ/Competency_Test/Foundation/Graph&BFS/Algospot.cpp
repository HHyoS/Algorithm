#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool map[101][101];
bool check[101][101];

int main(void){
    int n, m;
  //  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);

    for (int a = 1; a <= m; ++a) {
        for (int b = 1; b <= n; ++b) {
            scanf("%1d", &map[a][b]);
        }
    }
    priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int, int>>>> que;


    que.push({ 0,{1,1} });
    check[1][1] = 1;



    while (!que.empty()){

        int ct = que.top().first;
        int x = que.top().second.first;
        int y = que.top().second.second;

        que.pop();

        if (x == m && y == n) {
            printf("%d", ct);
            return 0;
        }

        if (x < m && !check[x+1][y]) {
            if (!map[x + 1][y]) {
                check[x + 1][y] = 1;
                que.push({ ct,{x + 1,y} });
            }
            else {
                check[x + 1][y] = 1;
                que.push({ct+1 ,{x + 1,y} });
            }
        }
        if (x > 1 && !check[x -1][y]) {
            check[x - 1][y] = 1;
            if (!map[x - 1][y]) {
                que.push({ ct,{x - 1,y} });
            }
            else {
                que.push({ ct+1,{x - 1,y} });
            }
        }
        if (y < n && !check[x][y+1]) {
            check[x][y + 1] = 1;
            if (!map[x][y+1]) {
                que.push({ ct,{x,y+1} });
            }
            else {
                que.push({ ct+1,{x,y+1} });
            }
        }
        if (y > 1 && !check[x][y-1]) {
            check[x][y - 1] = 1;
            if (!map[x][y-1]) {
                que.push({ ct,{x,y-1} });
            }
            else {
                que.push({ ct+1,{x,y-1} });
            }
        }
    }

    return 0;

}


