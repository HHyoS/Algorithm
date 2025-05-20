![image](https://github.com/user-attachments/assets/f3220163-40b0-4efc-a6bc-347fcd6fd990)문제 사이트 : https://www.acmicpc.net/problem/11049

문제 설명

![image](https://github.com/user-attachments/assets/9e5b03db-c63b-4f5c-955a-088c6f3601a8)
![image](https://github.com/user-attachments/assets/cddac407-f801-4781-bed1-097c7b0f3727)

풀이 알고리즘

    입력 처리
    -  N개 행렬의 각 크기 r과c가 주어짐
    -  DP용 배열 d를 길이 N+1 크기로 만들고 아래 형태로 채움
        d(0) = r(1) , d(1) = c(1) = r(2), d(N-1) = c(N-1) =  r(N), d(N) = c(N)
        
    dp 테이블 초기화
    - 2차원 배열 dp[N+1][N+1]을 전부 0으로 초기화 (dp[i][i] = 0)

    길이 기준 탐색
    - len을 1부터 N-1 까지 탐색(len - j-i)
    - 각 i에 대해 j = i + len을 정하고 아래 점화식 진행
    dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + d[i-1]*d[k]*d[j])

    결과
    - dp[1][N]이 최소 곱셈 횟수.

풀이 코드

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <limits.h>
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

풀이 결과

![image](https://github.com/user-attachments/assets/6771436c-f448-4b74-9847-4ddbb0bccc2c)
