#include <iostream>
using namespace std;
int T, N, M;
char m[55][55];
 
void input() {
    cin >> N >> M;
    for (int y = 0; y < N; y++)for (int x = 0; x < M; x++)cin >> m[y][x];
}
bool check(int ty, int tx, char tar) {
    if (ty % 2 == tx % 2) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (m[y][x] == '?')continue;
                if (y % 2 == x % 2) {
                    if (m[y][x] != (tar == '#' ? '#' : '.')) return false;
                }
                else {
                    if (m[y][x] != (tar == '#' ? '.' : '#')) return false;
                }
            }
        }
    }
    else {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (m[y][x] == '?')continue;
                if (y % 2 == x % 2) {
                    if (m[y][x] != (tar == '#' ? '.' : '#')) return false;
                }
                else {
                    if (m[y][x] != (tar == '#' ? '#' : '.')) return false;
                }
            }
        }
    }
    return true;
}
void solve() {
    cin >> T; for (int t = 1; t <= T; t++) {
        input(); string ans = "";
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (m[y][x] == '?')continue;
                if (m[y][x] == '.' || m[y][x] == '#') {
                    if (check(y, x, m[y][x])) ans = "possible";
                    else ans = "impossible";
                    break;
                }
            }
            if (ans != "")break;
        }
        if (ans == "")ans = "possible";
        cout << "#" << t << " " << ans << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    solve();
    return 0;
}
