#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 차원 정보 저장용 배열 d[0..N]
    vector<long long> d(N+1);
    // 첫 번째 행렬의 r1, c1 읽어서 d[0], d[1] 채우기
    long long r, c;
    cin >> r >> c;
    d[0] = r;
    d[1] = c;
    // 두 번째 행렬부터
    for(int i = 2; i <= N; i++){
        cin >> r >> c;
        d[i] = c;  // 이전 c == 현재 r
    }

    // dp[i][j]: i번째부터 j번째 행렬까지 곱할 때 최소 연산 수
    vector<vector<long long>> dp(N+1, vector<long long>(N+1, 0LL));

    // 길이 len = 1..N-1
    for(int len = 1; len < N; len++){
        for(int i = 1; i + len <= N; i++){
            int j = i + len;
            long long best = LLONG_MAX;
            // 분할 위치 k
            for(int k = i; k < j; k++){
                long long cost = dp[i][k] + dp[k+1][j]
                          + d[i-1] * d[k] * d[j];
                best = min(best, cost);
            }
            dp[i][j] = best;
        }
    }

    // 전체 곱셈 최소 비용
    cout << dp[1][N] << "\n";
    return 0;
}
