# 문제 사이트
https://www.acmicpc.net/problem/16236

# 문제 설명

![image](https://github.com/user-attachments/assets/e390a11a-ce6b-4f05-9773-54fdceefa4cd)
![image](https://github.com/user-attachments/assets/784a5798-fc1b-471a-9ae4-9f77d5408383)
![image](https://github.com/user-attachments/assets/bda03868-f98c-4a13-9b29-cf780428d822)

# 문제 요약

* N×N 크기 공간에 물고기들과 아기 상어(크기 2, 처음 위치 9)가 존재.
* 아기 상어는 자신보다 작은 물고기만 먹을 수 있음.
* 같은 크기의 물고기는 지나갈 수는 있지만 먹을 수는 없음.
* 자신보다 큰 물고기는 지나갈 수 없음.
* 상어는 먹을 수 있는 물고기 중 가장 가까운 물고기를 먹음.
* 거리가 같다면 위쪽, 그다음 왼쪽 우선.
* 상어는 자기 크기만큼 물고기를 먹으면 크기가 1 증가함.
* 먹는 데는 시간이 안 걸리고, 이동 1칸 = 1초.

# 풀이 알고리즘

## 1. 변수 및 상태 초기화
* 입력을 통해 공간을 채우며, 9인 위치를 찾고 → (x, y)에 상어 배치.
* grid[x][y] = 0으로 초기화 (상어는 공간에 표시하지 않음).
* 상어의 초기 상태: 크기 = 2, 먹은 수 = 0, 시간 = 0

## 2. BFS 탐색으로 먹을 수 있는 물고기 찾기
* 시작점에서 BFS를 돌며 갈 수 있는 모든 칸 탐색.
* 조건
  - 상어 크기보다 작으면 → 먹을 수 있는 후보
  - 상어 크기보다 크면 → 이동 불가
  - 같으면 → 지나갈 수만 있음
  - 후보를 vector에 모아서 정렬:
* 정렬 기준: 1. 거리 → 2. x 좌표 → 3. y 좌표

## 3. 먹고 이동
* 정렬된 후보 중 첫 번째 선택 → 먹기
* 상어 위치 갱신, eat_count++, time += 거리
* 먹은 개수 = 현재 크기면 → 크기++, eat_count = 0
* 해당 위치의 grid[x][y] = 0 (물고기 제거)

## 4. 반복 or 종료
* 더 이상 먹을 수 있는 물고기가 없으면 종료
* 총 소요 시간 출력

# 풀이 코드
```cpp
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
```
