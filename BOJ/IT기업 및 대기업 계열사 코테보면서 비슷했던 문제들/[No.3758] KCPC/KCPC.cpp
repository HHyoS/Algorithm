#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <string>
using namespace std;


/*
    입력 정보
    첫줄 : T = TC 개수
    둘째줄 : N = 팀 개수, K = 문제 개수, t = 우리팀 ID, m = 로그 엔트리 개수 
        3 ≤ n, k ≤ 100, 1 ≤ t ≤ n, 3 ≤ m ≤ 10,000
    셋째줄 ~ 셋째줄+N줄 : i = 제출 팀 ID / j = 문제 번호 / s = 획득 점수

    필요한 정보
    1) 각 팀당 제출 횟수 저장 배열
    2) 각 팀의 마지막 제출 시간
    3) 각 팀의 총 점수
    4) 각 팀에서 푼 특정 문제의 최종 점수

    풀이 방법 - 필요한 정보가 담긴 구조체 선언 후 탐색 or sort 구현 후 정렬
*/

struct Node {
    int team_id;
    int total_point;
    int last_submit_time;
    int submit_cnt;
};

Node info[110]; // 문제 풀이를 위한 각 팀의 정보
int question[110][110]; // 각 팀별 문제 최종 점수

int T, n, k, t, m;


bool H_Sort(Node a, Node b) { // 문제 조건에 따라 우선순위 정리
    if (a.total_point == b.total_point) {
        if (a.submit_cnt == b.submit_cnt) {
            return a.last_submit_time < b.last_submit_time;
        }
        return a.submit_cnt < b.submit_cnt;
    }

    return a.total_point > b.total_point;
}
int Solve() {
    // 우선순위 정렬
    sort(info, info + n + 1, H_Sort);
    for (int a = 0; a <= n; ++a) {
        // 정렬은 0번 인덱스부터 적용되었으므로 1등이 0번 인덱스에 위치함
        if (info[a].team_id == t) { 
            return a+1; // 따라서 a+1이 실제 등수임
        }
    }
}

void init() { // tc가 여러개이므로 초기화 해주기
    memset(question, 0, sizeof(question));
    memset(info, 0, sizeof(info));
    for (int a = 1; a <= n; ++a) {
        info[a].team_id = a;
    }
}

void Input() {
    cin >> T;
    for (int a = 0; a < T; ++a) {
        cin >> n >> k >> t >> m;
        init();
        for (int b = 0; b < m; ++b) {
            int i, j, s;
            cin >> i >> j >> s;
            info[i].submit_cnt++; // 제출 횟수 1회 증가
            if (question[i][j] < s) { // 현재 제출 점수가 더 클 경우 처리해주기
                info[i].total_point += (s - question[i][j]);
                question[i][j] = s; 
            }
            info[i].last_submit_time = b; // 마지막 제출 시간 정리
        }
        cout << Solve() << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    return 0;
}
