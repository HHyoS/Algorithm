#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
    문제 사이트 :https://www.acmicpc.net/problem/12919
    문제 설명 :
        시작 단어 A와 목적 단어 B가 주어지고, 문자열을 추가하는 두가지 연산이 주어질 때
        A를 이용하여 B를 만들 수 있는지 확인하는 문제 'A와 B 2'입니다.

        단순하게 A를 이용하여 B를 만들 경우 어떤 단계를 거쳐 B가 만들어졌는지 알기 어렵습니다.

        따라서 최종 결과물인 B를 활용하여 가능한 연산에 대해서만 역방향 시뮬레이션을 진행하고
        A와 단어 길이가 같아졌을 때, 두 단어가 같은 단어인지 확인하여 풀이 완료 하였습니다.
    */

string origin;
string target;
bool checker = false;
void dfs(string temp,bool arrow) {

    // 시작 단어와 길이가 같아졌을 때
    if (temp.size() == origin.size()) {
        if (arrow == 1) { // 역방향이면 함 뒤집어 주고
            reverse(temp.begin(), temp.end());
        }

        // 두개가 같은 단어인지 확인
        if (temp == origin) {
            checker = true;
        }
        return;
    }

    // 역방향 이라면
    if (arrow == true) {
        if (temp.back() == 'B' && checker == false) {
            dfs(temp.substr(0,temp.size()-1), !arrow);
        }

        if (temp[0] == 'A' && checker == false) {
            dfs(temp.substr(1), arrow);
        }
    }
    // 정방향 이라면
    else {
        if (temp[0] == 'B' && checker == false) {
            dfs(temp.substr(1), !arrow);
        }
        if (temp.back() == 'A' && checker == false) {
            dfs(temp.substr(0, temp.size() - 1), arrow);
        }
    }
}

void Solve() {

    // 마지막 단계 to 처음 단계로 가는 역방향으로 시뮬레이션 진행
    // A를 추가하는 연산이라면 정방향, B를 추가하는 연산은 string을 뒤집어야함
    // 하지만 계속 뒤집으면 복잡도가 발생하므로 
    // dfs인자에 방향에 해당하는 매개변수를 추가하여 불필요 연산 제거
    // 연산되는 두 가지 케이스 중, 가능한 케이스에 대해서만 시뮬레이션 진행 
    if (target[0] == 'B') { // 맨 앞에 B가 있다면, 이전 단계에서 B를 추가하고 스왑하는 연산이 있었을 수 있음
        dfs(target.substr(1), 1);
    }
    if (target.back() == 'A') { // 맨 뒤에 A가 있었다면 A를 추가하는 연산이 있었을 수 있음
        dfs(target.substr(0, target.size() - 1),0);
    }

    if (checker == false) {
        cout << "0";
    }
    else {
        cout << "1";
    }
}
void Input() {
    cin >> origin >> target;
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
