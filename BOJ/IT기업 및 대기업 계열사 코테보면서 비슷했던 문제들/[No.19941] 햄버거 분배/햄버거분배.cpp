#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

/*
    문제를 보면 그리디로 보이니까 어떻게 풀지 고민해보자..
    도달 거리가 정해져 있으므로
    킹론상 가장 가까운 햄버거를 집어야, 최대 사람이 먹을 수 있음
    따라서 맨 앞 혹은 맨 뒤에서 시작하자.
    그리고 시작이 햄버거라면 햄버거 기준 가장 가까운 사람에게 햄버거를 주고
    시작이 사람이라면 가장 가까운 햄버거를 체크해주자

*/
string hambuger;
int N, K;
bool eat[20001];
void Solve() {
    int answer = 0;
    for (int a = 0; a < N; ++a) {
        int checker = 0;

        // 이미 먹은 햄버거 or 먹은 사람 스킵
        if (eat[a] == 1) continue;

        // K까지의 범위 내에서 현재 인덱스의 상태(햄버거 or 사람)와
        // 다른 인덱스를 찾자
        for (int b = 1; b <= K; ++b) {
            int idx = a + b;
            if (idx >= N) break; // 범위 벗어나면 안되니까 처리해주고

            // 만약 찾은 인덱스가 1) 현재 먹히거나 먹은 사람이 아니고
            // 2) 현재 상태(햄버거 or 사람)이 아니여서 먹히거나 먹을 수 있는 관계라면
            // 먹고 정답 +1하고 먹음 처리
            if (eat[idx] == 0 && hambuger[idx] != hambuger[a]) {
                eat[idx] = 1;
                ++answer;
                break;
            }
        }
    }
    cout << answer;
}
void Input() {
    cin >> N >> K;
    cin >> hambuger;

}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
