#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

int N, R;
bool comeback[110];

void Solve() {
    bool flag = false;
    for (int a = 1; a <= N; ++a) {
        if (comeback[a] == false) {
            flag = true;
            cout << a << " ";
        }
    }
    if (flag == false) {
        cout << "*";
    }
}


void Input() {
    cin >> N >> R;
    for (int a = 0; a < R; ++a) {
        int target;
        cin >> target;
        comeback[target] = true;
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
