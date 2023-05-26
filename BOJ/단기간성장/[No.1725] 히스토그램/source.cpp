#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <memory.h>
using namespace std;

struct Node {
    int x;
    int y;
};

int histogram[100009];
void input() {

    int N;
    cin >> N;
    for (int a = 1; a <= N; ++a) {
        cin >> histogram[a];
    }
    histogram[N+1] = 0;

    stack<int> st;
    st.push(0);
    long long ans = 0;
    for (int a = 1; a <= N+1; ++a) {
        while (!st.empty() && histogram[a] < histogram[st.top()]) {
            int index = st.top();
            st.pop();
            long long temp = (a - st.top()-1) * histogram[index];
            if (temp > ans)
                ans = temp;
        }
        st.push(a);
                
    }

    cout << ans << "\n";
    ans = 0;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    // solve();
    return 0;
}
