#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <int> vec[100001];
int n, r, q;
int dp[100001];

int dfs(int n) {
	if (dp[n] != -1)
		return dp[n];
	
	int& ret = dp[n];	
	ret = 1;
	for (int a = 0; a < vec[n].size(); ++a) {
		int next = vec[n][a];
		if (dp[next]!= -1)
			continue;
		ret += dfs(next);
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> r >> q;
	for (int a = 0; a < n - 1; ++a) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int a = 1; a <= n; ++a)
		dp[a] = -1;
	dp[r] = dfs(r);
	for (int a = 0; a < q; ++a) {
		int c;
		cin >> c;
		cout << dp[c] << "\n";
	}


	return 0;
}
