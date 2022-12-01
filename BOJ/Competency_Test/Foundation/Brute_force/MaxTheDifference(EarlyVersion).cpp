#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int* before = (int*)malloc(sizeof(int) * n);
    for (int a = 0; a < n; ++a)
        cin >> before[a];
    sort(before, before + n);
    int big = 0;
    do {
        int sum = 0;
        for (int a = 0; a < n-1; ++a) {
            if (before[a] - before[a + 1] < 0)
                sum += (before[a + 1] - before[a]);
            else
                sum += (before[a] - before[a + 1]);
        }
        if (sum > big)
            big = sum;
    } while (next_permutation(before, before + n));
    printf("%d", big);
    return 0;
}
