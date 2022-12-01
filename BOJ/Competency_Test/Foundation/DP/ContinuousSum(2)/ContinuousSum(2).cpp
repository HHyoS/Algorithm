#include <cstdio>
#include <algorithm>
using namespace std;

int ar[100000][2] = { 0, };

int main() {
    int n;
    scanf("%d", &n);
    for (int a = 0; a < n; ++a) {
        scanf("%d", &ar[a][0]);
    }
    ar[0][1] = ar[0][0];
    int big = ar[0][0];
    for (int a = 1; a < n; ++a) {
        ar[a][1] = max(ar[a - 1][0], ar[a - 1][1] + ar[a][0]);
        ar[a][0] = max(ar[a][0], ar[a - 1][0]+ar[a][0]);
    }
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < 2; ++b) {
            if (big < ar[a][b]){
                big = ar[a][b];
            }
        }
    }
    printf("%d", big);
    return 0;
}
