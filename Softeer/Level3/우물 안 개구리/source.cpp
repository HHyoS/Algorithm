a#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int N, M;
int weight[100001];
bool strong[100001];
void solve() {
    int ans = 0;
    for (int a = 1; a <= N; ++a) {
        if (strong[a] == 0) {
            ++ans;
        }
    }
    cout << ans << "\n";
}

void input() {
    cin >> N >> M;
    for (int a = 1; a <= N; ++a) {
        cin >> weight[a];
    }
    for (int a = 0; a < M; ++a) {
        int A, B;
        cin >> A >> B;
        if (weight[A] < weight[B])
            strong[A] = 1;
        else if (weight[A] > weight[B])
            strong[B] = 1;
        else {
            strong[A] = 1;
            strong[B] = 1;
        }
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
    solve();
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
    return 0;
}
