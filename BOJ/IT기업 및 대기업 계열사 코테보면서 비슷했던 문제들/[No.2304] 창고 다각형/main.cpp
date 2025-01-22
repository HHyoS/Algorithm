#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int x;
    int y;
};

int N;

int roof[1001];
int max_h = 0;
int max_x = 0;
int start_x = 21e8;
int end_x = -1;
void Solve() {

    int area = 0;
    int max_roof = 0;

  // 시작 지점 부터 제일 높은 곳 까지 한칸씩 이동하면서 넓이 채워가기
    for (int a = start_x; a <= max_x; ++a) {
      // 더 높은곳이 있다면 더 큰 사각형을 채워야 하므로 값 기억
        max_roof = max(max_roof, roof[a]); 
        area += max_roof;
    }

    max_roof = 0;
  // 높은 지점부터 오른쪽 끝까지 탐색
    for (int a = end_x; a > max_x; --a) {
        max_roof = max(max_roof, roof[a]);
        area += max_roof;
    }

    cout << area;
    
}
void Input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        int x, y;
        cin >> x >> y;
        roof[x] = y;
        if (roof[x] > max_h) { // 최대 높이를 찾아서 해당 높이와 인덱스를 기록하자
            max_h = roof[x];
            max_x = x;
        }
      // 시작과 끝 지점도 기억하기
        start_x = min(start_x, x);
        end_x = max(end_x, x);
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
