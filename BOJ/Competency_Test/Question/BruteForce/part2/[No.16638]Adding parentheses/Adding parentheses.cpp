#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define MAX_NODE 100001
vector<int> tree[MAX_NODE];
int	order[MAX_NODE];
int pri[MAX_NODE];
bool vi[MAX_NODE];
int n;

bool cmp(int a, int b) {
	return pri[a] < pri[b];
}

bool solution(int now, int& idx) {
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (vi[next]) continue;
		vi[next] = true;

		if (next != order[++idx]) return false;
		else {
			if(!solution(next, idx)) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		cin >> order[i];
		pri[order[i]] = i + 1;
	}


	for (int i = 1; i <= n; i++) {
		sort(tree[i].begin(), tree[i].end(), cmp);
	}

	int idx = 0;
	if (order[0] == 1) {
		vi[1] = true;
		cout << solution(order[0], idx);
	}
	else cout << 0;
}
