문제 사이트 : https://www.acmicpc.net/problem/10820

문제 설명 :

    문자열 N개가 주어진다. 
    
    이때, 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램을 작성하시오.

    각 문자열은 알파벳 소문자, 대문자, 숫자, 공백으로만 이루어져 있다.

입력

    첫째 줄부터 N번째 줄까지 문자열이 주어진다.
    
    (1 ≤ N ≤ 100) 문자열의 길이는 100을 넘지 않는다.

출력

    첫째 줄부터 N번째 줄까지 각각의 문자열에 대해서 소문자, 대문자, 
    
    숫자, 공백의 개수를 공백으로 구분해 출력한다.

예제 입력 1 

    This is String
    SPACE    1    SPACE
     S a M p L e I n P u T     
    0L1A2S3T4L5I6N7E8

예제 출력 1 

    10 2 0 2
    0 10 1 8
    5 6 0 16
    0 8 9 0
    
[ 풀 이 ]

  첫째 줄부터 N번째 줄까지 문자열 S가 주어질 떄, 각 줄마다 소문자, 대문자, 숫자, 공백의
  
  갯수를 확인하고 출력하는 문제였습니다.
  
  이 문제를 풀 떄 생각한 아이디어는 두가지였습니다.
  
      1. 한 줄씩 입력받는 함수를 찾아 사용하자.
  
      2. 출력 조건인 대문자, 소문자, 숫자, 공백는 아스키 코드로 표현되므로 아스키 코드를 사용하여
      조건들을 분류하자 
     
  조건 1을 만족하는 함수는 string.h 헤더에서 제공하는 getline함수로 한줄씩 입력받아 처리하는 함수이고
  
  조건 2는 대문자(65 ~ 90) 소문자(97~122) 숫자(48~57) 공백(32) 로 아스키코드를 사용하였고
  
  해당 조건에 따라 각 줄마다 line의 문자열들을 조건에 맞추어 갯수를 카운팅하고 출력하도록하여 
  
  문제를 해결하였습니다.
  
[ 구 현 ]

    #include <iostream>
    #include <string>
    using namespace std;

    string S;
    int alpha[26];
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      //freopen("Input.txt", "r", stdin);
      while (getline(cin,S)) { // while문에 getline을 조건으로 EOF를 입력받을 떄 while문이 종료
        int so = 0, dae = 0, space = 0, num = 0; // so = 소문자 . dae = 대문자, space = 공백, num = 숫자
        for (int a = 0; S[a]; ++a) { // S에 한 line이 담겨있고 line의 끝에 도달하면 for문 종료
          if (S[a] >= 65 && S[a] <= 90) { // 대문자
            ++dae;
          }
          else if (S[a] >= 97 && S[a] <= 122) { // 소문자
            ++so;
          }
          else if (S[a] >= 48 && S[a] <= 57) { // 숫자
            ++num;
          }
          else {
            ++space;
          }
        }
        cout << so << " " << dae << " " << num << " " << space << "\n"; 
        // 조건에 따라 나눠진  출력
      }
      return 0;
    }
