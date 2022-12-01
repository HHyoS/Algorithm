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
vector<int> tree[100001];
int parent[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("Input.txt", "r", stdin);

	cin >> N;
	int nd_1, nd_2;
	for (int a = 0; a < N; ++a) {
		cin >> nd_1 >> nd_2;
		tree[nd_1].push_back(nd_2);
		tree[nd_2].push_back(nd_1);
	}
	parent[1] = -1;
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int size = que.size();
		for (int a = 0; a < size; ++a) {
			int idx = que.front();
			que.pop();
			for (int b = 0; b < tree[idx].size(); ++b) {
				if (!parent[tree[idx][b]]) {
					parent[tree[idx][b]] = idx;
					que.push(tree[idx][b]);
				}
			}
		}
	}
	for (int a = 2; a <= N; ++a) {
		cout << parent[a] << "\n";
	}
	return 0;
}
