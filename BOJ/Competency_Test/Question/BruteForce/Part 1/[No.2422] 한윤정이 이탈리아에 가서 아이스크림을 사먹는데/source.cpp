#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

int N, M;
bool avoid[201][201];
int solve() {
    int cnt = 0;

    for (int a = 1; a <= N-2; ++a) {
        for (int b = a+1; b <= N-1; ++b) {
            if (avoid[a][b] == 1) continue;
            for (int c = b+1; c <= N; ++c) {
                if (avoid[a][c] == 1 || avoid[b][c] == 1)
                    continue;
                ++cnt;
            }
        }
    }
    return cnt;
}
void input() {
    cin >> N >> M;
    for (int a = 0; a < M; ++a) {
        int first, second;
        cin >> first >> second;
        avoid[first][second] = 1;
        avoid[second][first] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    clock_t start, finish;
    double duration;
    freopen("input.txt", "r", stdin);
    start = clock();
    input();
    cout << solve()<<"\n";
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
    return 0;
}
