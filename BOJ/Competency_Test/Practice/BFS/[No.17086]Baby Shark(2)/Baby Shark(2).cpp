#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int N, M;
bool sea[50][50];
vector<pair<int, int>> shark;
int mov[8][2] = { {-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1} };
bool check[50][50];
int big = -1;
void bfs(int X, int Y) {
    queue<pair<int, int>> que;
    que.push({ X,Y });
    int count = 1;
    check[X][Y] = 1;
    while (!que.empty()) {
        int size = que.size();
        for (int a = 0; a < size; ++a) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for (int b = 0; b < 8; ++b) {
                int xx = x + mov[b][0];
                int yy = y + mov[b][1];
                if ((xx >= 0) && (xx < N) && (yy >= 0) && (yy < M) && !check[xx][yy]) {
                    check[xx][yy] = 1;
                    if (sea[xx][yy]) {
                        if (big < count)
                            big = count;
                        return;
                    }
                    que.push({ xx,yy });
                }
            }
        }
        ++count;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

   freopen("Input.txt","r", stdin);
    cin >> N >> M;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            cin >> sea[a][b];
            if (!sea[a][b])
                shark.push_back({ a,b });
        }
    }

    for (int a = 0; a < shark.size(); ++a) {
            bfs(shark[a].first, shark[a].second);
            memset(check, 0, sizeof(check));
    }
    cout << big;
    return 0;

}
