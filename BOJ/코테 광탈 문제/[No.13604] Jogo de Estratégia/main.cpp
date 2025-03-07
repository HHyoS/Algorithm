#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/13604
    문제 설명 : 
        N명의 참가자가 R라운드 동안 게임을 진행한다.
        각 라운드별로 참가자가 획득하는 점수(0-100점)가 주어질 때, 획득한 점수의 합이 최대인
        참가자를 출력하자.
        만약 동점인 참가자가 둘 이상 있다면 참가 번호가 가장 늦은 사람(참가 번호는 점수를 얻는 순서를 의미)를 출력하자
        ex) 3명이 게임을 진행하고 2라운드라면 1 2 3 4 5 6 이라는 점수가 주어진다
        이때, 참가번호 () 는 참가번호 1번, [] 는 2번 {}는 3번 참가자를 의미 (1) [2] {3} (4) [5] {6}

        브론즈답게 매우 쉬운 문제 Jogo de Estratégia(전략) 입니다.
        참가자의 최대 인원인 500 크기의 배열을 선언한 뒤, R*N의 2중 for문으로 입력받아 각 참가자의 번호에 해당하는 배열
        인덱스에 점수를 더해 나갑니다.

        마지막에 참가자 중 최대 점수의 참가자를 찾아 최대 점수와 최대 점수 참가자 번호를 갱신하고, 같은 값이 있다면 참가 번호가 늦은
        참가자의 번호로 갱신해주면 쉽게 풀이됩니다.

   
      */
int N,R;
int player[510]; // 참가자 점수 배열
void Solve() {
    int ans = 0;
    int max_point = -1;
    for (int a = 0; a < N; ++a) {
        if (player[a] >= max_point) { // 현재 참가자가 최대 점수보다 크거나 같다면
            ans = a; // 해당 참가자는 앞 참가자보다 무조건 뒤의 번호를 가지고 있으므로 바꿔주고
            max_point = player[a]; // 최대 점수도 바꿔주기
        }
    }
    cout << ans + 1; // 내 인덱스는 0에서 시작하므로 +1
}


void Input() {
    cin >> N >> R;
    
    // N명의 참가자에 대한 정보가 R라운드 동안 반복되므로 R*N 2중 for문으로 입력받기
    for (int a = 0; a < R; ++a) {
        for (int b = 0; b < N; ++b) {
            int point;
            cin >> point;
            player[b] += point;
        }
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
