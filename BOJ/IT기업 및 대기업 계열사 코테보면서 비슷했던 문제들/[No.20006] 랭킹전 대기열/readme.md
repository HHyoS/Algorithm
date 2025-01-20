문제 사이트 : https://www.acmicpc.net/problem/20006

문제 설명 :

![image](https://github.com/user-attachments/assets/a1acc665-7d27-49be-8401-7a8ad67a8c54)
![image](https://github.com/user-attachments/assets/43575e1a-14ee-4680-be86-972ad996c3d3)

풀이 알고리즘

    플레이어의 정보가 주어질 때, 조건에 따라 입장 가능한 방이 있는지 확인하고, 있다면 방 참가

    없다면 방을 생성하여 마지막에 생성된 방들에 대한 정보를 출력하는 문제 '랭킹전 대기열'입니다.

    설명에 따라 풀이 진행시 어려움이 없지만 여러 개념이 복잡적으로 들어가 기본적인 자료구조

    개념이 필요한 문제 였습니다.

    문제 구현에 필요한 개념은 크게 두가지로 
    
    1) 방의 정보를 저장하는 구조체

    2) string 값 기준으로 정렬하여 사용자 정보를 출력하는 sort 입니다.

    위의 두가지를 사용하여 구조체로 배열을 만들어 방의 정보를 관리하고, 방의 정보를

    출력할 떄, 사용자의 정보를 정렬 후 출력하여 풀이 진행하면 됩니다.

    저는 구조체 두가지를 선언하여 1) 사용자 정보 2) 방 정보 를 관리하였고,

    사용자 정보 정렬의 경우 우선순위 큐를 선언하고, 사용자 정의 정렬을 선언하여

    string 값 기준으로 값이 정렬되도록 하여 구현 완료하였습니다.
    
풀이 코드

    #include <iostream>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;
    
    struct Player {
        string idx;
        int level;
    };
    
    bool operator<(Player a, Player b) { // 플레이어 id 기반 정렬 순서 정해주기
        if (a.idx == b.idx) {
            return a.level < b.level;
        }
        return a.idx > b.idx;
    }
    struct Node {
        int level_cut;
        priority_queue<Player> user;
    };
    
    int N, M;
    vector<Node> room;
    
    
    bool is_can_enter(int level, int idx) { // 입장 가능한 방이 있는지 확인
        if (room[idx].level_cut - 10 <= level && room[idx].level_cut + 10 >= level) {
            if (room[idx].user.size() < M) { // 정원 확인
                return 1;
            }
        }
        return 0;
    }
    
    void Solve() {
        for (int a = 0; a < room.size(); ++a) {
            if (room[a].user.size() == M) { // 정원이 차있다면 시작
                cout << "Started!\n";
            }
            else { // 아니라면 대기 중
                cout << "Waiting!\n";
            }
            while(!room[a].user.empty()){ // 내부의 플레이어 정보 출력
                cout << room[a].user.top().level << " " << room[a].user.top().idx << "\n";
                room[a].user.pop();
            }
        }
    }
    void Input() {
        cin >> N >> M;
        for (int a = 0; a < N; ++a) {
            int level;
            string id;
            cin >> level >> id;
    
            int sz = room.size();
            bool flag = false;
            for (int b = 0; b < sz; ++b) {
                if (is_can_enter(level,b)){ // 입장 가능 여부 확인
                    room[b].user.push({id,level});
                    flag = true;
                    break;
                }
            }
            if (flag == false) { // 입장 가능한 방이 없다면 새로운 방 생성해주기
                Node temp;
                temp.level_cut = level;
                room.push_back(temp);
                room.back().user.push({ id,level });
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

오늘의 일기

    알고리즘은 쉽다... 자동차 수리비는 어렵다... 나의 지난 몇일은 무료맨이 되었다..

    나중에 정비 기술을 배워서 정비소를 차리면 나는 일론머스크급 부자가 되어있을거야

![image](https://github.com/user-attachments/assets/4418273f-aed3-4ebb-8736-15d99aa9d4da)
