#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int* before = (int*)malloc(sizeof(int) * n);
    for (int a = 0; a < n; ++a)
        before[a] = a + 1;
    do {
        for (int a = 0; a < n; ++a)
            printf("%d ", before[a]);
        printf("\n");
    } while (next_permutation(before, before + n));
    return 0;
}
