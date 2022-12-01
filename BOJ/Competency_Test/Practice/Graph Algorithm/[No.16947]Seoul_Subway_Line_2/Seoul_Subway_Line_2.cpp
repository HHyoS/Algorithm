#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int N;
vector<int> nosun[3000];
bool check[3000];
bool ckck[3000];
bool ck = 0;
void dfs(int idx, int target, int length) {
    if (idx == target) {
        if (length <= 2)
            return;
        ck = 1;
        return;
    }
    else {
        if (ck)
            return;
        for (int a = 0; a < nosun[idx].size(); ++a) {
            if (!check[nosun[idx][a]]) {
                check[nosun[idx][a]] = 1;
                dfs(nosun[idx][a], target, length + 1);
                if (ck)
                    break;
                check[nosun[idx][a]] = 0;
            }
        }
    }
}

void bfs(int num) {
    memset(ckck, 0, sizeof(ckck));
    queue<int> que;
    que.push(num);
    ckck[num] = 1;
    int count = 1;
    while (!que.empty()) {
        int size = que.size();
        for (int a = 0; a < size; ++a) {
            int nd = que.front();
            que.pop();
            for (int b = 0; b < nosun[nd].size(); ++b) {
                if (!ckck[nosun[nd][b]]) {
                    if (check[nosun[nd][b]]) {
                        cout << count << " ";
                        return;
                    }
                    ckck[nosun[nd][b]] = 1;
                    que.push(nosun[nd][b]);
                }
            }
        }
        ++count;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("Input.txt","r", stdin);

    cin >> N;
    int n1, n2;
    for (int a = 0; a < N; ++a) {
        cin >> n1 >> n2;
        nosun[n1 - 1].push_back(n2 - 1);
        nosun[n2 - 1].push_back(n1 - 1);
    }
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < nosun[a].size(); ++b) {
            check[nosun[a][b]] = 1;
            dfs(nosun[a][b], a, 1);
            if (ck) {
                a = N;
                break;
            }
            check[nosun[a][b]] = 0;
        }
    }
    for (int a = 0; a < N; ++a) {
        if (check[a])
            cout << "0 ";
        else {
            bfs(a);
        }
    }
    return 0;

}
