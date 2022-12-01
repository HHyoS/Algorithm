#include <cstdio>

int n, m;
char ar[16] = "               ";
void dfs(int deep) {
    for (int a = 0; a < n; ++a) {
        if (deep + 2 == m) {
            ar[deep] = '1' + a;
            printf("%s\n",ar);
        }
        else {
            ar[deep] = '1' + a;
            dfs(deep + 2);
        }
    }
}
int main() {
    //  freopen("input.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    m += m;
    ar[m] = 0;
    dfs(0);

    return 0;
}
