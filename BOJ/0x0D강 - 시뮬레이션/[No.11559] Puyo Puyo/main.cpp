#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int ROWS = 12;
int COLS = 6;
int dx[4] = {-1, 1, 0, 0}; // 상하좌우 방향 벡터
int dy[4] = {0, 0, -1, 1};

vector<string> field(ROWS);

// BFS를 이용하여 같은 색의 뿌요 그룹을 찾음
vector<pair<int, int>> bfs(int x, int y, vector<vector<bool>>& visited) {
    vector<pair<int, int>> connected;
    queue<pair<int, int>> q;
    char color = field[x][y];
    q.push({x, y});
    visited[x][y] = true;
    connected.push_back({x, y});

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS) {
                if (!visited[nx][ny] && field[nx][ny] == color) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    connected.push_back({nx, ny});
                }
            }
        }
    }
    return connected;
}

// 중력을 적용하여 뿌요를 아래로 떨어뜨림
void applyGravity() {
    for (int col = 0; col < COLS; ++col) {
        int emptyRow = ROWS - 1;
        for (int row = ROWS - 1; row >= 0; --row) {
            if (field[row][col] != '.') {
                field[emptyRow][col] = field[row][col];
                if (emptyRow != row) field[row][col] = '.';
                --emptyRow;
            }
        }
        for (int row = emptyRow; row >= 0; --row) {
            field[row][col] = '.';
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    // 필드 입력
    for (int i = 0; i < ROWS; ++i) {
        cin >> field[i];
    }

    int chainCount = 0;

    while (true) {
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        vector<pair<int, int>> toPop;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (field[i][j] != '.' && !visited[i][j]) {
                    auto connected = bfs(i, j, visited);
                    if (connected.size() >= 4) {
                        toPop.insert(toPop.end(), connected.begin(), connected.end());
                    }
                }
            }
        }

        if (toPop.empty()) break;

        for (auto [x, y] : toPop) {
            field[x][y] = '.';
        }

        applyGravity();
        ++chainCount;
    }

    cout << chainCount << "\n";
    return 0;
}
