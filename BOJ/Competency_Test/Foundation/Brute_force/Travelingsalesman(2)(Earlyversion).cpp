#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 8
int** ar;
int n;
int small = 999999999;
void dfs(int start, int now, int after,bool check[], int sum, int deep) {
    check[after] = true;
    sum += ar[now][after];
    if (deep == n) {
        if (ar[after][start] != 0) {
            if (small > sum + ar[after][start])
                small = sum + ar[after][start];
        }
        return;
    }
    
    for (int a = 0; a < n; ++a) {
        if (check[a] == false && ar[after][a] != 0) {
            if (deep == n - 1) {
                if (ar[a][start] != 0)
                    dfs(start, after, a, check, sum, deep + 1);
            }
            else
                dfs(start, after, a, check, sum, deep + 1);
            check[a] = false;
        }
    }
}
int main() {
    cin >> n;
    ar = (int**)malloc(sizeof(int*) * n);
    bool* check = (bool*)malloc(sizeof(bool) * n);
    for (int a = 0; a < n; ++a) {
        ar[a] = (int*)malloc(sizeof(int) * n);
    }
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b)
            cin >> ar[a][b];
    }
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            if (a != b && ar[a][b] != 0) {
                memset(check, false, sizeof(check));
                check[a] = true;
                dfs(a,a, b, check, 0, 2);
            }
        }
    }
    printf("%d", small);
    return 0;
}
