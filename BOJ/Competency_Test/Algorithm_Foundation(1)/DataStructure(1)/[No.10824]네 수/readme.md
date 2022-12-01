문제 사이트 : https://www.acmicpc.net/problem/10824

문제 설명 :

    네 자연수 A, B, C, D가 주어진다. 
    
    이때, A와 B를 붙인 수와 C와 D를 붙인 수의 합을 구하는 프로그램을 작성하시오.

    두 수 A와 B를 합치는 것은 A의 뒤에 B를 붙이는 것을 의미한다.
    
    즉, 20과 30을 붙이면 2030이 된다.

입력

    첫째 줄에 네 자연수 A, B, C, D가 주어진다. (1 ≤ A, B, C, D ≤ 1,000,000)

출력

    A와 B를 붙인 수와 C와 D를 붙인 수의 합을 출력한다.

예제 입력 1 

    10 20 30 40

예제 출력 1 

    4060
    
[ 풀 이 ] 

    주어진 A,B,C,D 를 이용하여 ( A 와 B를 붙인수 ) + ( C 와 D를 붙인수) 를 구하는 문제였습니다.
    
    제가 생각한 풀이 방법 첫번째는 뒤에 위치하는 B 와 D가 가지는 자릿수를 구하고
    
    A와 C에 해당 자리수+1 에 해당하는 10의 제곱수를 곱해주어 A<+>B , C<+>D를 구하고
    
    구한 두 수를 다시 더하여 문제를 해결하는 방식입니다.
    
    두 번쨰 방법은 입력값 A,B,C,D를 문자열로 처리하여 
    
    문자열 연산으로 A+B, C+D 를 하여 붙인수를 구하고
    
    붙인 수를 stoll 함수를 이용하여 long long 형태로 바꾼 뒤 두 수를 더하는 방법이였습니다.
    
[ 구 현 ]

1. 숫자 처리방식.

        #include <iostream>
        #include <string>
        using namespace std;


        int num[8] = { 1,10,100,1000,10000,100000,1000000,10000000 };
        int main() {

          ios::sync_with_stdio(0);
          cin.tie(0);
          cout.tie(0);
          long long A, B, C, D;
          long long sum_A, sum_B;
          //freopen("Input.txt", "r", stdin);
          cin >> A >> B >> C >> D;
          int idx = 0;
          while ((B / num[idx]) != 0) {
            ++idx;
          }
          sum_A = A * num[idx] + B;
          idx = 0;
          while ((D / num[idx]) != 0) { // B와 D의 10^idx 값을 한 자리 더 큰 10의 제곱을 찾은 뒤
            ++idx;
          }
          sum_B = C * num[idx] + D; // A와 C에 제곱들을 곱해주고 B와 D를 더하면 끝
          cout << sum_A+ sum_B; // 
          return 0;
        }

2. 문자열 처리방식.

        #include <iostream>
        #include <string>
        using namespace std;


        int main() {

          ios::sync_with_stdio(0);
          cin.tie(0);
          cout.tie(0);
          string A, B, C, D;
          freopen("Input.txt", "r", stdin);
          cin >> A >> B >> C >> D;

          A = A + B; // 문자열 연산으로 붙인수 구하기
          C = C + D;

          cout << stoll(A) + stoll(C); // 붙인수를 long long 형태로 바꾸어 더하기연산
          return 0;
        }
    
    
