#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int map[101][101];
void input() {
    for (int t = 1; t <= 10; ++t) {
        int tt;
        cin >> tt;
        int x = 0, y= 0;
        for (int a = 0; a < 100; ++a) {
            for (int b = 0; b < 100; ++b) {
                cin >> map[a][b];
                if (map[a][b] == 2) {
                    x = a;
                    y = b;
                }
            }
        }
        while (x != -1) {
            
            if (y >= 0 && map[x][y - 1] == 1) {
                --y;
                while (1) {
                    if (y < 0 || map[x][y] == 0) {
                        ++y;
                        break;
                    }
                    --y;
                }
            }
            else if (y < 100 && map[x][y + 1] == 1) {
                ++y;
                while (1) {
                    if (y > 99 || map[x][y] == 0) {
                        --y;
                        break;
                    }
                    ++y;
                }
            }
            --x;
        }
        cout << "#"<<tt<<" "<<y << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    return 0;
}
