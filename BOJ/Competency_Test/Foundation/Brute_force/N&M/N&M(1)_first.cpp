#include <string.h>
#include <iostream>
using namespace std;
int n, m;
char ar[8];
int check[8];
void dfs(int deep) {
    if (deep == m) {
        for (int a = 0; a < m; ++a) {
            cout << ar[a] << " ";
        }
        cout << "\n";
    }
    for (int a = 0; a < n; ++a) {
        if (!check[a]) {
            ar[deep] = 49 + a;
            check[a] = 1;
            dfs(deep + 1);
            check[a] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    //  freopen("input.txt", "r", stdin);

    cin >> n >> m;

    memset(check, false, sizeof(check));


    for (int a = 0; a < n; ++a) {
        check[a] = 1;
        ar[0] = 49 +a;
        dfs(1);
        check[a] = 0;
    }

    return 0;
}
