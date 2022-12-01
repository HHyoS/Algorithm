#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
vector<int> arr[20001];
int n, m,qq;
int x[200001], y[200001];
int check[20001];
int endd = 0;
// 0은 안들림, 1은 빨강, 2는 파랑
void dfs(int index, int dv) {
    check[index] = dv;
    for (int a = 0; a < arr[index].size(); ++a) {
        if (check[arr[index][a]]==0) {
            if (dv == 1) {
                dfs(arr[index][a], 2);
            }
            else {
                dfs(arr[index][a], 1);
            }
        }
        else if(check[arr[index][a]] == dv){
            endd = 1;
        }
    }
    return;
}

int main() {
 //   freopen("Input.txt", "r", stdin);
    scanf("%d", &qq);
    for (int q = 0; q < qq; ++q) {
        endd = 0;
        scanf("%d%d", &n, &m);
        
        for (int a = 0; a < m; ++a) {
            scanf("%d%d", &x[a], &y[a]);
            arr[x[a]].push_back(y[a]);
            arr[y[a]].push_back(x[a]);
        }
        for (int a = 1; a <= n; ++a) {
            if (!check[a]) {
                dfs(a,1);
            }
        }
        if (endd == 0)
            printf("YES\n");
        else
            printf("NO\n");
        memset(check, 0, sizeof(int)*(n+1));
        for (int a = 1; a <= n; ++a) {
            arr[a].clear();
        }
    }
    

    return 0;
}
