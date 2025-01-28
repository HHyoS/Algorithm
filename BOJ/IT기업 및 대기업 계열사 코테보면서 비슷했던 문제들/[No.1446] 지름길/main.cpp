#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/1446
    문제 설명 :

    */

struct Node {
    int d;
    int cost;
};
int N, D;

vector<Node> arr[10001];// 이동 코스트 정보 저장
int mini[10001]; // 이동 최소 코스트 저장



void Solve() {

    for (int a = 0; a <= D; ++a) {
        mini[a] = a;
    }
    for (int a = 0; a <= D; ++a) {
        if (a != 0) {
             mini[a] = min(mini[a], mini[a - 1] + 1);
        }
        for (int b = 0; b < arr[a].size(); ++b) {
            int nextD = arr[a][b].d;
            int nextCost = arr[a][b].cost;

            mini[nextD] = min(mini[nextD], min(mini[a] + nextCost, mini[a] + nextD - a));
        }
    }

    cout << mini[D];
}
void Input() {
    cin >> N >> D;
    for (int a = 0; a < N; ++a) {
        int s, e, d;
        cin >> s >> e >> d;
        arr[s].push_back({ e,d });
    }


    /* for debugging
    for (int a = 0; a <= D; ++a) {
        cout << "start at " << a << "\n";
        for (int b = 0; b < info[a].size(); ++a) {
            cout << info[a][b] << " ";
        }
        cout << "===========================\n";
    }
    */
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
