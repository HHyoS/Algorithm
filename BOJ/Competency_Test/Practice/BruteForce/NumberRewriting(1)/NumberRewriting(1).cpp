#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;


int g(long long n) {
    int count = 0;
    while (n > 0) {
        ++count;
        n /= 10;
    }
    return count;
}
long long gop(int a) {
    long long gop = 9;
    while (a--) {
        gop *= 10;
    }
    return gop;
}
int main() {
    long long v;
    scanf("%lld", &v);
    long long answer = 0;
    int vv = g(v);
    for (int a = 1; a < vv; ++a) {
        answer = answer + a * gop(a - 1);
    };
    int ten = 1;
    while (--vv) {
        ten *= 10;
    }
    ten -= 1;
    answer = answer + (v - ten) * g(v);
    printf("%lld", answer);
    return 0;
}
