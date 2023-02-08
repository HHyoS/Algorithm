#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<int> good[1001];
vector<int> bad[1001];
bool visited[1001];
int N, M;
void solve() {
    int team = 0;
    for (int a = 1; a <= N; ++a) {
        if (visited[a] == 0) ++team;
        visited[a] = 1;
        for (int b = 0; b < good[a].size(); ++b) {
            int goodNow = good[a][b];
            visited[goodNow] = 1;
            for (int c = 0; c < good[goodNow].size(); ++c) {
                visited[good[goodNow][c]] = 1;
            }
        }
        for (int b = 0; b < bad[a].size(); ++b) {
            int badNow = bad[a][b];
            for (int c = 0; c < bad[badNow].size(); ++c) {
                    visited[bad[badNow][c]] = 1;
            }
        }
    }
    cout << team;
}
void input() {
    cin >> N >> M;
    for (int a = 0; a < M; ++a) {
        char type;
        int start, end;
        cin >> type >> start >> end;
        if (type == 'F') {
            good[start].push_back(end);
            good[end].push_back(start);
        }
        else {
            bad[start].push_back(end);
            bad[end].push_back(start);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    return 0;
}
