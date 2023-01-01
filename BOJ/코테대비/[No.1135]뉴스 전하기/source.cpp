#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

vector<int> info[51];
int N;
int maxi = 21e8;
int dfs(int idx) {
    vector<int> temp;
    int ans = 0;
    int namuzi = info[idx].size() - 1;

    for (int a = 0; a < info[idx].size(); ++a) {
        temp.push_back(dfs(info[idx][a]));
    }

    sort(temp.begin(), temp.end());
    for (int a = 0; a < temp.size(); ++a) {
        ans = max(ans, temp[a] + namuzi--);
    }

    return ans+1;
}
void solve() {
    
    cout << dfs(0)-1;

}
void input() {
    cin >> N;
    int temp;
    cin >> temp;

    for (int a = 1; a < N; ++a) {
        cin >> temp;
        info[temp].push_back(a);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);

    input();
    solve();
    return 0;

}
