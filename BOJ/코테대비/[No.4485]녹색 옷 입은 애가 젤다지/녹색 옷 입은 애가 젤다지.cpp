
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


struct Node {
    int x;
    int y;
    int sum;
};
int N;
int arr[126][126];
int lose = 21e8;
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int dist[126][126];


bool operator<(Node a, Node b) {
    return a.sum > b.sum;
}

int bfs() {
    bool check[126][126] = {};
    priority_queue<Node> que;
    que.push({ 0,0,arr[0][0]});
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            dist[a][b] = 21e8;
        }
    }
    dist[0][0] = arr[0][0];
    while (!que.empty()) {
        int x = que.top().x;
        int y = que.top().y;
        int cost = que.top().sum;
        que.pop();

        if (dist[x][y] < cost) continue;
        for (int a = 0; a < 4; ++a) {
            int xx = x + mov[a][0];
            int yy = y + mov[a][1];

            if (xx >= 0 && xx < N && yy >= 0 && yy < N) {
                if (dist[xx][yy] > cost + arr[xx][yy]) {
                    dist[xx][yy] = cost + arr[xx][yy];
                    que.push({ xx,yy,dist[xx][yy] });
                }
            }
        }
    }
    return dist[N - 1][N - 1];
}
void input() {
    int cnt = 1;
    while (cin >> N) {
        if (N == 0)
            break;
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < N; ++b) {
                cin >> arr[a][b];
            }
        }

        cout << "Problem " << cnt << ": " << bfs() << "\n";
        ++cnt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    input();
    return 0;
}
