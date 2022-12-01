#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int ch[201] = { 0, };
int main() {
    int n, k;
    scanf("%d%d", &n,&k);
    for (int a = 0; a <= n; ++a) {
        ch[a] = 1;
    }


    for (int a = 2; a <= k; ++a) {
        for (int b = 1; b <= n; ++b) {
            ch[b] = (ch[b - 1] + ch[b])%1000000000;
        }
    }
    printf("%d", ch[n]);
    return 0;
}
