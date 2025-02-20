#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/1987
    문제 설명 : 
       문제에서 주어진 조건 세가지를 바탕으로 결과를 출력하는 문제 '알파벳'입니다.
       조건 1) 대문자 알파벳으로 주어진 R*C 크기의 입력값이 주어짐
       조건 2) 0,0 좌표에서 시작해서 상 하 좌 우 로 이동 가능
       조건 3) 한 번 방문한 알파벳은 두 번 방문 불가능

       조건을 만족하기 위해 세가지 변수를 선언하여 사용 했습니다.
       조건 1 = 입력값 저장을 위한 board 배열
       조건 2 = 이동을 위한 mov 배열
       조건 3 = 방문 알파벳 위치 기록을 위한 visited 배열

       위의 세가지 배열을 사용하여 0,0에서 시작하는 DFS 풀이를 진행했고 각 DFS의 동작은 아래와 같습니다

       1) DFS 함수는 DFS(다음 x좌표,다음 y좌표, 이동 칸수)
       2) DFS 함수를 실행하면 초기에 이동 칸수를 확인하여 현재까지 기록된 이동 칸수와 비교하여 최대값을 저장
       3) 상 하 좌 우 이동을 시도하고 R*C 의 범위를 벗어나거나, 이미 방문한 알파벳 이라면 스킵
       4) 3에 해당하지 않는다면 다음 좌표 알파벳을 방문처리하고 다음 좌표로 이동하는 DFS 탐색 진행
       5) 4의 코드 다음 줄에 방문처리 했던 값을 미방문 처리하여 다음 DFS에서 사용할 수 있도록 함

       위의 방법으로 구현하면 쉽게 풀이가 진행됩니다.

       저는 제출 2회 틀렸는데, 문제에서 사용하는 시작좌표 (1,1)과 달리 저는 (0,0)부터 시작하는데
       문제에서 제공하는 좌표를 그대로 입력값으로 사용하여 틀림이 발생했고, (0,0)으로 수정하여 통과했습니다.

      */

int R, C;

bool visited[27]; // 알파벳 방문 확인용
char board[22][22]; // 입력값 저장용
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; // 이동 배열 (상 우 하 좌)
int maxi = 1; // 최대 이동 칸수 저장용
void dfs(int x, int y, int cnt) {
    
    maxi = max(cnt, maxi); // 최대값을 계속 갱신해주기

    for (int a = 0; a < 4; ++a) {
        int nx = x + mov[a][0];
        int ny = y + mov[a][1];

        // 다음 좌표가 입력값 범위를 벗어나거나 이미 방문한 위치면 스킵
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (visited[board[nx][ny] - 'A'] == true) continue;

        // 아니라면 방문처리하고 DFS, 이후 미방문 처리
        visited[board[nx][ny] - 'A'] = true;
        dfs(nx, ny, cnt + 1);
        visited[board[nx][ny] - 'A'] = false;
    }


}
void Solve() {
    // 0,0은 시작 좌표이므로 방문 처리 후 시작
    visited[board[0][0] - 'A'] = true;
    dfs(0, 0,1);
    cout << maxi;
}
void Input() {
    cin >> R >> C;
    for (int a = 0; a < R; ++a) {
        for (int b = 0; b < C; ++b) {
            cin >> board[a][b];
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
