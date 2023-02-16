#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
int N;
int nums[5001];
int dp[5001][5001];
int mini;

int cal(int s, int e) {
    if(s >= e)
        return 0;
    int ans = 0;
    if (dp[s][e] != 0)
        return dp[s][e];
    
    if (nums[s] == nums[e])
        ans = cal(s + 1, e - 1);
    else {
        ans = min(cal(s + 1, e), cal(s, e - 1))+1;
    }

    return dp[s][e] = ans;
}
void solve() {
    cout << cal(0, N - 1) << "\n";
}
void input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        cin >> nums[a];
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
