
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int T;
int x, y, d, g;
bool map[102][102];

vector<int> arrow;
int mov[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
void run() {
    int size = arrow.size();

    for (int a = size-1; a >=0 ; --a) {
        int position = (arrow[a] + 1) % 4;
        x = x + mov[position][0];
        y = y + mov[position][1];
        map[x][y] = 1;
        arrow.push_back(position);
    }

}
void input() {
    cin >> T;
    for (int a = 0; a < T; ++a) {
        cin >> y >> x >> d >> g;

        map[x][y] = 1;
        x = x + mov[d][0];
        y = y + mov[d][1];
        map[x][y] = 1;
        arrow.push_back(d);
        while (g--) {
            run();
        }
        arrow.clear();

    }
}

bool find(int x, int y) {
    for (int a = 0; a < 2; ++a) {
        for (int b = 0; b < 2; ++b) {
            if (!map[x+a][y+b])
                return 0;
        }
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    input();
    int ans = 0;
    for (int a = 0; a < 101; ++a) {
        for (int b = 0; b < 101; ++b) {
            if (find(a,b))
                ++ans;
        }
    }

    cout << ans;
    return 0;
}
