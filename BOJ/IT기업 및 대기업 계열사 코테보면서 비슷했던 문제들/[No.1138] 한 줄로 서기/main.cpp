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
