#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


int T;
long long solve() {
}
void input() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long N;
        cin >> N;
        cout << "#"<<t<<" " <<N * N << "\n";
    }
 }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  //  freopen("input.txt", "r", stdin);

    input();
    return 0;
}
