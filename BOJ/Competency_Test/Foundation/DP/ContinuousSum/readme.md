문제 사이트 : https://www.acmicpc.net/problem/1912


설명

    n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

    예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.


풀이

    주어진 수열에서 연속된 수를 골라 만들 수 있는 가장 큰 수를 구하는 문제입니다.

    문제 해결 방식은 다음과 같습니다.

        1. 주어진 수열을 배열에 저장한다. ( 사용하는 배열은 0번부터 n-1번까지)

        2. for문을 이용하여 ar배열을 다시 작성시작 ( for문의 시작은 1번부터)

        3. 현재 값, 현재값 + 이전값 중 더 큰값을 현재 배열의 위치에 저장

        4. for문이 완료되면 max_element 함수를 이용하여 최대값 출력 


코드

    #include <cstdio>
    #include <algorithm>
    using namespace std;

    int ar[100000] = { 0, };

    int main() {
        int n;
        scanf("%d", &n);
        for (int a = 0; a < n; ++a) {
            scanf("%d", &ar[a]);
        }
        for (int a = 1; a < n; ++a) {
            ar[a] = max(ar[a-1]+ar[a], ar[a]); // 현재값인 ar[a]와 이전 최대값인 ar[a-1] + ar[a] 중 큰 값을
            // ar[a] 에 저장
        }
        printf("%d", *max_element(ar, ar + n));
        return 0;
    }
