문제 사이트 : https://www.acmicpc.net/problem/11722

설명

    수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

    예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

풀이

    증가하는 부분수열이 아닌 감소하는 부분수열을 찾는 문제였습니다.

    증가하는 부분수열 코드를 활용하여 2중 for문에서 현재값보다 큰 이전값이 존재한다면 수열의 길이를

    저장하는 dp 값과 비교하여 더 긴수를 저장하고, for문이 종료되면 모든 dp배열에서 가장 큰 값을 찾아 출력하도록

    코드를 구성하여 문제를 해결했습니다. 


코드

    #include <cstdio>
    #include <algorithm>
    using namespace std;


    int main() {
        int n;
        int ar[1000 + 1] = { 0, };
        int dp[1000 + 1] = { 0 };
        scanf("%d", &n);
        for (int a = 1; a <= n; ++a) {
            scanf("%d", &ar[a]);
        }
        for (int a = 2; a <= n; ++a) {
            for (int b = 1; b < a; ++b) {
                if (ar[b] > ar[a]) { // 현재 값인 ar[a]보다 큰 ar[b]가 존재할경우 
                        dp[a] = max(dp[a], dp[b] + 1); // dp[a]와 dp[b]+1중 더 큰값을 dp[a]에 저장
                }
            }
        }
        int big = *max_element(dp, dp + n + 1); // 가장 큰 dp값을 찾아 big에 저장 +1은 처음에 더해주지 못한 1
        printf("%d\n", big+1);
        return 0;
    }
