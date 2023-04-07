#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int T;
int N, M, K;
int info[101];
bool solve() {
        int before = 0;
   		 int boog=0;
        for (int a = 0; a < N; ++a) {
            boog = boog + ((info[a] / M)-before) * K;
            if (boog == 0) {
                return 0;
            }
            else {
                --boog;
                before = info[a] / M;
            }
        }
    return 1;
}
void input() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> M >> K;
        int boog = 0;
        for (int a = 0; a < N; ++a) {
            cin >> info[a];
        }
        sort(info, info + N);
        if(solve()){
            cout << "#"<< t<< " "<<"Possible\n";
        }
        else{
            cout << "#"<<t<<" "<<"Impossible\n";
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   // freopen("input.txt", "r", stdin);

    input();
    return 0;
}
