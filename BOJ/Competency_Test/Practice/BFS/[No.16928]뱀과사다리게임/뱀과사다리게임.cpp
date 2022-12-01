#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int map[101];
int shortest[101];


int solve() {
	queue<int> que;
	que.push(1);
	shortest[1] = 0;

	int cnt = 1;
	while (!que.empty()) {
		int size = que.size();

		for (int a = 0; a < size; ++a) {
			int now = que.front();
			que.pop();

			for (int b = 1; b <= 6; ++b) {
				int next = now + b;

				if (next > 100) continue;
				if (shortest[next] <= cnt) continue;
				while (map[next] != -1) {
					if (shortest[next] <= cnt) break;
					shortest[next] = cnt;
					next = map[next];
				}
				if (shortest[next] <= cnt) continue;

				if (next == 100) {
					return cnt;
				}
				shortest[next] = cnt;
				que.push(next);
			}
		}
		++cnt;
	}
}
void input() {
	cin >> N >> M;

	for (int a = 1; a <= 100; ++a) {
		shortest[a] = 21e8;
		map[a] = -1;
	}
	for (int a = 0; a < N + M; ++a) {
		int from, to;
		cin >> from >> to;
		map[from] = to;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();


	cout << solve() << "\n";
}
