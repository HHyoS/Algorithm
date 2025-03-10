문제 사이트 : https://www.acmicpc.net/problem/4659

문제 설명 :

    좋은 패스워드를 만드는것은 어려운 일이다. 대부분의 사용자들은 
    
    buddy처럼 발음하기 좋고 기억하기 쉬운 패스워드를 원하나,
    
    이런 패스워드들은 보안의 문제가 발생한다.
    
    어떤 사이트들은 xvtpzyo 같은 비밀번호를 무작위로 부여해 주기도 하지만, 
    
    사용자들은 이를 외우는데 어려움을 느끼고 심지어는 포스트잇에 적어 컴퓨터에 붙여놓는다. 
    
    가장 이상적인 해결법은 '발음이 가능한' 패스워드를 만드는 것으로
    
    적당히 외우기 쉬우면서도 안전하게 계정을 지킬 수 있다. 
    
    회사 FnordCom은 그런 패스워드 생성기를 만들려고 계획중이다. 
    
    당신은 그 회사 품질 관리 부서의 직원으로 생성기를 테스트해보고 
    
    생성되는 패스워드의 품질을 평가하여야 한다. 
    
    높은 품질을 가진 비밀번호의 조건은 다음과 같다.

        모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
        모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
        같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
        이 규칙은 완벽하지 않다;우리에게 친숙하거나 발음이 쉬운
        단어 중에서도 품질이 낮게 평가되는 경우가 많이 있다.
        
입력
      
    입력은 여러개의 테스트 케이스로 이루어져 있다.
    
    각 테스트 케이스는 한 줄로 이루어져 있으며, 
    
    각 줄에 테스트할 패스워드가 주어진다.
    
    마지막 테스트 케이스는 end이며, 패스워드는 한글자 이상 20글자 이하의 문자열이다. 
    
    또한 패스워드는 대문자를 포함하지 않는다.

출력

    각 테스트 케이스를 '예제 출력'의 형태에 기반하여 품질을 평가하여라.

예제 입력 1 

    a
    tv
    ptoui
    bontres
    zoggax
    wiinq
    eep
    houctuh
    end

예제 출력 1 

    <a> is acceptable.
    <tv> is not acceptable.
    <ptoui> is not acceptable.
    <bontres> is not acceptable.
    <zoggax> is not acceptable.
    <wiinq> is not acceptable.
    <eep> is acceptable.
    <houctuh> is acceptable.

풀이 알고리즘

    주어진 조건에 맞는 좋은 비밀번호를 판단하는 문제 '비밀번호 발음하기' 입니다.

    문제에서 주어진 조건대로 구현하면 되는 문제로 구현시 분류해야하는 조건은 아래와 같습니다.

    1) 모음이 한개 이상 포함되는지 확인
    2) 모음 혹은 자음이 세개 연속 불가능
    3) 모든 글자는 연속해서 두 번 올 수 없지만, e와 o는 두 번 까지 가능

    위의 조건을 그대로 구현하면 풀이가 가능한 문제였습니다.

    문제를 정독하지 않아서 마지막 조건을 잘못 구현했었는데, 해당 부분 수정 후 pass 되었습니다.

풀이 코드

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    using namespace std;
    
    
    
    
    bool judge_aeiou(char input_char) {
        if (input_char == 'a' || input_char == 'e' || input_char == 'i' || input_char == 'o' || input_char == 'u') {
            return 1;
        }
        return 0;
    }
    bool Solve(string temp) {
        
        int size = temp.size();
        int char_cnt = 1;
        bool aeiou_used = false;
        bool before_aeiou = false;
        if (judge_aeiou(temp[0])) {
            aeiou_used = true;;
            before_aeiou = true;
        }
        for (int a = 1; a < size; ++a) {
            if (judge_aeiou(temp[a])) // 모음 사용 체크
                aeiou_used = true;
    
            if (temp[a-1] == temp[a]) { // 같은 모음 / 자음 체크
                ++char_cnt;
                if (char_cnt == 2) { // 두번 반복일 때 
                    if (temp[a] == 'e' || temp[a] == 'o') { // e와 o는 ok
                        continue;
                    }
                    else { // 아니면 불가능
                        return 0;
                    }
                }
                else if (char_cnt == 3) { // 세번은 모두 불가능
                    return 0;
                }
            }
            else {
                bool now_aeiou = judge_aeiou(temp[a]);
                if (now_aeiou == before_aeiou) {
                    ++char_cnt;
                    if (char_cnt == 3) // 모음 또는 자음이 세번 나옴
                        return 0;
                }
                else {
                    char_cnt = 1;
                    before_aeiou = now_aeiou;
                }
            }
        }
        if (aeiou_used)
            return 1;
        else
            return 0;
    }
    void Input() {
        string temp;
        while (1) {
            cin >> temp;
            if (temp == "end")
                break;
    
            if (Solve(temp)) {
                cout << "<" << temp << "> is acceptable.\n";
            }
            else {
                cout << "<" << temp << "> is not acceptable.\n";
            }
        }
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
    
    
        return 0;
    }

풀이 후기

    문제를 잘 읽자
![image](https://github.com/user-attachments/assets/5129daf3-f997-4563-8700-577ac100a746)
