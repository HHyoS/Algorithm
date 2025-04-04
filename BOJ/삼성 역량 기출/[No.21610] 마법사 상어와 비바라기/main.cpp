#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int N, M;
vector<vector<int>> A;
vector<pair<int, int>> clouds;

void moveClouds(int d, int s) {
    vector<vector<bool>> new_clouds(N, vector<bool>(N, false));

    for (auto &cloud : clouds) {
        int x = (cloud.first + dx[d] * s + N * s) % N;
        int y = (cloud.second + dy[d] * s + N * s) % N;

        new_clouds[x][y] = true;
        A[x][y]++;
    }

    clouds.clear();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (new_clouds[i][j]) {
                int cnt = 0;
                for (int d = 1; d < 8; d += 2) {
                    int nx = i + dx[d], ny = j + dy[d];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N && A[nx][ny] > 0)
                        cnt++;
                }
                A[i][j] += cnt;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!new_clouds[i][j] && A[i][j] >= 2) {
                clouds.emplace_back(i, j);
                A[i][j] -= 2;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    A.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    clouds = {{N - 1, 0}, {N - 1, 1}, {N - 2, 0}, {N - 2, 1}};

    while (M--) {
        int d, s;
        cin >> d >> s;
        moveClouds(d - 1, s);
    }

    int result = 0;
    for (const auto &row : A)
        for (int water : row)
            result += water;

    cout << result << "\n";
    return 0;
}
