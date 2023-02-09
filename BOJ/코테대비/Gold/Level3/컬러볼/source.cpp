#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Node {
    int index;
    int color;
    int size;
};

bool cmp(Node a, Node b) {
    if (a.size == b.size) {
        if (a.color == b.color) {
            return a.index < b.index;
        }
        return a.color < b.color;
    }
    return a.size < b.size;
}
int N;
vector<Node> v;
int ans[200001];
int colorSum[200001];
int dp[2001];
void solve() {
    int totalSum = 0;
    int beforeSize = 0;
    int beforeColor = 0;
    int beforeCnt = 0;
    for (int a = 0; a < N; ++a) {
        int color = v[a].color;
        int size = v[a].size;
        if (beforeSize == size && beforeColor == color) {
            ans[v[a].index] = beforeSize * beforeCnt;
            ++beforeCnt;
        }
        else {
            beforeSize = size;
            beforeColor = color;
            beforeCnt = 1;
        }
        ans[v[a].index] = ans[v[a].index]+ totalSum - colorSum[color] - dp[size];
        totalSum += size;
        colorSum[color] += size;
        dp[size] += size;
    }
    for (int a = 0; a < N; ++a) {
        cout << ans[a] << "\n";
    }

}
void input() {
    cin >> N;
    for (int a = 0; a < N; ++a){
        int color, size;
        cin >> color >> size;
        v.push_back({ a,color,size });
    }
    sort(v.begin(), v.end(), cmp);
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
    solve();
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
    return 0;
}
