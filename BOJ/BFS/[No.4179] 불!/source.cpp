#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <stack>
using namespace std;


struct Node {
	int x;
	int y;
};
char map[1011][1011];
bool visited[1001][1001];
bool burn[1001][1001];
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int N, M;

queue<Node> jihoon;
queue<Node> fire;
int bfs() {
	int cnt = 1;
	while (!jihoon.empty()) {
		int size = fire.size();
		for (int s = 0; s < size; ++s) {
			Node nowFire = fire.front();
			fire.pop();

			for (int a = 0; a < 4; ++a) {
				int x = nowFire.x + mov[a][0];
				int y = nowFire.y + mov[a][1];

				if (map[x][y] == '#') continue;
				if (burn[x][y]) continue;
				if (x < 0 || x >= N || y < 0 || y >= M) continue;

				fire.push({ x,y });
				burn[x][y] = 1;
			}
		}

		size = jihoon.size();
		for (int s = 0; s < size; ++s) {
			Node nowJihoon = jihoon.front();
			jihoon.pop();

			for (int a = 0; a < 4; ++a) {
				int x = nowJihoon.x + mov[a][0];
				int y = nowJihoon.y + mov[a][1];

				if (map[x][y] == '#') continue;
				if (visited[x][y] || burn[x][y]) continue;
				if (x < 0 || x >= N || y < 0 || y >= M) {
					return cnt;
				}

				jihoon.push({ x,y });
				visited[x][y] = 1;
			}
		}
		++cnt;
	}

	return -1;
}

void solve() {
	int result = bfs();
	if (result == -1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << result;
	}
}
void input() {
	cin >> N >> M;
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			cin >> map[a][b];
			if (map[a][b] == 'J') {
				jihoon.push({ a,b });
				map[a][b] = '.';
				visited[a][b] = 1;
			}
			else if (map[a][b] == 'F') {
				fire.push({ a,b });
				burn[a][b] = 1;
			}
		}
	}
	solve();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	input();
	return 0;
}
