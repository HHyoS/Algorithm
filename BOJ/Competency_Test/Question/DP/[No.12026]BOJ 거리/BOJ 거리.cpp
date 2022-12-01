#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int N, M;
char bodo[1001];
int dp[1000];

bool nxt(int nxt, int before) {
    if (bodo[before] == 'B' && bodo[nxt] == 'O')
        return 1;
    if (bodo[before] == 'O' && bodo[nxt] == 'J')
        return 1;
    if (bodo[before] == 'J' && bodo[nxt] == 'B')
        return 1;

    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("Input.txt", "r", stdin);
    cin >> N >> bodo;
    for (int a = 0; a < N; ++a)
        dp[a] = 1e9;

    dp[0] = 0;
    for (int a = 1; a < N; ++a) {
        for (int b = 0; b < a; ++b) {
            if (nxt(a, b)) {
                int k =  a-b;
                dp[a] = min(dp[a], dp[b] + k * k);
            }
        }
    }
    if (dp[N - 1] == 1e9)
        cout << -1;
    else
        cout << dp[N - 1];
    return 0;
}

