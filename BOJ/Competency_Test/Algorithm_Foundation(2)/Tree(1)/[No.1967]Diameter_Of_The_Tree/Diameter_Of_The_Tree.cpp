#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> tree[10001];
bool check[10001];
int big = 0;
int node;

void dfs(int now, int sum) {
	if (sum > big) {
		big = sum;
		node = now;
	}
	for (int a = 0; a < tree[now].size(); ++a) {
		if (!check[tree[now][a].first]) {
			check[tree[now][a].first] = 1;
			dfs(tree[now][a].first, sum + tree[now][a].second);
			check[tree[now][a].first] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);

	cin >> N;
	int parent, child, weight;
	for (int a = 0; a < N-1; ++a) {
		cin >> parent >> child >> weight;
		tree[parent].push_back({ child,weight });
		tree[child].push_back({ parent,weight });
	}
	check[1] = 1;
	dfs(1, 0);
	check[1] = 0;

	check[node] = 1;
	dfs(node, 0);
	cout << big;
	return 0;
}
