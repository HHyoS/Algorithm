#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int* before = (int*)malloc(sizeof(int) * n);
    int t;
    for (int a = 0; a < n; ++a)
        cin >> before[a];
    if (next_permutation(before, before+n)) {
        for (int a = 0; a < n; ++a) {
            printf("%d ", before[a]);
        }
    }
    else
        printf("-1");
    return 0;
}
