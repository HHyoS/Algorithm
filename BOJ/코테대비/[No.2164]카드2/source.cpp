#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;


queue<int> que;
int N;
void solve() {
    while (que.size() != 1) {

        que.pop();
        if (que.size() == 1)
            break;

        int temp = que.front();
        que.pop();
        que.push(temp);
    }
    cout << que.front();
}
void input() {
    cin >> N;
    for (int a = 1; a <= N; ++a) {
        que.push(a);
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
