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
vector<pair<int, int>> tree[100001];
bool check[100001];
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
	freopen("Input.txt", "r", stdin);

	cin >> N;
	int node_1, node_2 = 0, weight;
	for (int a = 1; a <= N; ++a) {
		cin >> node_1;
		while (node_2 != -1) {
			cin >> node_2;
			if (node_2 == -1) {
				node_2 = 0;
				break;
			}
			cin >> weight;
			tree[node_1].push_back({ node_2,weight });
		}
	}
	check[1] = 1;
	dfs(1, 0);
	check[1] = 0;

	check[node] = 1;
	dfs(node, 0);
	cout << big;
	return 0;
}
