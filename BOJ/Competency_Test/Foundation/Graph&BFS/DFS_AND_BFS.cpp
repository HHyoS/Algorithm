#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>



int n, m, q;
bool check[1001];
using namespace std;
queue<int> que;
vector<int> arr[1001];
void dfs(int index) {
    printf("%d ", index);

    for (int a = 0; a < arr[index].size(); ++a) {
        if (!check[arr[index][a]]) {
            check[arr[index][a]] = 1;
            dfs(arr[index][a]);
        }
    }
}

void bfs() {

    for (int a = 0; a < 1001; ++a) {
        check[a] = 0;
    }
    check[q] = 1;
    int t;
    while (!que.empty()) {
        t = que.front();
        que.pop();
        printf("%d ", t);
        for (int a = 0; a < arr[t].size(); ++a) {
            if (!check[arr[t][a]]) {
                check[arr[t][a]] = 1;
                que.push(arr[t][a]);
            }
        }
    }
    return ;

}
int main() {
 //   freopen("Input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    int b, c;
    for (int a = 0; a < m; ++a) {
        scanf("%d%d", &b, &c);
        arr[b].push_back(c);
        arr[c].push_back(b);
    }
    for (int a = 0; a < n; ++a) {
        sort(arr[a].begin(), arr[a].end());
    }
    check[q] = 1;
    dfs(q);
    printf("\n");
    que.push(q);
    bfs();
    


    return 0;
}
