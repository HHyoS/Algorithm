#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int N;
priority_queue<int, vector<int>, greater<int>> que;
void Solve() {

    
}
void Input() {
    cin >> N;
    int maxi = N * N;
    for (int a = 0; a < maxi; ++a) {
        int temp;
        cin >> temp;
        que.push(temp);

        if (que.size() > N) { // 위에서 N번째 수만 알면 되므로 일단 넣고
            que.pop(); // que 사이즈가 N보다 크면 가장 작은수(맨 앞의 수)를 pop
        }
    }
    cout << que.top();
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
  //  Solve();
    return 0;
}
