#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int N, K;
string info;
bool used[20001];
void solve() {

    int cnt = 0;
    for (int a = 0; a < N; ++a) {
        if (info[a] == 'H') {
            for (int b = -K; b <= K; ++b) {
                int idx = a + b;
                if (idx < 0 || idx >= N) continue;
                if (info[idx] == 'P' && used[idx] == 0) {
                    used[idx] = 1;
                    ++cnt;
                    break;
                }
            }
        }
    }

    cout << cnt << "\n";
}

void input() {
    cin >> N >> K >> info;
}

int main(int argc, char** argv)
{

    input();
    solve();
	return 0;
}
