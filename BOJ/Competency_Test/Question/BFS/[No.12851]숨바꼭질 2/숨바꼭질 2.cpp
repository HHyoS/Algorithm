#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Node {
    int idx;
    int sum;
};

bool visited[100001];
int N, K;
int miniCnt = 0;
queue<int> que;
void solve() {
    if (K <= N) {
        cout << N-K << "\n" << 1;
        return;
    }

    que.push(N);
    int time = 1;
    while (!que.empty()) {
        int size = que.size();
        for (int s = 0; s < size; ++s) {
            int nowIdx = que.front();
            que.pop();
            visited[nowIdx] = 1;
            int backIdx = nowIdx - 1;
            int goIdx = nowIdx + 1;
            int jumpIdx = nowIdx * 2;

            if (backIdx >= 0 && visited[backIdx] == 0) {
                if (backIdx == K)
                    ++miniCnt;
                else {
                    que.push({ backIdx });
                }
            }
            if (goIdx <= K && visited[goIdx]==0) {
                if (goIdx == K)
                    ++miniCnt;
                else {
                    que.push({ goIdx });
                }
            }
        
            if (jumpIdx <= 100000 && visited[jumpIdx] == 0) {
                if (jumpIdx == K)
                    ++miniCnt;
                else {
                    que.push({ jumpIdx });
                }
            }
        }
        if (miniCnt != 0) {
            cout << time << "\n" << miniCnt<<"\n";
            return;
        }
        ++time;
    }

}
void input() {
    cin >> N >> K;
}
int main() {
    input();
    solve();
    return 0;
}
