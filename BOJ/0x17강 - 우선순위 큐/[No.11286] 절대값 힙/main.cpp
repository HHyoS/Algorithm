#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 사용자 정의 비교 함수
struct Compare {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) return a > b;  // 절댓값이 같으면 더 작은 수가 먼저
        return abs(a) > abs(b);              // 절댓값이 작은 수가 먼저
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, Compare> pq;

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x != 0) {
            pq.push(x);
        } else {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}
