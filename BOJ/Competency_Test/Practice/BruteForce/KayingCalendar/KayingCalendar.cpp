#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;



bool arr[40001] = { 0, };
int main() {
    int v;
    scanf("%d", &v);
    for (int a = 0; a < v; ++a) {

        int n, m, x, y;

        int year = 0;
        scanf("%d %d %d %d", &m,&n,&x,&y);
        year = x - 1;
        while(true){
        if (!arr[year % n + 1]) {
            if (year % n + 1 == y)
                break;
            else {
                arr[year % n + 1] = 1;
                year += m; 
            }

        }
        else
            break;
        }
    if (year % n + 1 == y)
        printf("%d\n", year+1);
    else
        printf("-1\n");

    memset(arr, 0, sizeof(arr));
    }
    return 0;
}
