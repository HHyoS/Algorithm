#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int x;
    int y;
};
int N;
int arr[100001];
int ans = 21e8;
int info[3][2] = { {-1,1},{0,0},{1,1} };
void dfs(int before,int idx, int cnt, int chai) {
    if (cnt >= ans)
        return;

    if (idx == N-1) {
        ans = cnt;
        return;
    }

    int minus = abs(chai-(arr[idx+1]-before));
    if(minus == 1 || minus == 0){
        dfs(before + chai,idx+1,cnt+minus,chai);
    }


}
void solve() {
    if (N == 1)
        cout << 0;
    else {
        int idx = 0;
        for (int a = 0; a < 3; ++a) {
            int nowValue = arr[idx] + info[a][0];
            for (int b = 0; b < 3; ++b) {
                int nextValue = arr[idx+1] + info[b][0];
                dfs(nextValue,idx + 1, info[a][1] + info[b][1], nextValue - nowValue);
            }
        }
        if(ans == 21e8)
            cout << -1;
        else{
            cout << ans;
        }
    }
}


void input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        cin >> arr[a];
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
