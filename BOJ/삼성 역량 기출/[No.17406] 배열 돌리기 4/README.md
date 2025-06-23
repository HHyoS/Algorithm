# 문제 사이트
https://www.acmicpc.net/problem/17406

# 문제 설명
![image](https://github.com/user-attachments/assets/7882ef9d-de5a-4992-83eb-54b855f0f653)
![image](https://github.com/user-attachments/assets/17a31164-a222-4498-8e45-1833f5d69e44)
![image](https://github.com/user-attachments/assets/0ef00c59-7a15-4ec9-9219-c68cc38f921b)

# 문제 요약
- 입력
  * N×M 배열(행렬) / 2 <= N,M ≤ 50
  * 회전 연산 K개 / 1 <= K <= 6
- 회전 연산 -  각 회전 연산은 (r, c, s) 형태
  * 중심이(r,c) (1-based 인덱스)인 정사각형 영역을, 반지름이 s인, 즉 위쪽 경계 r−s,
  * 아래쪽 경계 r+s, 왼쪽 경계 c−s, 오른쪽 경계 c+s인 영역의 테두리를 시계 방향으로 한 칸씩 회전시키는 작업.
- 풀이 진행
  * 여러 회전 연산을 임의의 순서로 적용할 수 있음.
  * K개의 연산 순서를 자유롭게 바꾸어 적용.
  * 순서를 정해 적용한 뒤, 최종 배열 상태에서 각 행의 원소 합을 구하고, 그 중 최솟값을 구함.
  * 가능한 모든 연산 순서에 대하여 얻은 최종 배열의 행별 합 중 최소값들 중 가장 작은 값을 정답으로 출력.
 
# 풀이 정리
- 원본 배열 : 입력받은 배열을 original에 저장.
- 회전 연산 리스트 보관: rotations 배열에 (r, c, s) 목록 저장.
- 회전 순서 순열 생성: order = [0,1,...,K-1] 초기화 후 next_permutation으로 모든 순열(총 K!개) 순회.
- 각 순열마다:
  * board = original으로 복사.
  * 순열에 따라 인덱스 idx를 뽑아 applyRotation(rotations[idx]) 호출하여 board에 직접 회전 적용.
  * 회전 연산을 모두 완료한 뒤, computeMinRowSum(board)로 각 행 합 계산, 최솟값 얻음.
  * 전역 최솟값 answer = min(answer, 이 순열의 결과값).
- 모든 순열 탐색 후 answer 출력.

# 풀이 코드

```cpp
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

```

풀이 인증

![image](https://github.com/user-attachments/assets/88bae297-6fc4-4763-a54e-3f9a8686cd26)


