#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;


int N;
int M;

void Input_And_Solve() {
    cin >> N >> M;
    int first_lamp;
    cin >> first_lamp;
    int need_H = first_lamp; // 시작지점부터 첫번째 램프 사이의 거리
    int before_lamp = first_lamp;
    int last_lamp = 0;
    for (int a = 1; a < M; ++a) {
        int lamp;
        cin >> lamp;
        int now_need_H = lamp - before_lamp; // 각 램프 사이의 거리
        int plus_one=0;
        if (now_need_H % 2) // 만약 램프 사이의 거리 /2 가 소수점이 있다면,
            plus_one = 1; // 높이는 정수이므로 +1 해주기

      // 현재까지 필요한 최대 높이와 지금 램프 사이의 거리로 확인한 필요한 높이 중 더 큰거
        need_H = max(need_H, now_need_H / 2 + plus_one); 
        before_lamp = lamp;
        if (a == M - 1) { // 만약 마지막 램프라면 값 체크해주고
            last_lamp = lamp;
        }
    }
  // 마지막 램프와 굴다리 끝 거리 확인하여 현재까지 필요한 높이와 비교해주기
    need_H = max(need_H, N - last_lamp); 
    cout << need_H; // 최대값 출력
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input_And_Solve();


    return 0;
}
