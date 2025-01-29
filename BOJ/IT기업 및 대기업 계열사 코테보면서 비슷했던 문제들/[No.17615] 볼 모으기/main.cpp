#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/17615
    문제 설명 :
        최대 두 종류의 공들이 주어질 때, 같은 종류의 공 끼리 모이도록
        정렬하고, 정렬할 때, 최소 이동 횟수를 구하는 문제 '볼 모으기' 입니다.

        문제의 입력은 최대 50만으로 불필요한 반복이 발생할 경우 반드시 시간초과가 발생하는
        문제 입니다.

        문제의 조건을 만족시킬 수 있는 공들의 이동 방법은 아래와 같습니다.

        1) 왼쪽은 빨강, 오른쪽은 파랑
            - 빨강을 왼쪽으로 이동시키기
            - 파랑을 오른쪽으로 이동시키기

        2) 왼쪽은 파랑, 오른쪽은 빨강
            - 파랑을 왼쪽으로 이동시키기
            - 빨강을 오른쪽으로 이동시키기

        위의 조건들은 비슷해 보일 수 있으나 주어지는 입력에 따라 특정 케이스가 더 
        효율적인 케이스가 있을 수 있으므로 모든 케이스에 대해 체크가 필요합니다.

        위의 조건을 만족시키는 방법은 각 공들의 처음과 마지막 위치를 기록하고
        공을 이동시킬 때, 해당 위치 전-후로 공들을 이동시키면 됩니다.
    */

int N;
string balls;
int first_red, last_red;
int first_blue, last_blue;

// 파랑 왼쪽, 빨강 오른쪽
int BlueLeft_RedRight() {
    int ans = 21e8;
    int cnt = 0;

    // 빨간 공을 오른쪽으로 이동 시키기
    for (int a = 0; a < N; ++a) {
        // 왼쪽부터 시작해서 파란 공의 끝까지 탐색했다면, 
        // 왼쪽에 있던 모든 빨간공은 오른 쪽으로 이동 완료
        if (a == last_blue)
            break;
        if (balls[a] == 'R') {
            ++cnt;
        }
    }

    ans = min(ans, cnt);
    cnt = 0;

    // 오른쪽 끝에서 시작하여 파란 공을 왼쪽으로 이동 시키기
    for (int a = N - 1; a >= 0; --a) {
        // 오른쪽부터 시작해서 빨간 공의 처음 위치까지 탐색했다면, 오른쪽에 있던 
        // 모든 파란공은 왼쪽으로 이동 완료
        if (a == first_red) {
            break;
        }
        if (balls[a] == 'B') {
            ++cnt;
        }
    }
    ans = min(ans, cnt);
    return ans;
}

// 빨강 왼쪽, 파랑 오른쪽
int RedLeft_BlueRight() {
    int ans = 21e8;
    int cnt = 0;
    for (int a = 0; a < N; ++a) {
        // 왼쪽부터 시작해서 빨강 공의 끝까지 탐색했다면, 왼쪽에 있던 모든 파란 공은 
        // 오른쪽으로 이동 완료
        if (a == last_red) {
            break;
        }
        if (balls[a] == 'B') {
            ++cnt;
        }
    }

    ans = min(ans, cnt);
    cnt = 0;

    for (int a = N - 1; a >= 0; --a) {
        // 오른쪽부터 시작해서 파란 공의 처음까지 탐색했다면, 오른쪽에 있던 모든
        // 빨간 공은 왼쪽으로 이동 완료
        if (a == first_blue) {
            break;
        }
        if (balls[a] == 'R') {
            ++cnt;
        }
    }

    ans = min(ans, cnt);

    return ans;
}

int Solve() {

    int mini = 21e8;
    mini = min(mini, BlueLeft_RedRight());
    mini = min(mini, RedLeft_BlueRight());

    return mini;

}
void Input() {
    cin >> N >> balls;
    bool red_first = false, blue_first = false;

    // 각 공의 시작, 끝 위치 기록해두기
    for (int a = 0; a < N; ++a) {
        if (balls[a] == 'R'){
            if (red_first == false) {
                red_first = true;
                first_red = a;
            }
            last_red = a;

        }
        else if (balls[a] == 'B') {
            if (blue_first == false) {
                blue_first = true;
                first_blue = a;
            }
            last_blue = a;
        }
    }
    if (red_first && blue_first) {
        cout << Solve();
    }
    // 특정 색의 공이 없다면 옮길 필요가 없다.
    else {
        cout << "0";
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    return 0;
}
