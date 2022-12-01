문제 사이트 : https://www.acmicpc.net/problem/1212

풀이 환경 : visual studio 2019

설명 : 

    8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.

입력

    첫째 줄에 8진수가 주어진다. 
    
    주어지는 수의 길이는 333,334을 넘지 않는다.

출력

    첫째 줄에 주어진 수를 2진수로 변환하여 출력한다. 
    
    수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.

예제 입력 1 

    314

예제 출력 1 

    11001100
    
풀이 알고리즘

    이전에 풀었던 2진수 8진수(https://url.kr/ngu9po) 를 역으로 8진수에서 2진수로 변환하는 문제입니다.
    
    2진수에서 8진수로 갈 때, 2진수 세자리가 8진수 한자리가 되는것을 역으로
    
    8진수 한자리가 2진수 세자리가 되도록 하는 문제입니다.
    
    이 방식을 구현하기 위해 8진수 값 N을 입력받아 N의 각 자리값을 4, 2 , 1 로 나누어 나온 몫을
    
    자리값으로 갖는 세자리의 이진수를 구하고, 해당 값들을 연속해서 출력하는 것으로 문제를
    
    해결하였습니다. 
    
    ex) 8진수 = 7 일경우, 처음에는 4로 나누면 7 /4 = [ 1 ] 이 되고, 
    
    7 /4의 나머지인 7 % 4= { 3 } , 그 후 3을 2로 나누어서 3 /2 = [ 1 ], 3 % 2 = { 1 }, 
    
    다음 1 / 1 = [ 1 ]  을 하여 [ 1 ] [ 1 ] [ 1 ] 이 답이됩니다.
    
구 현

    #include <iostream>
    #include <string>
    #include <queue>
    #include <stack>
    #include <algorithm>
    using namespace std;

    string N;
    char answer[1000005];
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      freopen("Input.txt", "r", stdin);

      cin >> N;
      int idx = 0;
      for (int a = 0; a < N.length(); ++a) {
        int fal = 4;
        int num = N[a] -'0';
        while (fal != 0) {
          answer[idx++] = num / fal + '0';
          num %= fal;
          fal /= 2;
        }

      }
      int start = 0;
      while (answer[start] == '0' && start < idx) { // 입력값이 0 일 경우에는
        ++start;
      }
      if (idx == start) // idx와 start의 값이 같아지므로 0 출력 후 
        cout << 0;
      else {
        for (int a = start; a < idx; ++a) {
          cout << answer[a];
        }
      }
      return 0;
    }
