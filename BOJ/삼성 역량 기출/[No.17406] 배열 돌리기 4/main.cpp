#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int original[51][51];
int board[51][51];

struct Rotation {
    int r, c, s;
};

vector<Rotation> rotations;
vector<int> order;

// 한 번 회전 연산: board에 직접 적용
void applyRotation(const Rotation &rot) {
    int r = rot.r;
    int c = rot.c;
    int s = rot.s;

    // 각 레이어별로 시계 방향으로 한 칸씩 이동
    for (int layer = 1; layer <= s; layer++) {
        int top = r - layer;
        int left = c - layer;
        int bottom = r + layer;
        int right = c + layer;

        // 1) 테두리 좌표를 시계 방향 순서대로 수집
        vector<pair<int,int>> pos;
        // 위쪽 행, 왼쪽→오른쪽 (끝점 제외: right)
        for (int j = left; j < right; j++) {
            pos.emplace_back(top, j);
        }
        // 오른쪽 열, 위→아래 (끝점 제외: bottom)
        for (int i = top; i < bottom; i++) {
            pos.emplace_back(i, right);
        }
        // 아래쪽 행, 오른쪽→왼쪽 (끝점 제외: left)
        for (int j = right; j > left; j--) {
            pos.emplace_back(bottom, j);
        }
        // 왼쪽 열, 아래→위 (끝점 제외: top)
        for (int i = bottom; i > top; i--) {
            pos.emplace_back(i, left);
        }

        int L = pos.size();
        if (L == 0) continue;

        // 2) 현재 값 수집
        vector<int> vals(L);
        for (int idx = 0; idx < L; idx++) {
            int x = pos[idx].first;
            int y = pos[idx].second;
            vals[idx] = board[x][y];
        }

        // 3) 시계 방향으로 한 칸 이동: shift right by 1
        vector<int> rvals(L);
        for (int idx = 0; idx < L; idx++) {
            int new_idx = (idx + 1) % L;
            rvals[new_idx] = vals[idx];
        }

        // 4) 다시 쓰기
        for (int idx = 0; idx < L; idx++) {
            int x = pos[idx].first;
            int y = pos[idx].second;
            board[x][y] = rvals[idx];
        }
    }
}

// 현재 board 상태에서 각 행 합 중 최소값 계산
int computeMinRowSum() {
    int ans = 21e8;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= M; j++) {
            sum += board[i][j];
        }
        ans = min(ans, sum);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> original[i][j];
        }
    }
    rotations.resize(K);
    order.resize(K);
    for (int i = 0; i < K; i++) {
        cin >> rotations[i].r >> rotations[i].c >> rotations[i].s;
        order[i] = i;
    }

    int answer = 21e8;

    // 모든 순열 시도
    do {
        // original을 board로 복사
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                board[i][j] = original[i][j];

        // 순서대로 회전 연산 적용
        for (int idx : order) {
            applyRotation(rotations[idx]);
        }

        // 결과 행 합 최소값 갱신
        answer = min(answer, computeMinRowSum());

    } while (next_permutation(order.begin(), order.end()));

    cout << answer << "\n";
    return 0;
}

