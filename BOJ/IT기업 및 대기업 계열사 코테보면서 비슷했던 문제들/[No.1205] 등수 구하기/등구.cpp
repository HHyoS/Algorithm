#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, S, P; // N=점수 개수, S=태수점수, P=랭킹 가능 개수
priority_queue<int> que;
int Solve() {
    int rank = 1;
    int cnt = 0;
    int ans = -1;
    if (N == 0) // N이 0이면 P는 항상 10 이상이므로 1등
        return 1;
    while (!que.empty()) {// 우선순위 que에서 꺼내면서
        int now_score = que.top();
        que.pop();
        ++cnt;
        if (now_score > S) { // 우선순위 큐의 숫자가 크면 다음으로 넘기기
            rank = cnt+1;
        }
        else if (now_score == S) { // 숫자가 같다면 등수 찾기 가능
            while (!que.empty() && que.top() == now_score) { // 동일 등수가 몇명인지 체크
                now_score = que.top();
                que.pop();
                ++cnt;
            }
            if (cnt < P) { // 동일 등수를 다 합쳤을 때, 랭킹 범위 내에 들어온다면
                ans = rank; // 랭킹은 모두 동일 랭킹으로 세팅
            }
            break;
        }
        else { // if(now_score < S) // 현재 점수보다 크다면, 내 위치 정해주기
            ans = rank;
            break;
        }
    }
    if (N < P && ans == -1) { // 만약 등수가 정해지지 않았는데, 모든 큐의 값을 다 뺏다면
        return N + 1; // 현재 등록된 랭킹 +1이 내 랭킹
    }
    return ans;
}
void Input() {
    cin >> N >> S >> P;
    for (int a = 0; a < N; ++a) {
        int temp;
        cin >> temp;
        que.push(temp);
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    cout << Solve();


    return 0;
}
