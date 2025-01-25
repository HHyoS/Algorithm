문제 사이트 : https://www.acmicpc.net/problem/1138

문제 설명 :

![image](https://github.com/user-attachments/assets/e9aa20ba-eb65-4854-9856-dd6ff072e67e)
![image](https://github.com/user-attachments/assets/573e67a6-d4e8-4962-843b-f273a38e5121)

풀이 알고리즘

    주어진 조건대로 N명을 사람을 줄 세우고, 세운 줄에 존재하는 사람들의 키를 출력하는 문제

    '한 줄로 서기' 입니다.

    문제의 조건을 만족하는지 모든 케이스에 대해 조건을 거는 것을 매우 힘들고, 모든 케이스를

    확인하는 것도 어렵지만, N의 크기가 10 이므로 BrueteForce로 진행한다고 하더라도

    연산 횟수가 3,628,800회 내에 정리가 될 수 있습니다.

    풀이 방법은 아래와 같습니다.

    1) DFS를 사용하여 N! 에 해당하는 경우의 수를 모두 줄 세워보자
    2) 줄이 세워졋다면, 줄 서기 규칙에 따라 줄이 세워졌는지 확인한다
    3-1) 줄이 세워지지 않았다면 DFS를 계속 진행하며 정답을 찾고
    3-2) 세워진 줄이 규칙에 부합하다면 세워진 줄을 출력하고, 다른 DFS가 돌지 않도록 
    설정하여 프로그램을 종료.

풀이 코드

    #include <iostream>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;
    
    /*
        문제 사이트 : https://www.acmicpc.net/problem/1138
        문제 설명 :
            주어진 조건을 만족하는 줄서기를 만들어보자
            N의 크기가 10이므로 굉장히 작다.
            N!을 하더라도 연산 횟수는 3,628,800로 작다
            Brute Force로 구현해보자
    */
    
    int N;
    bool checker[11];
    int rule[11];
    int line[11];
    bool answer_checker;
    
    // 주어진 룰대로 줄을 섰는지 체크
    bool is_answer() {
        for(int a = 0; a < N; ++a) {
            
            int cnt = 0;
            for (int b = 0; b < a; ++b) {
                if (line[a] < line[b]) {
                    ++cnt;
                }
            }
            if (cnt != rule[line[a]]) {
                return false;
            }
        }
        
        return true;
    }
    
    // 모든 경우의 수에 대해 줄을 일단 세워보자
    void dfs(int deep) {
        if (deep == N) {
            answer_checker = is_answer();
            if (answer_checker) {
                int answer[11] = { 0, };
                for (int a = 0; a < N; ++a) {
                    answer[a] = line[a]+1;
                }
                for (int a = 0; a < N; ++a) {
                    cout << answer[a] << " ";
                }
            }
            return;
        }
    
    
        // 그래도 반복은 불필요하니까 빼주고
        for (int a = 0; a < N; ++a) {
            if (answer_checker == true)
                return;
    
            if (checker[a] == true) continue;
    
            checker[a] = true;
            line[deep] = a;
            dfs(deep + 1);
            checker[a] = false;
        }
    }
    void Solve() {
    
        for (int a = 0; a < N; ++a) {
            checker[a] = true;
            line[0] = a;
            dfs(1);
            checker[a] = false;
        }
        
    }
    void Input() {
        cin >> N;
        for (int a = 0; a < N; ++a) {
            cin >> rule[a];
        }
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
        Solve();
        return 0;
    }

오늘의 일기

    설날의 고속도로는 지옥이다

![image](https://github.com/user-attachments/assets/e11678bd-1461-4ead-8fb8-9b69ad078cb6)
