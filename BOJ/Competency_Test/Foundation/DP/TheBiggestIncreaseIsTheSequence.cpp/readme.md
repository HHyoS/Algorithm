문제 사이트 : https://www.acmicpc.net/problem/11055


문제 설명

    수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

    예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

풀이

    주어진 수열 중 증가 부분 수열의 합이 가장 큰 값을 찾는 문제였습니다.

    해당 문제의 풀이 알고리즘은 다음과 같습니다.

    수열의 값이 저장된 ar배열과, 특정 인덱스에서 최대값을 저장하며 갱신하는 배열인 dp배열을 선언한 뒤

    ar배열과 dp배열을 입력받은 값으로 초기화하고, 2중 for문을 이용하여 이전 인덱스(b)에서 현재 인덱스(a)로 부분 증가 수열이 만들어

    질 수 있다면, 현재 값 + 이전 인덱스의 dp값 을 더하여  max(dp[a], dp[b] + ar[a]) 중 더 큰값을 dp배열에 저장ㅇ시킵니다.

    2중 for문의 탐색이 종료되면 max_element 함수를 이용하여 최대값을 갖는 dp를 찾아서 출력합니다.
    
 
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
            dp[a] = ar[a];
        }
        for (int a = 2; a <= n; ++a) {
            for (int b = 1; b < a; ++b) {
                if (ar[b] < ar[a]) {
                        dp[a] = max(dp[a], dp[b] + ar[a]);
                }
            }
        }
        printf("%d\n", *max_element(dp, dp + n + 1));
        return 0;
    }
