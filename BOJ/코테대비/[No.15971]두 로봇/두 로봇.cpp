#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



struct Node {
	int idx;
	int cost;
};
int N, pos1, pos2;
vector<vector<Node>> v(100010);
int root[100010];
bool check[100010];
bool checker = 0;
int cnt;
int mini = 21e8;

void dfs(int start, int end, int sum, int max_leng) {

	if (start == end) {
		if(sum-max_leng < mini)
			mini = sum - max_leng;
		return;
	}

	for (int a = 0; a < v[start].size(); ++a) {
		if (!check[v[start][a].idx]) {
			check[v[start][a].idx] = 1;
			dfs(v[start][a].idx, end, sum + v[start][a].cost, max(v[start][a].cost, max_leng));
			check[v[start][a].idx] = 0;
		}

	}
}
void input() {
	cin >> N >> pos1 >> pos2;
	for (int a = 1; a < N; ++a) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
		v[to].push_back({ from,cost });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	if (N == 1)
		mini = 0;
	else
		dfs(pos1, pos2, 0, 0);
	cout << mini;
	return 0;
}
