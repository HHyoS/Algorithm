#include <stdio.h>
using namespace std;
int main() {
    int n;
    int arr[1000000 + 1] = { 0,1,2,4, };
    scanf("%d",&n);
    int target;
    int index = 3;
    for (int a = 0; a < n; ++a) {
        scanf("%d", &target);
        if (target > index) {
            for (int b = index + 1; b <= target; ++b) {
                arr[b] = ((arr[b - 2] + arr[b - 3]) % 1000000009+arr[b - 1]) % 1000000009;
            }
            index = target;
            printf("%d\n", arr[target]);
        }
        else
            printf("%d\n", arr[target]);
    }

    return 0;
}
