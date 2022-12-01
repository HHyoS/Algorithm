#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;


int k;
char ar[10] = "         ";
char arr[10] = { "", };
bool check[10] = { 0, };
long long big = -1;
long long sm = -1;

void ch(long long n) {
    long long temp = n;
    int count = 0;
    while (temp > 0) {
        count++;
        temp /= 10;
    }
    if (count == k + 1)
        printf("%lld", n);
    else {
        int c = k + 1 - count;
        for (int a = 0; a < c; ++a) {
            printf("0");
        }
        printf("%lld", n);
    }
}
void dfs(int index) {
    if (k == index) {
        long long t = atoll(ar);
        if (big == -1 || big < t)
            big = t;
        if (sm == -1 || sm > t)
            sm = t;

        return;
    }
    for (int a = 0; a < 10; ++a) {
        if (!check[a]) {
            if ((arr[index] == '>') && (ar[index] > a + '0')) {
                check[a] = 1;
                ar[index+1] = a + '0';
                dfs(index + 1);
                check[a] = 0;
            }
            else if((arr[index] == '<') && (ar[index] < a + '0')) {
                check[a] = 1;
                ar[index+1] = a + '0';
                dfs(index + 1);
                check[a] = 0;
            }
        }
    }
}
int main() {
    scanf("%d", &k);
    for (int a = 0; a < k; ++a) {
        scanf(" %c", &arr[a]);
    }
    for (int a = 0; a < 10; ++a) {
        ar[0] = a + '0';
        check[a] = 1;
        dfs(0);
        check[a] = 0;
    }
    ch(big);
    printf("\n");
    ch(sm);
    return 0;
}
