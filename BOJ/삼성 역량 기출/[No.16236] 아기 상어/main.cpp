#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int board[20][20];
int dx[4] = {-1, 0, 0, 1}; // 위, 왼, 오, 아래
int dy[4] = {0, -1, 1, 0};

struct Shark {
    int x, y, size, eat;
};

int bfs(Shark &shark) {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int, int>> q;

    q.push({shark.x, shark.y});
    dist[shark.x][shark.y] = 0;

    vector<tuple<int, int, int>> candidates;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (dist[nx][ny] != -1) continue;
            if (board[nx][ny] > shark.size) continue; // 못 지나감

            dist[nx][ny] = dist[x][y] + 1;

            if (board[nx][ny] != 0 && board[nx][ny] < shark.size) {
                // 먹을 수 있는 물고기 발견
                candidates.push_back({dist[nx][ny], nx, ny});
            }

            q.push({nx, ny});
        }
    }

    if (candidates.empty()) return 0;

    // 거리 → 위쪽 → 왼쪽 순으로 정렬
    sort(candidates.begin(), candidates.end());

    int d, nx, ny;
    tie(d, nx, ny) = candidates[0];

    shark.x = nx;
    shark.y = ny;
    shark.eat += 1;
    if (shark.eat == shark.size) {
        shark.size++;
        shark.eat = 0;
    }

    board[nx][ny] = 0; // 물고기 먹음
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    Shark shark;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark = {i, j, 2, 0};
                board[i][j] = 0; // 초기 위치 제거
            }
        }
    }

    int total_time = 0;
    while (true) {
        int time = bfs(shark);
        if (time == 0) break;
        total_time += time;
    }

    cout << total_time << '\n';
    return 0;
}
