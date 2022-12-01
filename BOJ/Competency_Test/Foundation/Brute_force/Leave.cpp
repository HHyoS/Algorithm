#include <string.h>
#include <vector>
#include <iostream>

using namespace std;
unsigned int n;
unsigned int** arr;
unsigned int big = 0;
void dfs(unsigned int time, unsigned int sum) {
    if (time == n){
        if (sum > big)
            big = sum;
    }
    else {
        dfs(time + 1, sum);
        if (time + arr[time][0] <= n)
            dfs(time + arr[time][0], sum + arr[time][1]);
    }
}
int main() {
 //   freopen("input.txt", "r", stdin);
    cin >> n;
    arr = (unsigned int**)malloc(sizeof(unsigned int*) * n);
    for (unsigned int a = 0; a < n; ++a) {
        unsigned int* temp = (unsigned int*)malloc(sizeof(unsigned int) * 2);
        arr[a] = temp;
        cin >> arr[a][0] >> arr[a][1];
    }
    dfs(0, 0);
    printf("%d", big);
    return 0;
}
