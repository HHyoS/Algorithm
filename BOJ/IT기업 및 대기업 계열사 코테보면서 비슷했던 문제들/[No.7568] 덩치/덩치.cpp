#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int W; // 몸무게
    int H; // 키
};

Node arr[51];
int answer[51];
int N;
int target;


void Solve() {
    
    for (int a = 0; a < N; ++a) { // 내 등수는 나보다 큰 애의 숫자 +1이므로 완탐 해보자
        int cnt = 1;
        for (int b = 0; b < N; ++b) {
            if (a == b) continue; // 나랑 같은건 스킵. 안해도 상관 없긴 할 듯.
            if (arr[a].H < arr[b].H && arr[a].W < arr[b].W) { // 나보다 덩치 큰애 있으면 +1
                ++cnt;
            }
        }
        answer[a] = cnt; // 나보다 덩치 큰 애들의 수가 나의 순위다
    }
    for (int a = 0; a < N; ++a) {
        cout << answer[a] << " ";
    }
}
void Input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        int w, h;
        cin >> w >> h;
        arr[a] = { w,h };
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
