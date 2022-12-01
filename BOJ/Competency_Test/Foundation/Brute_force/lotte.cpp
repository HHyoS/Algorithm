#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    
    unsigned int n;
    unsigned int* ar;
    unsigned int* arr;
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        else {
            ar = (unsigned int*)malloc(sizeof(unsigned int) * n);
            arr = (unsigned int*)malloc(sizeof(unsigned int) * n);
            for (int a = 0; a < n; ++a) {
                cin >> ar[a];
                if (a < 6)
                    arr[a] = 1;
                else
                    arr[a] = 0;
            }
            sort(arr, arr + n, greater<int>());
            do {
                for (unsigned int a = 0; a < n; ++a) {
                    if (arr[a] == 1)
                        printf("%d ", ar[a]);
                }
                printf("\n");
            } while (prev_permutation(arr, arr + n));
        }
        printf("\n");
        free(ar);
        free(arr);
    }
    return 0;
}
