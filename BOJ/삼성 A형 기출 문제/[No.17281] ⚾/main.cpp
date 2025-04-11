#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// hit_result에 따라 현재 이닝의 루 상태를 업데이트하고 점수를 계산하는 함수
int processHit(vector<int>& bases, int hit) {
    int score = 0;
    vector<int> newBases(3, 0);
    
    // hit가 1, 2, 3일 경우 기존 루에 있던 주자들을 hit만큼 이동
    for (int i = 2; i >= 0; i--) {
        if (bases[i]) {
            int newPos = i + hit;
            if (newPos >= 3) {
                score++;
            } else {
                newBases[newPos] = 1;
            }
        }
    }
    // 타자 처리 : 안타(hit=1이면 1루, hit=2이면 2루, hit=3이면 3루로 진루)
    if (hit >= 1 && hit <= 3) {
        if (hit - 1 >= 3)
            score++;
        else
            newBases[hit - 1] = 1;
    }
    bases = newBases;
    return score;
}

int simulateGame(const vector<vector<int>>& game, const vector<int>& order) {
    int score = 0;
    int cur = 0;  // 타순 인덱스 (0 ~ 8)
    int N = game.size();
    
    for (int inning = 0; inning < N; inning++) {
        int outs = 0;
        vector<int> bases(3, 0); // 1루, 2루, 3루 (0이면 빈칸, 1이면 주자 존재)
        while (outs < 3) {
            int player = order[cur];
            int result = game[inning][player];
            
            if (result == 0) {         // 아웃
                outs++;
            } else if (result == 4) {  // 홈런: 모든 주자 + 타자 점수
                score += 1;           // 타자 점수
                for (int i = 0; i < 3; i++) {
                    if (bases[i]) {
                        score++;
                    }
                }
                bases.assign(3, 0);   // 베이스 클리어
            } else {                   // 안타 (1), 2루타 (2), 3루타 (3)
                score += processHit(bases, result);
            }
            cur = (cur + 1) % 9;
        }
        // 이닝이 끝나면 bases와 outs는 초기화되며 타순은 이전 이닝 종료 시점의 다음 타자부터 시작
    }
    return score;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<vector<int>> game(N, vector<int>(9, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> game[i][j];
        }
    }
    
    int maxScore = 0;
    // 선수 번호를 0부터 8로 생각합니다.
    // 단, 0번 선수(문제의 1번 선수)는 반드시 4번 타자(인덱스 3)에 고정합니다.
    // 나머지 선수(1~8)를 위한 순열 생성
    vector<int> players = {1, 2, 3, 4, 5, 6, 7, 8};  
    do {
        // 순열로부터 실제 타순 생성: 처음 3명, 그 다음 0번 선수, 그 후 나머지 5명을 이어 붙임
        vector<int> order;
        order.insert(order.end(), players.begin(), players.begin() + 3);
        order.push_back(0);  // 1번 선수 (0번)
        order.insert(order.end(), players.begin() + 3, players.end());
        
        int score = simulateGame(game, order);
        maxScore = max(maxScore, score);
        
    } while (next_permutation(players.begin(), players.end()));
    
    cout << maxScore << "\n";
    return 0;
}
