#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;



int N;
char game;
int game_idx; // 게임 뭔지 구분용
int need_people[3] = { 1,2,3 }; // 게임 종류 별 필요 인원
int participant_cnt = 0; // 전체 참가자 수 카운팅
unordered_map<string, bool> participant; // 이름 중복없이 사용 위함 unordered_map
void Solve() {
    cout << participant_cnt / need_people[game_idx]; // 정답 출력
}
void Input() {
    cin >> N >> game;
    if (game == 'Y') { // 윳
        game_idx = 0;
    }
    else if (game == 'F') { // 그림 찾기
        game_idx = 1;
    }
    else {
        game_idx = 2; // 원카드
    }

    for (int a = 0; a < N; ++a) {
        string temp;
        cin >> temp;
        if (participant.count(temp) == 0) { // 중복된 참가자가 아니라면
            ++participant_cnt; // 참가자 +1
            participant[temp] = true; // 두번 카운팅 안되게 체크
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
