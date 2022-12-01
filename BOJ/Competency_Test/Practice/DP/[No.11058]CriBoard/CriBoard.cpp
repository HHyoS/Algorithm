#include <cstdio>
 
using namespace std;
 
long long d[101];
 
int Max(int x, int y) {
    if (x < y) return y;
    else return x;
}
 
int main() {
    int n;
    scanf("%d", &n);
    d[0] = 0;
    for (int a = 1; a <= n; ++a) {
        d[a] = d[a-1] + 1;
        for (int b = 3; b <= a; ++b) {
            if (d[a] < d[a-b]*(b-1)) d[a] = d[a-b]*(b-1);
        }
    }
    printf("%lld\n", d[n]);
}
