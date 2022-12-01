#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 8
int** ar;
int n;
int big = 0;
void dfs(int now, int after,bool check[], int sum, int deep) {
    check[after] = true;
    sum += ar[now][after];
    if (deep == n) {
        if (big < sum)
            big = sum;
        return;
    }
    
    for (int a = 0; a < n; ++a) {
        if (check[a] == false) {
            dfs(after, a, check, sum, deep+1);
            check[a] = false;
        }
    }
}
int main() {
    cin >> n;
    int* before = (int*)malloc(sizeof(int) * n);
    ar = (int**)malloc(sizeof(int*) * n);
    bool* check = (bool*)malloc(sizeof(bool) * n);
    for (int a = 0; a < n; ++a) {
        cin >> before[a];
        ar[a] = (int*)malloc(sizeof(int) * n);
    }
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            if (a != b) {
                if (before[a] - before[b] < 0)
                    ar[a][b] = before[b] - before[a];
                else
                    ar[a][b] = before[a] - before[b];
            }
        }
    }
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            if (a != b) {
                memset(check, false, sizeof(check));
                check[a] = true;
                dfs(a, b, check, 0, 2);
            }
        }
    }
    printf("%d", big);
    return 0;
}
