#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/9935
    문제 설명 : 
        문제에서 주어지는 문자열 폭발을 진행할 때, 마지막에 남는 문자열을 출력하는 문제 '문자열 폭발' 입니다.
        문제 자체는 쉽게 정리가 가능하지만 불필요한 연산과 메모리 할당에 대해 잘 알아야 하는 문제였습니다.
        문제에서 생각해야 하는 점은 두가지로 1) 탐색 위치 2) 메모리 할당 입니다.
        1) 문자열 폭발을 생각하여 0번 인덱스부터 탐색을 시작할 경우 불필요한 연산이 계속 발생하여 시간 초과가 발생할 수 있기 때문에
        기본 문자를 하나씩 입력받고 폭발 인덱스의 길이보가 커질 경우 뒤에서부터 문자를 비교하여 진행해야 시간초과가 발생하지 않습니다.
        2) string 타입으로 문제 풀이를 진행할 경우 문자열을 어떻게 파싱하든 메모리를 새로 할당하는 동작이 반복됩니다.
        이로인해 메모리 할당의 시간이 추가로 진행되어 배열 형태의 데이터 타입을 사용하여 삭제되지 않는 문자는
        그대로 유지하고, 폭발로 인해 없어지는 문자만 제거하는 방식으로 진행해야 됩니다.


      */

int N;

string S;
string boom;
void Solve() {
    int ans = 0;

    // 폭발을 위한 vector, String으로 선언할 경우 substr로 해도 메모리 할당이 진행되어
    // 시간 초과가 발생할 수 있음.
    vector<char> tS;
    int leng = boom.length();
    int idx = 0;

    // 문자를 하나씩 넣어가며 진행하기
    for (int a = 0; a < S.length(); ++a) {
        tS.push_back(S[a]);
        int tLeng = tS.size()-1;

        // 폭발 문자열보다 길이가 길 경우
        if (tS.size() >= leng) {
            bool flag = false;
            // 뒤에서부터 시작해서 폭발 문자열과 비교하고
            for (int b = 0; b < leng; ++b) {

                // 하나라도 다를 경우 폭발 불가능 flag 체크
                if (tS[tLeng - b] != boom[leng - 1 - b]) {
                    flag = true;
                    break;
                }
            }

            // 모두 같을 경우 pop하여 폭발해주기
            if (flag == false) {
                for (int b = 0; b < leng; ++b) {
                    tS.pop_back();
                }
            }
        }
    }
    // 정답 출력
    if (tS.size() == 0) {
        cout << "FRULA";
    }
    else {
        for (int a = 0; a < tS.size(); ++a) {
            cout << tS[a];
        }
    }
}
void Input() {
    cin >> S >> boom;
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
