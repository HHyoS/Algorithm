#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v(101);
int parent[101];
bool checker[101];
int N, M;
int t1, t2;
int ans = -1;
bool check;
void input() {
	cin >> N >> t1 >> t2 >> M;
	for (int a = 0; a < M; ++a) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		parent[to] = from;
	}
}

void dfs(int idx, int cnt) {
	if (check)
		return;
	checker[idx] = 1;
	if (parent[idx] != 0 && !checker[parent[idx]]) {
		if (parent[idx] == t2) {
			check = 1;
			ans = cnt + 1;
			return;
		}
		dfs(parent[idx], cnt + 1);
	}

	for (int a = 0; a < v[idx].size(); ++a) {
		if (v[idx][a] == t2) {
			ans = cnt + 1;
			check = 1;
			return;
		}
		else if (!checker[v[idx][a]]) {
			dfs(v[idx][a], cnt + 1);
		}
	}
}
void output(int cnt) {
	cout << cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	dfs(t1, 0);
	cout << ans;
	return 0;
}
