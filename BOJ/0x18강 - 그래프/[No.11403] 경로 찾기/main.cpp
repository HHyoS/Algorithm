#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N));

    // 인접 행렬 입력
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> graph[i][j];

    // 플로이드-워셜 알고리즘을 이용한 경로 탐색
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;

    // 결과 출력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << graph[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
