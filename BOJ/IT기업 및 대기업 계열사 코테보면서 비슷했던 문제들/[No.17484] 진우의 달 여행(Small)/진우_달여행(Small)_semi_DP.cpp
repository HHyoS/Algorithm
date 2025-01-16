#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <string>
using namespace std;

int N, M;
int arr[7][7];
int min_v[7][7][3];
int mov[3] = { -1,0,1 };
int ans = 21e8;


void dfs(int x, int y,int now_sum,int before) {
    if (x == N-1) {
        ans = min(ans, now_sum);
        return;
    }
    for (int a = 0; a < 3; ++a) {
        if (before == a) continue;
        int nx = x + 1;
        int ny = y + mov[a];
        if (ny < 0 || ny >= M)continue;

        int total_sum = now_sum + arr[nx][ny];

          // 특정 위치에, 특정 방향으로 이동한 최소값보다 큰 값이라면 스킵
        if (min_v[nx][ny][a] <= total_sum) continue;
        dfs(nx, ny, total_sum,a);
    }

}
void Solve() {

    for (int a = 0; a < M; ++a) {
        dfs(0, a,arr[0][a],-2);
    }
    for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < M; ++b) {
            ans = min(ans, min_v[N - 1][b][a]);
        }
    }

}
void Input() {
    cin >> N >> M;

    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            cin >> arr[a][b];
            for (int c = 0; c < 3; ++c) {
                min_v[a][b][c] = 21e8;
            }
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
