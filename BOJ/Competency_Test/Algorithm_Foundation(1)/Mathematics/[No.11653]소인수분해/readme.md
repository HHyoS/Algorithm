문제 사이트 : https://www.acmicpc.net/problem/11653

문제 설명 :

    정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

입력

    첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

출력

    N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다.
    N이 1인 경우 아무것도 출력하지 않는다.

예제 입력 1 

    72

예제 출력 1 

    2
    2
    2
    3
    3

예제 입력 2 

    3

예제 출력 2 

    3

예제 입력 3

    6

예제 출력 3 

    2
    3

예제 입력 4 

    2

예제 출력 4 

    2

예제 입력 5 

    9991

예제 출력 5 

    97
    103
    
풀이 알고리즘

    숫자 N이 주어졌을 떄, N을 소인수 분해 하고, 그 결과를 오름차순으로 출력하는 문제입니다.
    
    이 문제는 실제로 소인수 분해 하듯이, 2 <= X <= N 을 만족하는 X 중, N % X == 0 을 만족하는 
    
    X를 찾고, 출력한 뒤 N = N / X 로 N값을 갱신하는 알고리즘을 N == 1 이 될떄까지 반복하는
    
    문제였습니다.
    
    while(N != 1) 의 조건을 갖는 while문을 이용하여 위의 알고리즘을 구현하여 문제를 해결하였습니다.
    
[ 구 현 ]

    #include <iostream>
    #include <vector>
    #include <stack>
    #include <algorithm>
    using namespace std;
    int N;
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        //freopen("Input.txt", "r", stdin);
        cin >> N;

        while (N != 1) { // N값이 1이되어 더이상 분해할 수 없으면 반복 종료
        
            for (int a = 2; a <= N; ++a) { // 오름찾순으로 출력이므로 가장 작은값부터 테스트
                if (N % a == 0) { // a값이 N을 소인수분해 할 수 있는 값이라면
                    cout << a << "\n"; // 출력한 이후
                    N = N / a; // N값을 갱신 후 
                    break; // for문 종료
                }
            }
        }

        return 0;
    }

