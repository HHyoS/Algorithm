#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

int n, m;
unsigned int ar[8];
unsigned int answer[8];

using namespace std;
void dfs(int deep, int index) {
    if (deep == m) {
        for (int a = 0; a < m; ++a)
            printf("%d ", answer[a]);
        printf("\n");
        return;
    }
    for (int a = index + 1; a < n; ++a) {
        answer[deep] = ar[a];
        dfs(deep + 1, a);
    }
}
int main() {

    scanf("%d%d", &n, &m);
    for (int a = 0; a < n; ++a)
        scanf("%d", &ar[a]);

    sort(ar, ar + n);
    for (int a = 0; a < n; ++a) {
        answer[0] = ar[a];
        dfs(1, a);

    }

    return 0;
}
