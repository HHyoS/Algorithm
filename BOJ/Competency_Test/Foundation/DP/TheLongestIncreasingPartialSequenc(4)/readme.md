문제 사이트 : https://www.acmicpc.net/problem/14002

문제 설명 

    수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

    예를  들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.


풀이
  
     가장 긴 증가하는 부분수열의 확장버젼으로 수열의 길이뿐만 아니라 어떤 구성으로 가장 긴 부분수열이 완성되었는지 출력하는 문제였습니다.

     위 문제를 해결하기위해 최대수열을 완성하며 가는 단계에서 수열의 길이를 구성하는 dp배열을 갱신할 때 마다

     이전 위치를 메모라이즈하는 mp배열에 이전 위치를 저장하도록 하였고, 순서대로 출력해야하기 때문에 while문을 통해

     역순으로 출력되는 mp배열을 정렬하기위해 while문을 이용하고, 정렬된 순서를 출력하도록 프로그램을 구성하여 문제를 해결하였습니다.



코드

    #include <cstdio>
    #include <algorithm>
    using namespace std;


    int main() {
        int n;
        int ar[1000 + 1] = { 0, };
        scanf("%d", &n);
        for (int a = 1; a <= n; ++a) {
            scanf("%d", &ar[a]);
        }
        int dp[1000 + 1] = { 0 };
        int mp[1000 + 1] = { 0 };
        for (int a = 2; a <= n; ++a) {
            for (int b = 1; b < a; ++b) {
                if (ar[b] < ar[a]) {
                    if (dp[a] < dp[b] + 1) {
                        dp[a] = max(dp[a], dp[b] + 1);
                        mp[a] = b; // 새롭게 dp가 갱신될경우 mp배열에 a 인덱스를 거치는 순서의 이전에는 b 인덱스를 거쳣다 라고 저장
                    }
                }
            }
        }
        int big = *max_element(dp, dp + n + 1) + 1;
        printf("%d\n", big);
        int aa = big; // big은 사용해야하기 때문에 따로 저장
        int ch = 0;
        for (int a = n; a >= 1; --a) {
            if (big == dp[a]+1) { 
                ch = a; // 가장 긴 수열의 끝 인덱스를 찾아서 ch 에 저장
                break;
            }
        }
        while (big--) { // mp배열은 역순으로 저장되기 떄문에 순차적으로 출력하기 위한 while문
            dp[big] = ch; // 더이상 사용하지 않는 dp에 순서 저장, 초기값은 가장 긴 수열의 끝점인 ch값
            ch = mp[ch]; // mp배열에서 ch 값 이전에 방문한 인덱스를 ch값에 저장
        }
        for (int a = 0; a < aa; ++a) {
            printf("%d ", ar[dp[a]]); // 순서대로 저장된 배열을 출력
        }
        return 0;
    }
