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

int N;
int arr[101] = { 0 };
int visited[101] = { 0 };
vector<int> answer;

void dfs(int current, int start) {
    if (visited[current]) {
        if (current == start)
            answer.push_back(start);
    }
    else {
        visited[current] = 1;
        dfs(arr[current], start);
    }

}
void solve() {
    for (int a = 1; a <= N; ++a) {
        memset(visited, 0, sizeof(visited));
        dfs(a, a);
    }

    cout << answer.size() << "\n";
    for (int a = 0; a < answer.size(); ++a)
        cout << answer[a] << "\n";
}
void input() {
    cin >> N;
    for (int a = 1; a <= N; ++a) {
        cin >> arr[a];
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
