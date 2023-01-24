#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

long long N, K, P;
long long timer[1000];
long long gopMemo[1000];
long long gop = 1;
int maxi;
void solve() {

    long long ans = 1;
    long long namuziTime = N;
    while (1) {

        for (int a = maxi; a > 0; --a) {
            if (timer[a] <= namuziTime) {
                namuziTime -= timer[a];
                ans = (ans * gopMemo[a]) % 1000000007;
                maxi = a;
                break;
            }
        }
        if (namuziTime == 0)
            break;
    }
    cout << (K*ans) % 1000000007;
}
void input() {
    cin >> K >> P >> N;
    for (int a = 0; a < 10; ++a) {
        gop = (gop * P) % 1000000007;
    }
    
    int index = 2;
    long long sec = 2;
    long long target = gop;
    timer[1] = 1;
    gopMemo[1] = gop;
    while (sec <= N) {
        target = (target * target) % 1000000007;
        timer[index] = sec;
        gopMemo[index++] = target;
        sec = sec << 1;
    }
    maxi = index - 1;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   input();
    solve();
	return 0;
}
