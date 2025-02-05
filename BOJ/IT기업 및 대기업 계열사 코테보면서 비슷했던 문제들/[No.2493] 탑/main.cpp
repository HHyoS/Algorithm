#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/2493
    문제 설명 :

      */

struct Node {
    int idx;
    int h;
};

int top[500010];
int ans[500010];
stack<Node> st;
int N;
void Solve() {
    for (int a = N; a >= 1; --a) {
        if (a == N) {
            st.push({ a,top[a] });
        }
        else {
            while (!st.empty() && st.top().h <= top[a]) {
                Node nNode = st.top();
                st.pop();
                ans[nNode.idx] = a;
            }
            st.push({ a,top[a] });
        }
    }
    for (int a = 1; a <= N; ++a) {
        cout << ans[a] << " ";
    }
}
void Input() {
    cin >> N;
    for (int a = 1; a <= N; ++a) {
        cin >> top[a];
    }

}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
