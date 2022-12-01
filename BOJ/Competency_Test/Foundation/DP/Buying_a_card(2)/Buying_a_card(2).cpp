#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int arr[1001] = { 0,};
    int n;

    scanf("%d",&n);
    for (int a = 1; a <= n; ++a) {
        scanf("%d", &arr[a]);
    }
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= a; ++b) {
                arr[a] = min(arr[a], arr[b] + arr[a-b]);
            
        }
    }
    printf("%d", arr[n]);
    return 0;
}
