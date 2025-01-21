#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int T, N;
long long stock[1000001];
void Solve() {
}
void Input() {
    cin >> T;
    for (int a = 0; a < T; ++a) {
        cin >> N;
        for (int b = 0; b < N; ++b) {
            cin >> stock[b];
        }
        long long max_profit = 0;
        int max_idx = N - 1;
        // 모든 날의 정보를 알고 있으므로 뒷날부터 최대 값을 확인해보자

        // 최대값을 저장하며, 해당 값보다 낮은 주가를 가진 날은 해당 날에 파는게 제일 이득
        // 최대값이 앞 날에 존재한다면 해당 날로 최대값 위치를 변경하여 더 앞의 날들은
        // 해당 날에 주식을 판매한 것으로 처리
        for (int b = N-2; b >= 0; --b) {
            if (stock[max_idx] > stock[b]) {
                max_profit = max_profit + stock[max_idx] - stock[b];
            }
            else if (stock[max_idx] < stock[b]) {
                max_idx = b;
            }
        }
        cout << max_profit << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
   // Solve();
    return 0;
}
