#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
    int x;
    int y;
};
string temp, original;
char map[6][6];
bool used[27];
Node alpa[27];
string solve() {
    string target = original;
    for (int a = 0; a < target.size()-1; a+=2) {
        if (target[a] == target[a + 1]) {
            if (target[a] == 'X') {
                target = target.substr(0,a+1)+"Q"+target.substr(a+1);
            }
            else {
                target = target.substr(0, a + 1) + "X" + target.substr(a + 1);
            }
        }
    }
    if (target.size() % 2 == 1) {
        target = target + "X";
    }

    for (int a = 0; a < target.size(); a += 2) {
        int first = target[a]-'A';
        int second = target[a + 1]-'A';

        if (alpa[first].x == alpa[second].x) {
            int x = alpa[first].x;
            int firstIndex = (alpa[first].y + 1) % 5;
            int secondIndex = (alpa[second].y + 1) % 5;
            target[a] = map[x][firstIndex];
            target[a + 1] = map[x][secondIndex];
        }
        else if (alpa[first].y == alpa[second].y) {
            int y = alpa[first].y;
            int firstIndex = (alpa[first].x + 1) % 5;
            int secondIndex = (alpa[second].x + 1) % 5;
            target[a] = map[firstIndex][y];
            target[a + 1] = map[secondIndex][y];
        }
        else {
            int firstY = alpa[first].y;
            int secondY = alpa[second].y;
            target[a] = map[alpa[first].x][secondY];
            target[a + 1] = map[alpa[second].x][firstY];
        }
    }
    return target;
}
void input() {
    cin >> original >> temp;
    int x = 0;
    int y = 0;
    for (int a = 0; a < temp.size(); ++a) {
        if (used[temp[a]-'A'] == 0) {
            used[temp[a]-'A'] = 1;
            map[x][y] = temp[a];
            alpa[temp[a] - 'A'] = { x,y };
            ++y;
            if (y >= 5) {
                ++x;
                y = 0;
            }
        }
    }
    int j = 'J' - 'A';
    for (int a = 0; a < 27; ++a) {
        if (a == j) continue;
        if (used[a] == 1) continue;
        used[a] = 1;
        map[x][y] = 'A' + a;
        alpa[a] = { x,y };
        ++y;
        if (y >= 5) {
            ++x;
            y = 0;
        }
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
