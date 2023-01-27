#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int workTimeA[1004];
int workTimeB[1005];
int N;
int moveTo[2][1005];
int dp[1005][2]; // dp[0] = A작업장, dp[1] = B작업장
void solve() {

    for (int a = 1; a <= N; ++a) {
        dp[a][0] = min(dp[a - 1][0] + workTimeA[a], dp[a - 1][1] + moveTo[0][a] + workTimeA[a]);
        dp[a][1] = min(dp[a - 1][1] + workTimeB[a], dp[a - 1][0] + moveTo[1][a] + workTimeB[a]);
    }
    cout << min(dp[N][0],dp[N][1]);
}
void input() {
    cin >> N;
    for (int a = 1; a <= N-1; ++a) {
        cin >> workTimeA[a] >> workTimeB[a] >> moveTo[1][a+1] >> moveTo[0][a+1];
    }
    cin >> workTimeA[N] >> workTimeB[N];

}
int main(int argc, char** argv)
{

    input();
    solve();
	return 0;
}
