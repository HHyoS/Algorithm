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
  
int money;
int joi[6] = { 500,100,50,10,5,1 };
int solve() {
    int cnt = 0;
    int total = 1000-money;
    for (int a = 0; a < 6; ++a) {
        if (total == 0) {
            break;
        }
        cnt += (total / joi[a]);
        total = total % joi[a];
    }
    return cnt;
}
void input() {
    cin >> money;
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
