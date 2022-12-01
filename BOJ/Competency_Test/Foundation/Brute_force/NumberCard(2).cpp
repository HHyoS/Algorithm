#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int a = 0; a < n; ++a)
        cin >> arr[a];

    sort(arr, arr + n);
    cin >> m;
    int* fd = (int*)malloc(sizeof(int) * m);
    for (int a = 0; a < m; ++a)
        cin >> fd[a];

    for (int a = 0; a < m; ++a) {
        int lower = lower_bound(arr, arr + n, fd[a]) - arr;
        int uper = upper_bound(arr, arr + n, fd[a]) - arr;
        if (arr[lower] == fd[a]) {
            int answer = uper - lower;
            if (answer == 0)
                printf("1 ");
            else
                printf("%d ", answer);
        }
        else
            printf("0 ");
    }
    return 0;
}
