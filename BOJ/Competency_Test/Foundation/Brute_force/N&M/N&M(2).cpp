#include <cstdio>

int n, m;
char ar[16] = "               ";
void dfs(int deep, int index) {
    if (deep == m) {
        printf("%s\n", ar);
        return;
    }
    for (int a = index+1; a < n; ++a) {
            ar[deep] = '1' + a;
            dfs(deep + 2,a);
        }
}
int main() {
    //  freopen("input.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    m += m;
    ar[m] = 0;
    for (int a = 0; a < n; ++a) {
        ar[0] = '1' + a;
        dfs(2, a);
    }

    return 0;
}
