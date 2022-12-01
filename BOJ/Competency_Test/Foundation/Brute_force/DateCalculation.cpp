#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int a = 1,b = 1,c = 1.;
    int years = 1;
    while (true) {
        if (a == x && b == y && c == z)
            break;
        ++a; ++b;++c;
        if (a == 16)
            a = 1;
        if (b == 29)
            b = 1;
        if (c == 20)
            c = 1;
        ++years;

    }
    printf("%d", years);
    return 0;
}
