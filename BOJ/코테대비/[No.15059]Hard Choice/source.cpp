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

int C, B, P;
int wantC, wantB, wantP;
int solve() {
    int ans = 0;
    if (wantC > C)
        ans += (wantC - C);
    if (wantB > B)
        ans += (wantB - B);
    if (wantP > P)
        ans += (wantP - P);
    return ans;
}
void input() {
    cin >> C >> B >> P;
    cin >> wantC >> wantB >> wantP;
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
