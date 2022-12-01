#include <cstdio>
#include <algorithm>
using namespace std;

int ar[100000] = { 0, };

int main() {
    int n;
    scanf("%d", &n);
    for (int a = 0; a < n; ++a) {
        scanf("%d", &ar[a]);
    }
    for (int a = 1; a < n; ++a) {
        ar[a] = max(ar[a-1]+ar[a], ar[a]);
    }
    printf("%d", *max_element(ar, ar + n));
    return 0;
}
