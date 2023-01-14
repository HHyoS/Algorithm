#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int transmission[9];

string solve() {
    int before = transmission[1];
    if (before == 1) {
        for (int a = 2; a <= 8; ++a) {
            if (before + 1 != transmission[a])
                return "mixed";
            before = transmission[a];
        }
        return "ascending";
    }
    else if (before == 8) {
        for (int a = 2; a <= 8; ++a) {
            if (before - 1 != transmission[a])
                return "mixed";
            before = transmission[a];
        }
        return "descending";
    }
    else {
        return "mixed";
    }
}
void input() {
    int before = 0;
    int flag = 0;
    for (int a = 1; a <= 8; ++a) {
        int tmp;
        cin >> transmission[a];
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    cout << solve();

	return 0;
}
