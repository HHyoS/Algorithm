문제 사이트 : https://www.acmicpc.net/problem/11655

문제 설명 :

    ROT13은 카이사르 암호의 일종으로 영어 알파벳을 13글자씩 밀어서 만든다.

    예를 들어, "Baekjoon Online Judge"를 ROT13으로 암호화하면
    
    "Onrxwbba Bayvar Whqtr"가 된다.
    
    ROT13으로 암호화한 내용을 원래 내용으로 바꾸려면 암호화한 문자열을 다시 ROT13하면 된다.
    
    앞에서 암호화한 문자열 "Onrxwbba Bayvar Whqtr"에 다시 
    
    ROT13을 적용하면 "Baekjoon Online Judge"가 된다.

    ROT13은 알파벳 대문자와 소문자에만 적용할 수 있다. 
    
    알파벳이 아닌 글자는 원래 글자 그대로 남아 있어야 한다. 
    
    예를 들어, "One is 1"을 ROT13으로 암호화하면 "Bar vf 1"이 된다.

    문자열이 주어졌을 때, "ROT13"으로 암호화한 다음 출력하는 프로그램을 작성하시오.

입력

    첫째 줄에 알파벳 대문자, 소문자, 공백, 숫자로만 이루어진 문자열 S가 주어진다. S의 길이는 100을 넘지 않는다.

출력

    첫째 줄에 S를 ROT13으로 암호화한 내용을 출력한다.

예제 입력 1 

    Baekjoon Online Judge

예제 출력 1 

    Onrxwbba Bayvar Whqtr

예제 입력 2 

    One is 1

예제 출력 2 

    Bar vf 1
    
[ 풀 이 ]

    문장 S가 주어졌을 때, 각 알파뱃을 주어진 조건 ROT13 에 맞추어 암호화하는 문제였습니다.
    
    제가 생각한 문제 해결 아이디어는 다음과 같습니다.
    
    ROT13은 각 알파뱃을 13칸씩 밀어서 암호화하는 문제이기떄문에
    
    아스키 코드를 기준으로 대문자는 65 ~ 90, 소문자는 97 ~ 122 의 범위를 갖는데
    
    대문자 65 ~ 77, 소문자 97 ~ 109 범위는 13을 더한값을 문장의 알파뱃에 변화를 주고
    
    대문자 78 ~ 90, 소문자 110 ~ 122 범위는 13을 더한 뒤 대문자는 91, 소문자는 123으로 나머지연산하여
    
    한바퀴를 도는것으로 생각하고, 대문자는 65, 소문자는 97를 더해주어 새로운 위치를 찾아
    
    암호화해주도록하여 문제를 해결하였습니다.
    
[ 구 현 ]

    #include <iostream>
    #include <string>
    using namespace std;

    string S;
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      //freopen("Input.txt", "r", stdin);
      getline(cin, S);
      for (int a = 0; S[a]; ++a) {
        if (S[a] >= 65 && S[a] <= 77) { // 대문자
          S[a] = S[a] + 13;
        }
        else if (S[a] >= 78 && S[a] <= 90) {
          S[a] = (S[a] + 13) % 91 + 65;
        }
        else if (S[a] >= 97 && S[a] <= 109) { // 소문자
          S[a] = S[a] + 13;;
        }
        else if (S[a] >= 110 && S[a] <= 122) {
          S[a] = (S[a] + 13) % 123 + 97;
        }
        else
          continue;
      }
      cout << S;
      return 0;
    }
