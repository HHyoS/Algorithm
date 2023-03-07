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
  
int square[3][3];
int tempSquare[3][3];
int ans = 21e8;
bool used[10];
bool check() {
    int rowSum[3] = { 0 };
    int colSum[3] = { 0 };
    int leftCross = 0, rightCross = 0;
    for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
            if (a == b) {
                leftCross += tempSquare[a]QD[b];
            }
            if (a + b == 2) {
                rightCross += tempSquare[a][b];
            }
            rowSum[a] += tempSquare[a][b];
            colSum[b] += tempSquare[a][b];
        }
    }
    for (int a = 0; a < 2; ++a) {
        if (rowSum[a] != rowSum[a + 1])
            return 0;
    }
    for (int a = 0; a < 2; ++a) {
        if (colSum[a] != colSum[a + 1])
            return 0;
    }
    if (rightCross != leftCross)
        return 0;

    if (rowSum[0] == colSum[0] && colSum[0] == rightCross)
        return 1;
    return 0;
}
void dfs(int x, int y, int sum) {
    ++y;
    if (y == 3) {
        ++x;
        y = 0;
        if (x == 3) {
            if(check())
                ans = min(ans,sum);
            return;
        }
    }

    for (int a = 1; a <= 9; ++a) {
        if (used[a] == 0) {
            used[a] = 1;
            tempSquare[x][y] = a;
            dfs(x, y, sum + abs(a - square[x][y]));
            used[a] = 0;
        }
    }
}
void solve(){
    for (int a = 1; a <= 9; ++a) {
        used[a] = 1;
        tempSquare[0][0] = a;
        dfs(0, 0, abs(a - square[0][0]));
        used[a] = 0;
    }
    cout << ans;
}
void input() {
    for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
            cin >> square[a][b];
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
