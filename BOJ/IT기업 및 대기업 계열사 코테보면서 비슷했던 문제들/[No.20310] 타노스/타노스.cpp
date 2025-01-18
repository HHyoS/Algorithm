#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <string>
using namespace std;

/*
    짝수개의 0과 1로 이루어진 문자열이 주어질 때, 타노스의 힘으로
    0과 1의 개수를 절반으로 줄여 가장 작은 이진수를 만들어보자
    
    아이디어만 있다면 쉬운 문제로, 
    1) 0은 왼쪽에 있으면 어떤 의미도 주지 않지만 오른쪽에 있다면 자리수가 늘어남.
    2) 1은 왼쪽에 있을 수록 더 큰 의미를 가짐
    
    따라서 0은 오른쪽 부터 지우고, 1은 왼쪽부터 지운다.
    
    그 이후 지운 숫자를 제외한 문자열을 다시 모아서 출력하면 끝
    
*/
string S;
bool checker[510];
string Solve() {
    int zero_cnt = 0;
    int one_cnt = 0;

    // 0과 1이 몇개인지 체크해서 지워야할 개수를 확인하자
    for (int a = 0; a < S.size(); ++a) {
        if (S[a] == '0') {
            ++zero_cnt;
        }
        else {
            ++one_cnt;
        }
    }
    int sz = S.size() - 1;
    // 나는 타노스니까 절반만 지워
    zero_cnt /= 2;
    one_cnt /= 2;


    // 0과 1은 짝수개 이므로 없는 케이스는 생각하지 않아도 된다.
    // 1은 왼쪽에 있을수록 숫자가 커지므로 지우자.
    for (int a = 0; a <= sz; ++a) {
        if (S[a] == '1') {
            checker[a] = 1;
            --one_cnt;
            if (one_cnt == 0)
                break;
        }
    }

    // 0은 오른쪽에 있을 수록 숫자가 커지므로 지우자
    for (int a = sz; a >= 0; --a) {
        if (S[a] == '0') {
            checker[a] = 1;
            --zero_cnt;
            if (zero_cnt == 0) {
                break;
            }
        }
    }
    string ans = "";
    // 지워진 것 빼고 모아모아
    for (int a = 0; a <= sz; ++a) {
        if (checker[a] == 0) {
            ans = ans + S[a];
        }
    }
    // 정답 출력
    return ans;
}

void Input() {
    cin >> S;
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    cout << Solve();
    return 0;
}
