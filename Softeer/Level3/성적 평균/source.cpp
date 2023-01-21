#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

double grade[1000001];
double memo[1000001];
int N, K;
void solve() {
    for (int a = 0; a < K; ++a) {
        int start, end;
        cin >> start >> end;
        double temp = (memo[end] - memo[start - 1])/(double(end-start+1));
        cout << temp << "\n";
    }
}
void input() {
    cin >> N >> K;
    memo[0] = 0;
    for (int a = 1; a <= N; ++a) {
        cin >> grade[a];
        memo[a] = memo[a - 1] + grade[a];
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    input();
    cout << fixed;
    cout.precision(2);
    solve();
	return 0;
}
