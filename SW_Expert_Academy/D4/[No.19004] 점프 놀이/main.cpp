#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Node {
    int x, y;
};

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        cin >> N >> K;
        vector<vector<int>> art(N, vector<int>(N));
        // 색깔별 좌표 저장 (색은 1부터 K까지)
        vector<vector<Node>> coords(K + 1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> art[i][j];
                coords[art[i][j]].push_back({ i, j });
            }
        }

        // 각 색깔에 하나라도 없는 경우, 게임 진행 불가
        bool possible = true;
        for (int color = 1; color <= K; color++) {
            if (coords[color].empty()) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            cout << "#" << tc << " -1\n";
            continue;
        }

        // dp[color][i]: 색깔 color의 i번째 타일까지 도달하는 최소 비용
        // 색깔 1의 경우 시작 비용은 0으로 초기화
        vector<vector<int>> dp(K + 1);
        dp[1].resize(coords[1].size(), 0);

        // 색깔 2부터 K까지 최소 비용을 갱신
        for (int color = 2; color <= K; color++) {
            dp[color].resize(coords[color].size(), 1e9); // 큰 값으로 초기화
            // 이전 색깔의 각 타일에서 현재 색깔의 각 타일까지 전이
            for (int i = 0; i < coords[color].size(); i++) {
                for (int j = 0; j < coords[color - 1].size(); j++) {
                    int prev_cost = dp[color - 1][j];
                    // 맨해튼 거리 계산
                    int dist = abs(coords[color][i].x - coords[color - 1][j].x) +
                        abs(coords[color][i].y - coords[color - 1][j].y);
                    dp[color][i] = min(dp[color][i], prev_cost + dist);
                }
            }
        }

        // 마지막 색깔 K의 최소 비용 값 취득
        int answer = 1e9;
        for (int cost : dp[K]) {
            answer = min(answer, cost);
        }
        if (answer == 1e9) answer = -1;

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
