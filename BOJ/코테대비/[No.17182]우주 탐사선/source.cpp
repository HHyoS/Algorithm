#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;


int cost[11][11];
bool visited[11];
int costSum[11][11];
int N, K;
int mini = 21e8;
void dfs(int deep,int sum,int before) {
    if (deep == N) {
        mini = min(mini, sum);
    }
    if (sum > mini)
        return;

    for (int a = 0; a < N; ++a) {
        if (visited[a]) continue;

        visited[a] = 1;
        dfs(deep + 1, sum + cost[before][a],a);
        visited[a] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  //  freopen("input.txt", "r", stdin);

    cin >> N >> K;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            cin >> cost[a][b];
        }
    }
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            for (int c = 0; c < N; ++c) {
                if (a == c || b == c || a == b) continue;
                cost[a][b] = min(cost[a][b], cost[a][c] + cost[c][b]);

            }
        }
    }
    visited[K] = 1;
    for (int a = 0; a < N; ++a) {
        if (a == K) continue;
        visited[a] = 1;
        dfs(2, cost[K][a],a);
        visited[a] = 0;
    }
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            cout << cost[a][b] << " ";
        }
        cout << "\n";
    }
    cout << mini;
    return 0;

}
