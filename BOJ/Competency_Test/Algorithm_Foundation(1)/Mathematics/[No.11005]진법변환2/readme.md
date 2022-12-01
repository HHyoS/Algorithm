문제 사이트 : https://www.acmicpc.net/problem/11005

풀이 환경 : Visual Studio 2019

설 명 : 

    10진법 수 N이 주어진다. 
    
    이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.

    10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다.
    
    이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.

    A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

입력

    첫째 줄에 N과 B가 주어진다. 
    
    (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.

출력

    첫째 줄에 10진법 수 N을 B진법으로 출력한다.

예제 입력 1

    60466175 36

예제 출력 1 

    ZZZZZ
    
풀이 알고리즘

    10진법의 수 N 과 진법을 나타내는 수 B가 주어졌을 때, N을 B진법 수로 치환하여 출력하는 문제였습니다.
    
    이 문제를 풀기위해 생각한 방법은 다음과 같습니다.
    
    1. B의 제곱수 중 N을 나누었을 떄 0이 나오지 않는 가장 큰 수( gop )를 찾는다.
    
    2. 가장 큰 수를 찾은 이후에는 다음과 같은 사이클을 진행합니다.
    
        (1) N을 gop으로 나누어 몫과 나머지를 구한다
        
        (2) 몫은 정답을 저장하는 string 변수인 answer = answer + 몫 연산을 통해 연산한다
            - 몫이 10 이상일 경우 ASCII 코드표를 이용하여 몫에 55를 더해준 뒤 char형으로 변환하여 문자열(A to Z)로 바꾸고 answer 에 더해주고
              아닐 경우 answer에 to_string 함수를 이용하여 더해준다.
              
        (3) gop의 값을 B로 나눈 뒤 B가 0보다 크다면, N의 값에 구한 나머지를 저장하고 다시 (1) 단계로 돌아간다.
        
구 현

    #include <iostream>
    #include <string>
    #include <queue>
    #include <algorithm>
    using namespace std;

    long long N;
    int B;
    string answer;
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      freopen("Input.txt", "r", stdin);

      cin >> N >> B;
      
      long long gop = 1;
      
      while (1) { // B의 제곱 수 중 N보다 작은 가장 큰 제곱수 찾기
        gop *= B;
        if (N / gop == 0) {
          gop /= B;
          break;
        }
      }
      while (gop > 0) { // N을 나누는 제곱수 gop이 0보다 클 떄(제곱수 이므로 최소값은 1이여야함)
        char t;
        if (N / gop >= 10) { // 몫이 10보다 크다면 A to Z 로 치환
          t = N / gop + 55;
          answer += t;
        }
        else { // 아니라면 answer에 더해주기
          answer += to_string(N / gop);
        }
        N %= gop; // N의 값에 gop으로 나눈 나머지를 넣어주고
        gop /= B; // gop의 값은 B로 나누어 이전 단계의 제곱수 
      }
      cout << answer;
      return 0;
    }
