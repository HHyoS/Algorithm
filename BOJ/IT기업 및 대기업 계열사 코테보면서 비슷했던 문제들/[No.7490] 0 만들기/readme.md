문제 사이트 : https://www.acmicpc.net/problem/7490

문제 설명 :

![image](https://github.com/user-attachments/assets/90fae66d-06d5-4fce-8707-1b4adef457cb)

풀이 알고리즘

    주어진 조건에 맞게 0을 만드는 문제 0 만들기 입니다.

    주어진 N은 1부터 N까지의 수를 사용한다는 의미인데, 1 2 3 4 5 6 .. N까지
    각 숫자 사이에 '+' '-' ' ' 을 넣어서 결과로 0을 만들 수 있는 모든 케이스를 ASCI 순으로
    출력 해야합니다.

    문제 자체는 간단하지만 식을 만드는 것이 까다로운 문제인데, 제가 생각한 풀이는 다음과 같습니다.

    1) 숫자를 1부터 N까지(깊이가 1부터 N까지) 사용하는 DFS를 구현한다.
    2) DFS는 깊이가 깊어질 때, (깊이,전체 합, 임시 값, 이전에 사용한 연산( '+' '-' ' '')) 를 사용한다
    3) 다음의 과정을 수행한다
        3-1)이번에 사용할 연산이 '+' '-' 일 경우
        - 계산할 값 = 전체 합 + 이전 숫자 or 전체 합 - 이전 숫자 
        - 다음 DFS로 넘길 값 = (깊이+1,계산할 값, 임시 값(현재 깊이), 이번에 사용한 연산) 를 DFS로 넘긴다
        3-2) 이번에 사용할 연산지 ' ' 일 경우
        - 다음 DFS로 넘길 값 = (깊이+1,전체 합,임시 값*10+현재 깊이,이전에 사용한 연산) 을 넘긴다.
    4) 3의 과정 중 임시값과 이전 연산을 저장하는 연산 중 공백 연산이 존재하기 때문에
        공백 연산을 할 경우 임시값 *10 + 현재 깊이 를 해주어야 이후 연산에 사용할 수 있음
        이전 연산을 저장하는 이유는 임시값을 키우는 대신 연산을 진행할 때, 필요한 연산은
        새로운 연산이 임시값 앞에 존재하는 연산 이므로 저장해 두었다가 사용이 필요

풀이 코드

    #include <iostream>
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <queue>
    using namespace std;
    
    int T, N;
    vector<char> temp;
    void dfs(int nowNum,int result,int before_num,char last_cal) {
    
    
        if (nowNum == N+1) {
            if (before_num != 0) {
                if (last_cal == '+') {
                    result = result + before_num;
                }
                else {
                    result = result - before_num;
                }
            }
            if (result == 0) {
                int num = 1;
                cout << num++;
                for (int a = 0; a < temp.size(); ++a) {
                    cout << temp[a] << num++;
                }
                cout << "\n";
            }
            return;
        }
    
    
        temp.push_back(' ');
        dfs(nowNum + 1, result, before_num * 10 + nowNum, last_cal);
        temp.pop_back();
    
        if (last_cal == '+') {
            temp.push_back('+');
            dfs(nowNum + 1, result + before_num, nowNum, '+');
            temp.pop_back();
    
            temp.push_back('-');
            dfs(nowNum + 1, result + before_num, nowNum, '-');
            temp.pop_back();
        }
        else {
            temp.push_back('+');
            dfs(nowNum + 1, result - before_num, nowNum, '+'); // 3 , 3 
            temp.pop_back();
    
            temp.push_back('-');
            dfs(nowNum + 1, result - before_num, nowNum, '-');
            temp.pop_back();
        }
    
    }
    void Solve() {
    
        dfs(2, 0, 1,'+');
    
    }
    void Input() {
        cin >> T;
        for (int a = 0; a < T; ++a) {
            cin >> N;
            Solve();
            cout << "\n";
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

    구현력이 부족행..

![image](https://github.com/user-attachments/assets/f421d69f-d032-4175-9262-d0f2d7ecc19a)
