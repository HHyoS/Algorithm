#include <cstdio>

int n, m;
char ar[16]= "               ";
int check[8];
void dfs(int deep) {
    if (deep == m) {
        printf("%s\n",ar);
        return;
    }
    for (int a = 0; a < n; ++a) {
        if (!check[a]) {
            ar[deep] = '1' + a;
            check[a] = 1;
            dfs(deep+2);
            check[a] = 0;
        }
    }
}
int main() {
    //  freopen("input.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    m += m;
    ar[m] = 0;
    for (int a = 0; a < n; ++a) {
        check[a] = 1;
        ar[0] = '1' + a;
        dfs(2);
        check[a] = 0;
    }

    return 0;
}
