문제 사이트 :https://www.acmicpc.net/problem/1935

문제 설명 :

후위 표기식과 각 피연산자에 대응하는 값들이 주어져 있을 때, 그 식을 계산하는 프로그램을 작성하시오.

입력

    첫째 줄에 피연산자의 개수(1 ≤ N ≤ 26) 가 주어진다.
    
    그리고 둘째 줄에는 후위 표기식이 주어진다. 
    
    (여기서 피연산자는 A~Z의 영대문자이며, A부터 순서대로 N개의 영대문자만이 사용되며,
    
    길이는 100을 넘지 않는다) 
    
    그리고 셋째 줄부터 N+2번째 줄까지는 각 피연산자에 대응하는 값이 주어진다.
    
    3번째 줄에는 A에 해당하는 값, 4번째 줄에는 B에 해당하는값 ,
    
    5번째 줄에는 C ...이 주어진다, 
    
    그리고 피연산자에 대응 하는 값은 100보다 작거나 같은 자연수이다.

    후위 표기식을 앞에서부터 계산했을 때, 
    
    식의 결과와 중간 결과가 -20억보다 크거나 같고, 20억보다 작거나 같은 입력만 주어진다.

출력

    계산 결과를 소숫점 둘째 자리까지 출력한다.

예제 입력 1 

    5
    ABC*+DE/-
    1
    2
    3
    4
    5
    
예제 출력 1 

6.20

예제 입력 2 

1
AA+A+
1

예제 출력 2 

3.00

[ 풀 이 ]

    주어진 숫자와 표기식에 맞추어 알파뱃에 대응값을 사용하여 후위표기식으로 계산하고 
    
    출력하는 문제였습니다.
    
    문제의 입력값 순서는 
    
    1. 숫자(대응값)의 갯수  2. 후위표기법 3. 대응값 
    
    순서로 주어지지만 문제를 풀때는
    
    1 -> 3 -> 2 순으로 대응값을 찾은 뒤, 후위표기법에 맞추어 문제를 해결하는 순서로 진행했습니다.
    
    제가 생각한 풀이 알고리즘은 다음과 같습니다.
    
    1. 후위표기법을 string값으로 저장
    
    2. 주어진 대응값을 배열에 저장하기
    
    3. 후위표기법을 인덱스로 접근하며 알파뱃 일경우 double형으로 선언해 둔 배열에 값을 넣고
    
    배열의 인덱스르 증가시키고, 연산자이면 stack과 같은방식으로 Last input first out 방식으로
    
    double형 배열에서 숫자를 꺼내어 연산하고 다시 배열에 저장, 배열의 인덱스 조절을하여
    
    후위표기법에 따라 연산을 진행
    
    4. 나온 결과를 "소수 두번쨰 자리" 까지만 출력하는것이 문제의 조건이므로 
    
    cout 함수의 cout << fixed;	cout.precision(2); 함수를 통하여 cout에서 나오는
    
    값의 소수점 자리수를 조절하고 값을 출력
    
    ps/ 이 문제를  풀 때 가장 막힌부분은 cin으로 소수 둘 째자리까지 표현하는 것이였습니다.
    
    처음에는 왜 틀린지 모르고 방법을 찾아보다, 문제를 정독한 뒤 fixed, precision 함수를 찾아 사용하여
    
    문제를 해결할 수 있었습니다.
    
 [ 구 현 ]
 
    #include <iostream>
    #include <string>
    using namespace std;


    int num[27]; // 대응값 저장하는 배열
    string S; // 후위표기법 저장 string
    double stk[202]; // 후위표기법을 계산할 때 stack 처럼 사용할 double형 배열
    int idx = 0; // stk 배열에서 값 입력값의 위치를 정해주는 index 변수
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      int N;
      //freopen("Input.txt", "r", stdin);
      cin >> N >> S; 
      for (int a = 0; a < N; ++a) {
        cin >> num[a]; // 대응값을 저장하고
      }
      for (int a = 0; S[a]; ++a) {
        if (S[a] >= 65 && S[a] <= 90) { // 후위표기법의 현재 위치가 알파뱃이면
          stk[idx++] = num[S[a] - 65]; // stk에 값을 하나하나 저장
        }
        else { // 연산자면 
          if (S[a] == '*') {
            stk[idx - 2] = stk[idx - 2] * stk[idx - 1]; // idx는 값을 입력할 새로운 위치를 가리키므로
            // idx-1 = 마지막에 입력된 위치가 되므로 idx-2 와 idx-1 을 연산한 값을 idx-2 에 저장
            // idx-2 와 idx-1 을 사용하여 idx-2 에 저장했으므로 새로 입력하는 값은 idx-1에 해야하므로
            
            --idx; // 다음 입력 위치는 idx-1
          }
          else if (S[a] == '+') {
            stk[idx - 2] = stk[idx - 2] + stk[idx - 1];
            --idx;

          }
          else if (S[a] == '/') {
            stk[idx - 2] = stk[idx - 2] / stk[idx - 1];
            --idx;
          }
          else {
            stk[idx - 2] = stk[idx - 2] - stk[idx - 1];
            --idx;
          }
        }
      }
      cout << fixed;
      cout.precision(2);
      // 소수 둘쨰짜리까지만 
      cout<< stk[0];

      return 0;
    }
