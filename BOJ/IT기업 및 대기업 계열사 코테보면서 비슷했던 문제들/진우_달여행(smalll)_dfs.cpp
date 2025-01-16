#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <string>
using namespace std;

int N, M;
int arr[7][7];
int ans = 21e8;


// 현재까지 코스트 + 이전 방향을 저장하면서 달에 도착하면 최소값만 정답으로 갱신 
void dfs(int x, int y,int now_sum,int before) {
    if (x == N-1) {
        ans = min(ans, now_sum);
        return;
    }
    for (int a = -1; a < 2; ++a) {
        if (before == a) continue;
        int nx = x + 1;
        int ny = y + a;
        if (ny < 0 || ny >= M)continue;

        int total_sum = now_sum + arr[nx][ny];

        dfs(nx, ny, total_sum,a);
    }
}
void Solve() {

    for (int a = 0; a < M; ++a) {
        dfs(0, a,arr[0][a],-2);
    }

}
void Input() {
    cin >> N >> M;

    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            cin >> arr[a][b];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    cout << ans;
    return 0;
}
