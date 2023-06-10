#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <stack>
using namespace std;

struct Info {
	int index;
	int cost;
};
int dist[1001];
int path[1001];
int minCost[1001][1001];
int N, M;
int start,target;
vector<Info> bus[1001];

bool operator<(Info a, Info b) {
	if (a.cost == b.cost) {
		return a.index > b.index;
	}
	return a.cost > b.cost;
}
void solve() {
	priority_queue<Info> que;
	que.push({ start,0 });
	dist[start] = 0;

	while (!que.empty()) {
		int nowCost = que.top().cost;
		int nowIndex = que.top().index;
		que.pop();
		if (nowCost > dist[nowIndex]) continue;

		for (int a = 0; a < bus[nowIndex].size(); ++a) {
			int nextIndex = bus[nowIndex][a].index;
			int nextCost = nowCost + bus[nowIndex][a].cost;
			if (nextCost >= dist[nextIndex]) continue;
			path[nextIndex] = nowIndex;
			dist[nextIndex] = nextCost;
			que.push({ nextIndex,nextCost });
		}
	}
	vector<int> temp;
	temp.push_back(target);
	while (1) {
		if (path[temp.back()] == 0) break;
		temp.push_back(path[temp.back()]);
	}
	cout << dist[target] << "\n" << temp.size() << "\n";
	int size = temp.size() - 1;
	for (int a = size; a >= 0; --a) {
		cout << temp[a] << " ";
	}

}

void input() {
	cin >> N >> M;
	for (int a = 1; a <= N; ++a) {
		dist[a] = 21e8;
		for (int b = 1; b <= N; ++b) {
			minCost[a][b] = 21e8;
		}
	}
	for (int a = 0; a < M; ++a) {
		int from, to, ccost;
		cin >> from >> to >> ccost;
		if (minCost[from][to] > ccost)
			minCost[from][to] = ccost;
	}
	for (int a = 1; a <= N; ++a) {
		for (int b = 1; b <= N; ++b) {
			if (minCost[a][b] == 21e8) continue;
			bus[a].push_back({ b,minCost[a][b] });
		}
	}
	cin >> start >> target;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	
	input();
	solve();
	return 0;	
}
