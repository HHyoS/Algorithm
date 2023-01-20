#include<iostream>

using namespace std;

long long K, P, N;
void input() {
    cin >> K >> P >> N;
}

long long solve() {
    long long ans = K;
    for (int a = 0; a < N; ++a) {
        ans = (ans * P) % 1000000007;
    }
    return ans;
    
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
