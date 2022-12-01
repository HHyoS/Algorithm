#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

int n, m;
unsigned int ar[8];
using namespace std;
int arr[8];
int b = 0;
void dfs(int deep,string answer, unsigned int v, int index) {
    if (deep + 1 == m) 
        printf("%s\n", (answer + to_string(v)).c_str());
    else 
        dfs(deep + 1, answer + to_string(v) + " ", v, index);
    if (index+1 < b) {
        dfs(deep, answer, ar[arr[index]], index+1 );
    }

}
int main() {

    scanf("%d%d", &n, &m);
    for (int a = 0; a < n; ++a)
        scanf("%d", &ar[a]);
    sort(ar, ar + n);
    int a = 0;
    while (a < n) {
        a = upper_bound(ar, ar + n, ar[a]) - ar;
        arr[b++] = a;
    }
    dfs(0, "", ar[0], 0);
    return 0;
}
