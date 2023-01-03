#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N, K;
vector<int> dogu;
bool used[9];
int ans = 0;
void dfs(int weight,int day) {
    if (day == N) {
        ++ans;
        return;
    }
    for (int a = 0; a < N; ++a) {
        if (used[a] == 0) {
            int total = weight - K + dogu[a];
            if (total < 500)
                continue;
            used[a] = 1;
            dfs(total, day + 1);
            used[a] = 0;
        }
    }
}
void solve() {
    
    for(int a = 0; a< N; ++a){
        if (dogu[a] < K)
            break;
        used[a] = 1;
        dfs(500 + dogu[a] - K,1);
        used[a] = 0;
    }
    cout << ans;
}
void input() {
    cin >> N >> K;

    for (int a = 0; a < N; ++a) {
        int temp;
        cin >> temp;
        dogu.push_back(temp);
    }
    sort(dogu.begin(), dogu.end(),greater<int>());
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt", "r", stdin);

    input();
    solve();
    return 0;

}
