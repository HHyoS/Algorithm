#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
bool checker[101];
vector<vector<int>> virus(101);
int solve() {

	queue<int> que;
	checker[1] = 1;
	que.push(1);
	int cnt = 0;
	while (!que.empty()) {
		int idx = que.front();
		que.pop();

		for (int a = 0; a < virus[idx].size(); ++a) {
			if (!checker[virus[idx][a]]) {
				que.push(virus[idx][a]);
				checker[virus[idx][a]] = 1;
				++cnt;
			}
		}
	}
	return cnt;
}
void input() {
	cin >> N >> M;

	for (int a = 0; a < M; ++a) {
		int from,to;
		cin >> from >> to;
		virus[from].push_back(to);
		virus[to].push_back(from);
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

	output(solve());
	return 0;
}
