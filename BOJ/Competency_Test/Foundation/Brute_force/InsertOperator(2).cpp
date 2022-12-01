#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

int n;
int* arr;
unsigned int* ct;
int big = -1000000001;
int sm = 1000000000;
void dfs(int sum, int index) {
    if (index == n) {
        if (sum < sm)
            sm = sum;
        if (sum > big)
            big = sum;
        return;
    }
    for (int a = 0; a < 4; ++a) {
        if (ct[a] > 0) {
            --ct[a];
            if (a == 0)
                dfs(sum + arr[index], index + 1);
            else if (a == 1)
                dfs(sum - arr[index], index + 1);
            else if (a == 2)
                dfs(sum * arr[index], index + 1);
            else if (a == 3)
                dfs(sum / arr[index], index + 1);
            ++ct[a];
        }
    }
}
int main() {
 //   freopen("input.txt", "r", stdin);
    cin >> n;
    arr = (int*)malloc(sizeof(int) * n);
    ct = (unsigned int*)malloc(sizeof(unsigned int) * 4);
    int count = 0;
    for (int a = 0; a < n; ++a)
        cin >> arr[a];
 
    for (int a = 0; a < 4; ++a) {
        cin >> ct[a];
        count += ct[a];
    }
    dfs(arr[0], 1);
    printf("%d\n%d", big, sm);
    return 0;
}
