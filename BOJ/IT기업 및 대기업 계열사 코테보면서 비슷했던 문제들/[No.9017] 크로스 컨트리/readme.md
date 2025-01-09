문제 사이트 : https://www.acmicpc.net/problem/9017

문제 설명 :

    크로스 컨트리 달리기는 주자들이 자연적인 야외의 지형에 만들어진 코스를 달리는 운동 경기이다. 
    
    경주 코스는 일반적으로 4에서 12 킬로미터이며,
    
    숲이나 넓은 땅을 통과하는 풀과 흙으로 된 지면과 언덕과 평평한 지형을 포함한다.
    
    이 경기는 주자들의 개인성적을 매기고, 이를 가지고 팀의 점수를 계산한다. 
    
    한 팀은 여섯 명의 선수로 구성되며, 팀 점수는 상위 네 명의 주자의 점수를 합하여 계산한다.
    
    점수는 자격을 갖춘 팀의 주자들에게만 주어지며,
    
    결승점을 통과한 순서대로 점수를 받는다. 
    
    이 점수를 더하여 가장 낮은 점수를 얻는 팀이 우승을 하게 된다. 
    
    여섯 명의 주자가 참가하지 못한 팀은 점수 계산에서 제외된다. 
    
    동점의 경우에는 다섯 번째 주자가 가장 빨리 들어온 팀이 우승하게 된다.
    
    예를 들어, 다음의 표를 살펴보자.

        등수	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15
        팀	A	B	C	C	A	C	B	D	A	A	C	A	C	C	A
        점수	1	n/a	2	3	4	5	n/a	n/a	6	7	8	9	10	11	12
        팀 B 와 D 는 선수의 수가 여섯이 아니므로, 점수를 받을 수 없다. 
        팀 A 의 점수는 18 (1+4+6+7)이고, 팀 C 의 점수는 18 (2+3+5+8)이다.
        이 경우 두 팀의 점수가 같으므로 다섯 번째로 결승점을 통과한 선수를 고려한다,
        A 팀의 다섯 번째 선수의 점수가 C 팀의 다섯 번째 선수의 점수보다
        적으므로 A 팀이 우승팀이 된다.

    모든 선수들의 등수가 주어질 때, 우승팀을 구하는 프로그램을 작성하라. 
    
    각 팀의 참가 선수가 여섯보다 작으면 그 팀은 점수 계산에서 제외됨을 주의하라.
    
    여섯 명 보다 많은 선수가 참가하는 팀은 없고, 
    
    적어도 한 팀은 참가 선수가 여섯이며, 모든 선수는 끝까지 완주를 한다고 가정한다.

입력

    입력 데이터는 표준입력을 사용한다. 
    
    입력은 T 개의 테스트 케이스로 주어진다. 
    
    입력 파일의 첫 번째 줄에 테스트 케이스의 수를 나타내는 정수 T 가 주어진다.
    
    두 번째 줄부터는 두 줄에 하나의 테스트 케이스에 해당하는 데이터가 주어진다. 
    
    각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N (6 ≤ N ≤ 1,000)이 주어진다. 
    
    두 번째 줄에는 팀 번호를 나타내는 N 개의 
    
    정수 t1, t2, …, tN 이 공백을 사이에 두고 주어진다. 
    
    각 팀은 1 과 M(1 ≤ M ≤ 200)사이의 정수로 표현된다.

출력

    출력은 표준출력을 사용한다. 
    
    하나의 테스트 케이스에 대한 우승팀의 번호를 한 줄에 출력한다. 

예제 입력 1 

    2
    15
    1 2 3 3 1 3 2 4 1 1 3 1 3 3 1
    18
    1 2 3 1 2 3 1 2 3 3 3 3 2 2 2 1 1 1

예제 출력 1 

    1
    3

풀이 알고리즘

    여러 조건이 주어질 때, 조건을 모두 통과한 팀 중 1등팀을 찾는 문제 '크로스 컨트리'입니다.

    문제가 굉장히 긴 문제로, 요약하면 아래와 같습니다.

    1) 들어올 순으로 점수 배정(1등 = 1점, 2등 = 2점)
    2) 순서대로 4명의 점수를 더했을 때, 가장 작은 팀이 우승
    3) 점수가 같다면 다섯번 째 들어온 선수의 점수가 작은 팀이 우승
    4) 팀원이 여섯명이 아니라면 팀원 전체 탈락
    5) 랭킹 점수는 유의미한 팀원만 체크되므로, 4)의 조건에 의해 탈락한 팀의 구성원은 제외
    ex- 3번팀이 탈락했을 떄, 3번팀이 1등으로 들어왓다면 2등이 1등이 되어 1점을 받음

    위의 조건대로 구현하면 문제가 해결되며, 구현시 아래의 조건을 필터로 걸어 구현 진행했습니다.

    1) 입력을 한 차례 받은 후, 팀원 수 카운팅 -> 무의미한 팀 체크
    2) 입력받은 값은 한번더 탐색하며 유의미한 팀의 구성원만을 사용하여 점수 배정
    3) 점수 배정이 된 팀을 정렬 -> 1) 종합점수 낮은 팀 2) 다섯번쨰 선수가 빨리 도착한 팀

    위의 조건으로 구현 진행시 문제 풀이 완료 됩니다.

풀이 코드

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

풀이 후기

    Segment Fault가 발생해서 원인을 찾아야 했던 문제였다리..

    워낙 조건이 많고 변수를 많이 사용하여 코드가 지저분해졌고, 그로인해 sort에서 너무 큰 값을

    사용하여 발생한 문제였다..

    코드 정리 잘하자..

![image](https://github.com/user-attachments/assets/d50f92f7-d46f-4f79-9dfd-276f477c05a8)

