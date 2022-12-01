#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unsigned char* temp = (unsigned char*)malloc(sizeof(unsigned char) * m);
    unsigned char* ar = (unsigned char*)malloc(sizeof(unsigned char) * m);
    for (int a = 0; a < m; ++a) {
        cin >> temp[a];
        if (a < n)
            ar[a] = '1';
        else
            ar[a] = '0';
    }
    sort(temp, temp + m);
    do {
        vector<unsigned char> tt;
        unsigned int mo = 1;
        unsigned int ja = 2;
        
        for (int a = 0; a < m; ++a) {
            if (ar[a] == '1') {
                if (temp[a] == 'a' || temp[a] == 'e' || temp[a] == 'i' || temp[a] == 'o' || temp[a] == 'u') {
                    if (mo != 0)
                        --mo;
                }
                else {
                    if (ja != 0)
                        --ja;
                }
                tt.push_back(temp[a]);
                if ((tt.size() == n) && (ja == 0 && mo == 0)) {
                    for (int b = 0; b < n; ++b) {
                        printf("%c", tt[b]);
                    }
                    printf("\n");
                }
            }
        }
        tt.clear();
    } while(prev_permutation(ar, ar + m));
    return 0;
}
