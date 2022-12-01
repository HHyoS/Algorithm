#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr[1001];
int n, m;
int x[10009], y[10009];
bool check[1001];
void dfs(int index) {
    check[index] = 1;
    for (int a = 0; a < arr[index].size(); ++a) {
        if (!check[arr[index][a]]) {
            dfs(arr[index][a]);
        }
    }
}

int main() {
 //   freopen("Input.txt", "r", stdin);
    int answer = 0;
    scanf("%d%d", &n, &m);
    for (int a = 0; a < m; ++a) {
        scanf("%d%d", &x[a], &y[a]);
        arr[x[a]].push_back(y[a]);
        arr[y[a]].push_back(x[a]);
    }
    for (int a = 1; a <= n; ++a) {
        if (!check[a]) {
            dfs(a);
            ++answer;
        }
    }
    
    printf("%d", answer);

    return 0;
}
