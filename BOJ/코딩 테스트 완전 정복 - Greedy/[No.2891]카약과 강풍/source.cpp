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
  

int N, S, R;
bool redundancy[12];
bool team[12];
int solve() {
    int cnt = 0;
    for (int a = 1; a <= N; ++a) {
        if (team[a]) {
            if (redundancy[a - 1] == 1) {
                redundancy[a - 1] = 0;

            }
            else if (redundancy[a + 1] == 1) {
                redundancy[a + 1] = 0;
            }
            else
                ++cnt;
        }
    }
    return cnt;
}
void input() {
    cin >> N >> S >> R;
    for (int a = 1; a <= S; ++a) {
        int temp;
        cin >> temp;
        team[temp] = 1;
    }
    for (int a = 0; a < R; ++a) {
        int temp;
        cin >> temp;
        if (team[temp] == 1) {
            team[temp] = 0;
        }
        else 
            redundancy[temp] = 1;
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
