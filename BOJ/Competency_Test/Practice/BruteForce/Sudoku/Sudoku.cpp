#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int N, M;
int map[9][9];
vector<pair<int,int>> blank;
int check = 0;

void sdoc_print() {

    for (int a = 0; a < 9; ++a) {
        for (int b = 0; b < 9; ++b) {
            cout << map[a][b] << " ";
        }
        cout << "\n";
    }
    check = 1;

    return;
}
bool row_check(int row,int num) {
    for (int a = 0; a < 9; ++a) {
        if (map[row][a] == num)
            return 0;
    }
    return 1;
}
bool col_check(int col,int num) {
    for (int a = 0; a < 9; ++a) {
        if (map[a][col] == num)
            return 0;
    }
    return 1;
}
bool sdoc_check(int x, int y, int num) {
    int xx = (x / 3) * 3;
    int yy = (y / 3) * 3;
    for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
            if (map[xx + a][yy + b] == num)
                return 0;
        }
    }
    return 1;
}
void dfs(int x, int y, int idx) {
    for (int a = 1; a <= 9; ++a) {
        if (row_check(x, a) && col_check(y, a) && sdoc_check(x, y, a)) {
            map[x][y] = a;
            if (idx >= blank.size()) {
                sdoc_print();
                check = 1;
                break;
            }
            dfs(blank[idx].first, blank[idx].second, idx + 1);
            if (check)
                return;
            map[x][y] = 0;
        }

    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("Input.txt","r", stdin);
    for (int a = 0; a < 9; ++a) {
        for (int b = 0; b < 9; ++b) {
            cin >> map[a][b];
            if (map[a][b] == 0)
                blank.push_back({ a,b });
        }
    }
    if (blank.size() == 0) {
        for (int a = 0; a < 9; ++a) {
            for (int b = 0; b < 9; ++b) {
                cout << map[a][b] << " ";
            }
            cout << "\n";
        }
        return 0;
    }

    dfs(blank[0].first, blank[0].second,1);
    return 0;

}
