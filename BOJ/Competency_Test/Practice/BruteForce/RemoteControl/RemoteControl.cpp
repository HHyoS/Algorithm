#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define M 1000000
bool p[10] = { 0, };

int cal(int v) {
    int count = 0;
    if (v == 0) {
        if (p[0] == 0)
            return 1;
        else
            return -1;
    }
    
    while (v > 0) {
        if (p[v % 10] == 0) {
            v /= 10;
            ++count;
        }
        else {
            return -1;
        }
    }
    return count;
}
int main() {
    int n,m;
    scanf("%d%d", &n,&m);
    int answer = abs(100 - n);
    if (m > 0) {
        int a;
        while (m--) {
            scanf("%d", &a);
            p[a] = 1;
        }
    }
    for (int a = n; a >= 0; --a) {
        if ((cal(a) != -1)) {
            if (cal(a) + abs(n - a) < answer)
                answer = cal(a) + abs(n - a);
            else
                break;
        }
    }
    for (int a = n; a <= M; ++a) {
        if ((cal(a) != -1)){
            if (cal(a) + abs(n - a) < answer)
                answer = cal(a) + abs(n - a);
            else
                break;
        }
    }
    printf("%d", answer);
    return 0;
}
