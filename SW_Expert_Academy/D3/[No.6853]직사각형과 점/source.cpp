#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
   
int T;
int N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   // freopen("Input.txt", "r", stdin);
   
    cin >> T;
   
    register int x1, y1, x2, y2, tx, ty, t, a;
    register unsigned int n1 = 0, n2 = 0, n3 = 0;
    for (register unsigned t = 1; t <= T; ++t) {
        cin >> x1 >> y1 >> x2 >> y2 >> N;
        n1 = n2 = n3 = 0;
        for (register unsigned a = 0; a < N; ++a) {
            cin >> tx >> ty;
            if (tx < x1 || tx > x2 || ty < y1 || ty > y2)
                ++n3;
            else if (tx > x1 && tx < x2 && ty > y1 && ty < y2)
                ++n1;
            else
                ++n2;
        }
        cout << "#" << t << " " << n1 << " " << n2 << " " << n3 <<"\n";
    }
   
   
    return 0;
}
