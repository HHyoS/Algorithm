#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int ch[100000+1] = { 0, };
int main() {
    int n;
    scanf("%d", &n);
    for (int a = 1; a <= n; ++a) {
        if (a <= 316)
            ch[a * a] = 1;

        if (ch[a] == 0)
            ch[a] = a;
        
    }
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <=sqrt(a); ++b) {
            if (ch[a] != 1)
                ch[a] = min(ch[a], ch[a - (b*b)] + 1);
            }
    }
    printf("%d", ch[n]);
    return 0;
} // 통과는 됬으나 개선부분 수정예정
