#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

int n, m;
unsigned int ar[8];
using namespace std;
bool check[8];
void dfs(int deep,string answer,int index) {
    if (deep == m) {
        printf("%s\n", answer.c_str());
        return;
    }
    for (int a = 0; a < n; ++a) {
        if (!check[a]) {
            check[a] = true;
            dfs(deep + 1, answer + to_string(ar[a]) + " ", 0);
            check[a] = false;
            a = upper_bound(ar, ar + n, ar[a]) - ar -1;
        }
    }
}
int main() {

    scanf("%d%d", &n, &m);
    for (int a = 0; a < n; ++a)
        scanf("%d", &ar[a]);
    sort(ar, ar + n);

    dfs(0, "", 0);
    return 0;
}
