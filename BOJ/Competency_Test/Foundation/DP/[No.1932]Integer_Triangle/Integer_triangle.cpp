#include <iostream>
#include <algorithm>

using namespace std;

int n;
int tri[502] = { 0, };
int dp[502];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("Input.txt", "r", stdin);
	cin >> n;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= a; ++b) 
			cin >> tri[b];
		for (int b = a; b >= 1; --b) {
			dp[b] = max(dp[b], dp[b - 1]) + tri[b];
		}
	}
	cout << *max_element(dp+1,dp + n+1);

	return 0;
}
