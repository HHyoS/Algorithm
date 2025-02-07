#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/14719
    문제 설명 :
       "2차원 블록 세계가 있다.
        각 블록은 높이가 다른데, 비가 오면 블록들 사이에 생긴 골에는 빗물이 고인다.
        입력으로 2차원 세계 블록의 정보가 주어질 때, 고일 수 있는 빗물의 양을 구하라"
        가 문제의 요약 입니다.

        문제풀이 초기에는 단순 stack 풀이를 생각 했으나, 특정 높이와 동일하거나 더 높은
        블록을 만나지 않으면 빗물이 고일 수 없기 때문에 다른 풀이 방법을 구상이 필요합니다.

        문제에서 주어진 블록 세계의 크기 W와 H는 각 최대 500으로 최대 격자 넓이는 2,500이 되는데
        위 값을 단순 for문으로 동작했을 때 충분히 처리 가능한 크기입니다.

        그래서 저는 격자 정보를 입력받으면 배열을 통해 블록 세계의 정보를 입력한 뒤
        높이 1부터 H까지 각 높이에 대해 1부터 W까지 탐색을 진행하며 '블록이 있는 위치 - 블록 이 있는 위치
        사이 공간에 빗물이 찬다' 라고 정의하고 풀이를 진행하였습니다.

        단순하게 위치- 위치 를 계산 할 경우, 실제로는 위치(1)과 위치(2) 사이의 공간에만
        물이 고이기 떄문에 실제 계산시에는 (위치 - 위치 - 1)을 하여 고이는 빗물 양을
        더해주어 풀이 완료 했습니다.

      */

int H, W;
int ans = 0;
bool rain[501][501];
void Solve() {
    for (int a = 1; a <= H; ++a) { // 모든 높이에 대해 탐색 시작
        int idx = -1; // 초기 값 세팅
        for (int b = 0; b < W; ++b) { // 특정 높이 a에 대해 블록을 가지고 있는 위치 다 찾아보기
            if (rain[b][a] == true) { // 현재 위치에 블록이 있는데
                if (idx == -1) { // 아직 블록을 만나지 못했다면
                    idx = b; // 처음 블록을 만난 위치 기록
                }
                else { // 이전에 블록을 만났었다면
                    ans = ans + (b - idx - 1); // 해당 블록부터 현 블록 사이에 빗물이 고임
                    idx = b; // 그리고 다음에 빗물이 고이는 위치의 시작은 현재 위치
                }
            }
        }
    }
    cout << ans; // 정답 출력
}
void Input() {
    cin >> H >> W;
    for (int a = 0; a < W; ++a) {
        int h;
        cin >> h;
        for (int b = 0; b <= h; ++b) { // 블록 세계 정보 입력
            rain[a][b] = true;
        }
    }

}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
