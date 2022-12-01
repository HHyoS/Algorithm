문제 사이트 : https://www.acmicpc.net/problem/2743

문제 설명 :

    알파벳으로만 이루어진 단어를 입력받아, 그 길이를 출력하는 프로그램을 작성하시오.

입력

    첫째 줄에 영어 소문자와 대문자로만 이루어진 단어가 주어진다. 단어의 길이는 최대 100이다.

출력

    첫째 줄에 입력으로 주어진 단어의 길이를 출력한다.

예제 입력 1 

    pulljima

예제 출력 1 

    8
    
[ 풀 이 ]

    문자열을 입력받아 길이를 출력하는 문제였습니다.
    
    문자열을 string 타입으로 입력받은 뒤, 해당 문자열의 길이를 출력하는 length() 함수를
   
    사용하여 길이를 출력하여 문제를 해결하였습니다.
    
    // 매우 간단한 문제이지만 문제집의 순서대로 문제풀이를 진행중이여서 업로드 하고있습니다. //
   
 [ 구 현 ]
 
    #include <iostream>
    #include <cstring>
    using namespace std;

    string S;
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      //freopen("Input.txt", "r", stdin);

      cin >> S;
      cout << S.length();
      return 0;
    }
