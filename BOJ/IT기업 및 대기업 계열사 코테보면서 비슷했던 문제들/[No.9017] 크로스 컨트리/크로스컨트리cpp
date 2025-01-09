#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

/*
팀의 수 <= 200
1<= 각 팀의 인원 <= 6
6 <= 참가 인원 <= 1000

*/

struct Node {
    int idx;
    int point;
    int cnt;
    int num_five;
};
int N;
Node team[203];
int total_participant;
int input_arr[1010];
int team_cnt[1010];
int maxi_team;
bool ssort(Node a, Node b) { // 1. 점수 낮은 팀 2.다섯번째가 가장 빨리 들어온 팀
    if (a.point == b.point) {
        return a.num_five < b.num_five;
    }
    return a.point < b.point;
}
void Solve() {
    sort(team, team + maxi_team+1, ssort); // 정렬해주기
    for (int a = 0; a <= total_participant; ++a) {
        if (team[a].cnt != 6) continue; // 정렬 한 내용 중 쓰레기값 제외하기
        cout << team[a].idx << "\n"; // 유의미한 팀 중 1등 팀 번호 출력
        return;
    }
}
void Input() {
    cin >> N;
    for (int a = 0; a < N; ++a) { // 매 케이스마다 초기화 함 해주고
        maxi_team = 0;
        memset(team_cnt, 0, sizeof(team_cnt));
        memset(team, 0, sizeof(team));
        memset(input_arr, 0, sizeof(input_arr));
        cin >> total_participant;
        for (int b = 1; b <= total_participant; ++b) {
            int index;
            cin >> index;
        
            input_arr[b] = index;
            team_cnt[index]++;
            maxi_team = max(maxi_team, index);
            // 팀의 최대 번호와 각 팀의 참가자 수 체크
        }
        int ranking_point = 1;
        for (int b = 1; b <= total_participant; ++b) {
            if (team_cnt[input_arr[b]] != 6) // 특정 팀의 참가자 수가 6이하라면 계산 X
                continue;
            else {
                int idx = input_arr[b];
                if (team[idx].cnt + 1 <= 4) { // 네명까지는 점수 합산
                    team[idx] = { idx,team[idx].point + ranking_point,team[idx].cnt + 1,team[idx].num_five };

                }
                else { // 네명 이후는 카운팅만
                    team[idx] = { idx,team[idx].point,team[idx].cnt + 1,team[idx].num_five };

                }
                if (team[idx].cnt == 5) { // 다섯번째 지나간 사람이라면 점수 쳋크
                    team[idx].num_five = b;
                }
                ++ranking_point; // 실제로 점수 카운팅 되는 팀만 +1
            }
        }
        Solve();
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();


    return 0;
}
