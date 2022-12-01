문제 사이트 : https://www.acmicpc.net/problem/10872

문제 설명 :

    0보다 크거나 같은 정수 N이 주어진다.
    
    이때, N!을 출력하는 프로그램을 작성하시오.

입력

    첫째 줄에 정수 N(0 ≤ N ≤ 12)이 주어진다.

출력

    첫째 줄에 N!을 출력한다.

예제 입력 1 

    10

예제 출력 1 

    3628800

예제 입력 2

    0

예제 출력 2 

    1
    
풀이 알고리즘

    팩토리얼을 코드로 구현하는 문제였습니다.
    
    N! 이라는 값이 의미하는 연산은 다음과 같습니다.
    
    1 * 2 * 3 * 4 * ... * N
    
    위의 알고리즘을 while 문을 이용하여 간단하게 구현하였고, 
    
    0! = 1 이라는 입/출력이 주어졌으므로  
    
    해당값을 예외처리하여 0이 입력되었을 경우
    
    1을 출력하도록하여 문제를 해결하였습니다.
    
[ 구 현 ]

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <queue>
    #include <utility>
    using namespace std;

    int N;
    int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      //	freopen("Input.txt", "r", stdin);
      cin >> N;
      long num = N--;
      if (N < 0) {
        cout << 1;
        return 0;
      }
      while (N > 1) {
        num *= N--;

      }
      cout << num;
      return 0;
    }
