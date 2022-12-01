#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int n, m;
int check[8];
unsigned int* ar;
unsigned int* arr;
void dfs(int deep, int index) {
    if (deep == m) {
        for (int a = 0; a < m; ++a)
            printf("%d ", arr[a]);
        printf("\n");
    }
    for (int a = 0; a < n; ++a) {
        if (!check[a]) {
            check[a] = 1;
            arr[deep] = ar[a];
            dfs(deep + 1, index);
            check[a] = 0;
        }
    }
}
int main() {
    //  freopen("input.txt", "r", stdin);

    scanf("%d%d", &n, &m);
    ar = (unsigned int*)malloc(sizeof(unsigned int) * n);
    arr = (unsigned int*)malloc(sizeof(unsigned int) * m);
    for (int a = 0; a < n; ++a)
        scanf("%d", &ar[a]);

    sort(ar, ar + n);
    for (int a = 0; a < n; ++a) {
        check[a] = 1;
        arr[0] = ar[a];
        dfs(1,a);
        check[a] = 0;
    }

    return 0;
}
