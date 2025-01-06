문제 사이트 : https://www.acmicpc.net/problem/25757

문제 설명 :

    임스가 미니게임을 같이할 사람을 찾고 있습니다.
    
    플레이할 미니게임으로는 윷놀이 
    $Y$, 같은 그림 찾기     $F$, 원카드     $O$가 있습니다.
    
    각각 2, 3, 4 명이서 플레이하는 게임이며 
    
    인원수가 부족하면 게임을 시작할 수 없습니다.

    사람들이 임스와 같이 플레이하기를 신청한 횟수 N과 임스가 플레이할 게임의 종류가 주어질 때,
    
    최대 몇 번이나 임스와 함께 게임을 플레이할 수 있는지 구하시오.

    임스와 여러 번 미니게임을 플레이하고자 하는 사람이 있으나,
    
    임스는 한 번 같이 플레이한 사람과는 다시 플레이하지 않습니다.
    
    임스와 함께 플레이하고자 하는 사람 중 동명이인은 존재하지 않습니다. 
    
    임스와 lms0806은 서로 다른 인물입니다.

입력

    첫 번째 줄에는 사람들이 임스와 같이 플레이하기를 신청한 횟수 
    N과 같이 플레이할 게임의 종류가 주어진다. 
    1 <= N <= 100,000

    두 번째 줄부터 N개의 줄에는 같이 플레이하고자 
    
    하는 사람들의 이름이 문자열로 주어진다. 

        1 <= 문자열 길이 <= 20

    사람들의 이름은 숫자 또는 영문 대소문자로 구성되어 있다.

출력

    임스가 최대로 몇 번이나 게임을 플레이할 수 있는지 구하시오.

예제 입력 1 

    7 Y
    lms0806
    lms0806
    exponentiale
    lms0806
    jthis
    lms0806
    leo020630

예제 출력 1 

    4

예제 입력 2 

    12 F
    lms0806
    powergee
    skeep194
    lms0806
    tony9402
    lms0806
    wider93
    lms0806
    mageek2guanaah
    lms0806
    jthis
    lms0806

예제 출력 2 

    3

예제 입력 3 

    12 O
    lms0806
    mageek2guanaah
    jthis
    lms0806
    exponentiale
    lms0806
    leo020630
    lms0806
    powergee
    lms0806
    skeep194
    lms0806

예제 출력 3 
    
    2

풀이 알고리즘

    주어진 입력 값을 바탕으로 몇번 게임을 진행할 수 있는지 출력하는 문제 '임께임' 입니다.

    문제에서 요구하는 알고리즘 역량을 중복된 string을 체크할 수 있는 자료구조 사용 가능

    여부 인것으로 보이며, 저는 unoredered_map 구조체를 사용하여 풀이 진행하였습니다.

    자료구조만 안다면 쉽게 풀 수 있는 문제로, 입력된 참가자의 이름을
    
    unordered_map 구조체에 넣은 뒤 처음 나왔다면 참가자 수를 증가시키고, 아니라면 스킵!

    위 과정을 통해 진짜 참가자의 수를 구할 수 있었고, 
    
    이 값을 바탕으로 (전체 참가자 / 필요 인원-1) 을 출력하여 문제 풀이 완료하였습니다.

    -1인 이유는 임스는 계속 참가하기 때문에 -1을 해주어야 합니다.

풀이 코드

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

풀이 후기

    자료구조를 알고 있는지 체크하는 문제로, 난이도 대비 매우 쉬움.

![image](https://github.com/user-attachments/assets/a2f5f170-6ab2-4885-9f12-181d3ec7e652)
