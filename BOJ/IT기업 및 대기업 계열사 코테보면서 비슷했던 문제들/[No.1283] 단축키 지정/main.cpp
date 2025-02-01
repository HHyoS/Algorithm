#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/1283
    문제 설명 :
        여러 문자열이 주어질 때, 조건에 맞게 옵션으로 설정이 가능한지 확인하고
        가능하다면 옵션에 해당하는 알파벳을 [ ] 로 감싸는 문제 '단축키 지정'입니다.

        문제의 조건이 굉장히 심플하고 문자열의 길이들도 짧기 때문에 파싱만 할 줄 알다면
        풀이가 가능한 문제였습니다.

        문제의 조건대로 1) 공백 기준 앞의 알파뱃 확인 2) 안된다면 입력된 문자열 전체를
        탐색하며 옵션으로 설정 가능한 알파뱃 확인 3) 모두 안된다면 그냥 출력

        세 가지에 대해 파싱 구현 진행하였고, 특이사항 없이 풀이 완료 되었습니다.
    */

int N;
bool option[27]; // 옵션 지정 여부 확인


// 옵션 지정 여부 확인하여 가능하다면 사용처리 후 true return
bool checker(char temp) {
    if (temp >= 'A' && temp <= 'Z') {
        if (option[temp - 'A'] == 0) {
            option[temp - 'A'] = 1;
            return true;
        }
    }
    else if (temp >= 'a' && temp <= 'z'){
        if (option[temp - 'a'] == 0) {
            option[temp - 'a'] = 1;
            return true;
        }
    }

    return false;
}


string Solve(string temp) {
    string ans;
    // 1-1) 첫 알파벳 체크하여 옵션 가능 여부 확인
    if (checker(temp[0])) {
        ans = "[" + temp.substr(0, 1) + "]" + temp.substr(1);
        return ans;
    }

    // 1-2)공백 기준 뒤의 알파뱃 확인하여 옵션 가능 여부 확인
    for (int a = 1; a < temp.size(); ++a) {
        if (temp[a-1] == ' ' && temp[a] != ' ') {
            if (checker(temp[a])){
                ans = temp.substr(0,a)+"[" + temp.substr(a,1) + "]" + temp.substr(a+1);
                return ans;
            }
        }
    }

    // 2) 전체 탐색하며 옵션 지정 가능 여부 확인
    for (int a = 1; a < temp.size(); ++a) {
        if (temp[a] != ' ') {
            if (checker(temp[a])) {
                ans = temp.substr(0, a ) + "[" + temp.substr(a, 1) + "]" + temp.substr(a + 1);
                return ans;
            }
        }
    }

    // 3) 안된다면 그냥 출력
    ans = temp;
    return ans;
}
void Input() {

    // cin은 개행문자가 버퍼에 남아서 getline시 포함되므로 ignore로 처리하기 
    cin >> N;
    cin.ignore();

    // 공백 포함 입력 받기
    for (int a = 0; a < N; ++a) {
        string temp;
        getline(cin, temp);
        cout << Solve(temp) << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    return 0;
}
