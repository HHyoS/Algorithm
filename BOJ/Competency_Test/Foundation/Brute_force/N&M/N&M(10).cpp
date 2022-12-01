#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

int n, m;
unsigned int ar[8];
using namespace std;
bool check[8];
void sort() {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (ar[i] > ar[j]) {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
}
void dfs(int deep,string answer,int index) {
    if (deep == m) {
        printf("%s\n", answer.c_str());
        return;
    }
    for (int a = index; a < n; ++a) {
        if (!check[a]) {
            if (deep + 1 == m)
                printf("%s\n", (answer + to_string(ar[a])).c_str());
            else {
                check[a] = true;
                dfs(deep + 1, answer + to_string(ar[a]) + " ", a + 1);
                check[a] = false;
            }
            a = upper_bound(ar + a, ar + n, ar[a]) - ar - 1;
        }
    }
}
int main() {

    scanf("%d%d", &n, &m);
    for (int a = 0; a < n; ++a)
        scanf("%d", &ar[a]);
 //   sort(ar, ar + n);
    sort();
    dfs(0, "", 0);
    return 0;
}
