#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

/*
    문제의 연산
    1) 배열에 x 추가
    2) 배열의 최소값 출력 및 배열에서 제거..
        -> 배열에 값이 없을 경우 0 출력

    그냥 우선순위 큐 오름차순으로 선언해서 쓰면 될 듯?
*/



// 숫자가 오름차순으로 배치되는 우선순위 큐 선언
priority_queue<int,vector<int>,greater<int>> que;
int N;

void Input_And_Solve() {
    cin >> N;

    for (int a = 0; a < N; ++a) {
        int command;
        cin >> command;

        if (command == 0) { // 최소값을 출력해야 할 때
            if (que.empty()) { // 큐가 비어있으면 0 출력
                cout << "0\n";
            }
            else { // 큐에 숫자가 있으면 출력
                cout << que.top() << "\n";
                que.pop();
            }
        }
        else {
            que.push(command);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input_And_Solve();
    return 0;
}
