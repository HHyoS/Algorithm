문제 사이트 : https://www.acmicpc.net/problem/1373

풀이 환경 : Visual studio 2019

설명 : 

    2진수가 주어졌을 때, 8진수로 변환하는 프로그램을 작성하시오.

입력

    첫째 줄에 2진수가 주어진다. 주어지는 수의 길이는 1,000,000을 넘지 않는다.

출력

    첫째 줄에 주어진 수를 8진수로 변환하여 출력한다.

예제 입력 1 

    11001100

예제 출력 1 

    314
    
풀이 알고리즘

    2진수로 작성된 값을 8진수로 변경하여 출력하는 문제였습니다.
    
    2진수는 8진수로 변경하기위해 제가 생각한 방법은 다음과 같습니다.
    
    1) 2진수 -> 8진수 변환을 위해서 2진수 -> 10진수 -> 8진수 로 변환하는것은 비효율적이다.
    
    2) 2진수에서 8진수로 바로 변환하려면 2진수값을 세개씩 묶어서 변환시키면 8진수로 변환할 수 있다.
    
      ex) 2진수 - 111010001 일경우 (111) (010) (001) 로 나누어 변환하면 쉽게 변환가능
      
      변환할 떄 왼쪽부터 x[1]. x[2], x[3] 이라고 할 경우, x[1] = 4, x[2] = 2, x[3] = 1 로 
      
      자릿수 값을 설정하여 1 계산 (111) = 4*1 + 2*1 + 1*1, (010) = 4*0 + 2*1 + 1*0 
      
      (001) = 4*0 + 2*0 + 1*1 로 계산
      
      2진수 111 010 001 = (7)(2)(1) = 721(8진수)
    
구 현

    #include <iostream>
    #include <string>
    #include <queue>
    #include <stack>
    #include <algorithm>
    using namespace std;

    string N;
    string aanswer;
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      //freopen("Input.txt", "r", stdin);

      cin >> N;
	    stack<int> st; // 역순으로 출력해야 하므로 stack사용
      int leng = N.length();
      for (int a = N.length() - 1; a >= 0; --a) { // 주어진 2진수 오른쪽 끝부터 접근
        int num = 1;
        int answer = 0;
        for (int b = 0; b < 3; ++b) { // 한번에 세자리씩 처리하므로 2중for문으로 처리
          if (a < b)
            break;
          int temp = N[a - b] - 48; // char 값으로 입력받으므로 int값으로 변환
          answer = answer + num * temp;
          num *= 2;
        }
        a -= 2;
		    st.push(answer); // 구한 8진수 값을 stack에 저장하여 나중에 역순으로 출력
      }
	    while (!st.empty()) {
		    cout << st.top();
		    st.pop();
	    }
      return 0;
    }

개선점

  stack을 이용해서 출력할 경우 통과햇지만, string값으로 변수를 설정하고 매 순회마다 string에
  
  값을 더해가며 하는 방식으로 구현할 경우 시간초과가 발생.. 왜그런지 모르겟다...
