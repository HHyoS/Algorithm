#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int idx;
    int gold;
    int silver;
    int bronze;
};
bool operator<(Node a, Node b) { // 우선순위 큐 정렬 우선순위 정해주기
    if (a.gold == b.gold) {
        if (a.silver == b.silver) {
            return a.bronze < b.bronze;
        }
        return a.silver < b.silver;
    }
    return a.gold < b.gold;
}

priority_queue<Node> que;
Node arr[1001];
int answer[1001];
int N;
int target;

bool Same_Or_Different(Node before, Node now) { // 등수를 어떻게 처리할지 체크용
    if (before.gold == now.gold && before.silver == now.silver && before.bronze == now.bronze) {
        return 1;
    }
    return 0;
}
int Solve() {
    
    Node before = { 0,0,0,0 }; // 등수는 내 앞과 비교하면 되므로 데리고 다니자
    int rank = 1; // 랭킹 현재 나라에 어떤 등수를 줘야하나 
    int cnt = 1;//  cnt는 현재까지 뽑힌 나라 개수 - 앞 나라와 같지 않다면 cnt가 등수가 됨.
    while (!que.empty()) {
        Node now = que.top();
        que.pop();
        if (Same_Or_Different(before, now)) { // 금은동 개수가 동일하면 동일 등수 처리
            answer[now.idx] = rank; // 금은동 개수가 같으므로 rank는 고정
        }
        else { // 금은동 갯수가 다르다면, 
            answer[now.idx] = cnt; // 우선순위 큐에서 나온 나라의 수가 현재 등수
            rank = cnt; // 순위도 다시 정상적으로 바꿔주기
        }
        before = now; // 이전 나라 대신 현재 나라로 다시 세팅
        ++cnt; // 현재까지 뽑은 나라 다시 세팅해주기

        if (now.idx == target) { // 현재 나라가 궁금한 나라라면
            return answer[now.idx]; // 등수 return해서 끝내주기
        }
    }
    
}
void Input() {
    cin >> N >> target;
    for (int a = 1; a <= N; ++a) {
        int idx, g, s, b; // 나라 번호, 금-은-동
        cin >> idx >> g >> s >> b;
        arr[a] = { idx, g, s, b };
        que.push(arr[a]);
        // cout test for debugging
        // cout << arr[a].idx << " " << arr[a].gold << " " << arr[a].silver << " " << arr[a].bronze << "\n";
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
