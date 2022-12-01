#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int target;
vector<vector<int>> v;
int arr[100001];
int start;
bool ans;
int idx=1;
bool check[100001];
bool comp(int a, int b) {
	if (arr[a] < arr[b]) return 1;
	if (arr[a] > arr[b]) return 0;

	return 1;
}

void dfs(int num) {
	if (idx == N) {
		ans = 1;
		return;
	}
	for (int a = 0; a < v[num].size(); ++a) {
		if (check[v[num][a]]) continue;
		if (arr[v[num][a]] != idx) return;
		
		++idx;
		check[v[num][a]] = 1;
		dfs(v[num][a]);
	}
}
void solve() {
	check[1] = 1;
	dfs(1);

}
void input() {
	cin >> N;

	v.assign(N + 1, vector<int>());
	for (int a = 0; a < N - 1; ++a) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int a = 0; a < N; ++a) {
		int tmp;
		cin >> tmp;
		if (a == 0) {
			start = tmp;
		}
		arr[tmp] = a;
	}

	for (int a = 1; a <= N; ++a) {
		if (v[a].size() > 1)
			sort(v[a].begin(), v[a].end(), comp);
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	if (arr[1] != 0)
		cout << 0;
	else {
		if (ans == 0)
			cout << 0;
		else
			cout << 1;
	}
	return 0;
}
