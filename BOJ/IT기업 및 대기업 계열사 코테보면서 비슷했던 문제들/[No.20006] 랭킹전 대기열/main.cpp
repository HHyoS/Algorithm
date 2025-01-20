#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
*/


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
