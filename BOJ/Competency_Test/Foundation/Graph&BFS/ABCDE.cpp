#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


int n, m;
bool check[2000];
using namespace std;

vector<int> arr[2000];
void dfs(int now,int deep) {
    if (deep == 4) {
        printf("1");
        exit(0);
    }
    for (int a = 0; a < arr[now].size(); ++a) {
        if (!check[arr[now][a]]) {
            check[arr[now][a]] = 1;
            dfs(arr[now][a], deep + 1);
            check[arr[now][a]] = 0;
        }

    }
}
int main() {
 //   freopen("Input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int a = 0; a < m; ++a) {
        int b, c;
        scanf("%d%d", &b, &c);
        arr[b].push_back(c);
        arr[c].push_back(b);

    }
    for (int a = 0; a < n; ++a) {
        check[a] = 1;
        dfs(a, 0);
        check[a] = 0;
    }
    printf("0");
    return 0;
}
