#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> heavier[101];
vector<int> lighter[101];
bool visited[101];
int ans = 0;

void findHeavier(int index) {
    for (int a = 0; a < heavier[index].size(); ++a) {
        if (visited[heavier[index][a]] == 0) {
            visited[heavier[index][a]] = 1;
            ++ans;
            findHeavier(heavier[index][a]);
        }
    }
}
void findLighter(int index) {
    for (int a = 0; a < lighter[index].size(); ++a) {
        if (visited[lighter[index][a]] == 0) {
            visited[lighter[index][a]] = 1;
            ++ans;
            findLighter(lighter[index][a]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    
    cin >> N >> M;
    for (int a = 0; a < M; ++a) {
        int A, B;
        cin >> A >> B;
        heavier[A].push_back(B);
        lighter[B].push_back(A);
    }
    for (int a = 1; a <= N; ++a) {
        memset(visited, 0, sizeof(visited));
        ans = 1;
        findHeavier(a);
        findLighter(a);
        cout << N - ans << "\n";

    }
    return 0;

}
