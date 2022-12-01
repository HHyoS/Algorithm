#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

int n, m;
unsigned int ar[8];

using namespace std;
void dfs(int deep,string answer) {
    for (int a = 0; a < n; ++a) {
        if (deep == m) {
            printf("%s\n",answer.c_str());
            break;
        }
        else {
            dfs(deep + 1, answer+to_string(ar[a]) + " ");
        }
    }
}
int main() {

    scanf("%d%d", &n, &m);
    for (int a = 0; a < n; ++a)
        scanf("%d", &ar[a]);
    sort(ar, ar + n);
    for (int a = 0; a < n; ++a) {
        dfs(1, to_string(ar[a])+" ");
    }

    return 0;
}
