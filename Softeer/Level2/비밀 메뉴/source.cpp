#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int M, N, K;
int recipe[101];
int command[101];

bool check(int rId) {
    for (int a = 0; a < M; ++a) {
        int idx = a + rId;
        if (command[idx] != recipe[a]) {
            return 0;
        }
    }
    return 1;
}
string solve() {
    for (int a = 0; a <= N - M; ++a) {
        if (command[a] == recipe[0]) {
            if (check(a)) {
                return "secret";
            }
        }
    }
    return "normal";
}
void input() {
    cin >> M >> N >> K;
    for (int a = 0; a < M; ++a) {
        cin >> recipe[a];
    }
    for (int a = 0; a < N; ++a) {
        cin >> command[a];
    }
}
int main(int argc, char** argv)
{

    input();
    cout << solve();
	return 0;
}
