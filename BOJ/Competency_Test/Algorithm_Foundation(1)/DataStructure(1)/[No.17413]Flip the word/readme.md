문제 사이트 : https://www.acmicpc.net/problem/17413

문제 설명 :


    문자열 S가 주어졌을 때, 이 문자열에서 단어만 뒤집으려고 한다.

    먼저, 문자열 S는 아래와과 같은 규칙을 지킨다.

    알파벳 소문자('a'-'z'), 숫자('0'-'9'), 공백(' '), 특수 문자('<', '>')로만 이루어져 있다.
    
    문자열의 시작과 끝은 공백이 아니다.
    
    '<'와 '>'가 문자열에 있는 경우 번갈아가면서 등장하며, '<'이 먼저 등장한다. 
    
    또, 두 문자의 개수는 같다.
    
    태그는 '<'로 시작해서 '>'로 끝나는 길이가 3 이상인 부분 문자열이고, 
    
    '<'와 '>' 사이에는 알파벳 소문자와 공백만 있다.
    
    단어는 알파벳 소문자와 숫자로 이루어진 부분 문자열이고,
    
    연속하는 두 단어는 공백 하나로 구분한다. 
    
    태그는 단어가 아니며, 태그와 단어 사이에는 공백이 없다.

입력

    첫째 줄에 문자열 S가 주어진다. S의 길이는 100,000 이하이다.

출력

    첫째 줄에 문자열 S의 단어를 뒤집어서 출력한다.
    
    
예제 입력 1 

    baekjoon online judge

예제 출력 1 

    noojkeab enilno egduj

예제 입력 2 

    <open>tag<close>
  
예제 출력 2 
  
    <open>gat<close>
  
예제 입력 3 
  
    <ab cd>ef gh<ij kl>
  
예제 출력 3 
  
    <ab cd>fe hg<ij kl>
  
예제 입력 4 
  
    one1 two2 three3 4fourr 5five 6six
  
예제 출력 4 
  
    1eno 2owt 3eerht rruof4 evif5 xis6
  
예제 입력 5 
  
    <int><max>2147483647<long long><max>9223372036854775807
  
예제 출력 5 

    <int><max>7463847412<long long><max>7085774586302733229
  
예제 입력 6 

    <problem>17413<is hardest>problem ever<end>
  
예제 출력 6 

    <problem>31471<is hardest>melborp reve<end>
  
예제 입력 7 

    <   space   >space space space<    spa   c e>
  
예제 출력 7 

    <   space   >ecaps ecaps ecaps<    spa   c e>
  
[ 풀이 알고리즘 ]

    주어진 문장을 조건에 맞추어 부분적으로 뒤집고 새로운 문장을 만드는 문제였습니다.
    
    해당 문제에서 발생할 수 있는 상황은 다음과 같습니다.
    
    1. '<' 시작 '>' 종료
    
    2. '알파뱃' ~'알파뱃' + '스페이스' or '<'
   
   
     1번 케이스는 '<' ~ '>' 까지의 단어들을 모두 그대로 보존하므로 '<' 시작부터 '>' 까지 생략하면 됩니다.

     2번 케이스는 '알파뱃' ~'알파뱃' 부분은 뒤집고, ' ' or '<' 시작부터는 뒤집지 않아야하므로

       2번케이스를 진행하며 다음칸에 '<' 혹은 ' '가 존재하는지 확인하고,
       
       존재할경우 이전위치까지만 뒤집기를 실행하면 문제가 해결됩니다.

    
    
[ 구 현 ]

    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <queue>
    #include <utility>

    using namespace std;
    string S;
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

      //freopen("Input.txt","r", stdin);

        getline(cin, S);
        for (int a = 0; S[a]; ++a) {
            if (S[a] == '<') { // 현재 인덱스의 값이 '<'라면
                ++a;
                while (S[a] != '>') // S[a] 가 '>'를 나타낼때까지 인덱스 증가
                    ++a;
            }
            else if (S[a] == ' ') // S[a]가 공란이라면 다음칸으로 이동
                continue;
            else { // 알파뱃이라면
                int left = a; // 시작위치를 체크해두고
                while ((S[a + 1] != '<') && (S[a+1] != ' ') && (a+1 < S.length())){
                    ++a;
                } // S[a+1]의 값이 '<' or ' ' 가 되거나, a+1의 값이 문장의 끝 전까지 인덱스 증가
                reverse(S.begin() + left, S.begin() + a+1);
                // reverse함수는 위치를 나태날 때 값을 1 더 넣어줘야지 원하는대로 동작하므로
               // S[left] 부터 S[a] 까지 단어를 뒤집고 싶다면
               // reverse(s.begin() + left, S.begin() + a + 1)
            
            }
        }
        cout << S; // for문이 종료되면 문장이 모두 뒤집힌 상태이므로 cout << S로 답 
      return 0;

    }
