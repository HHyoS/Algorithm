#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct Node {
	int x;
	int y;
};
int N, M;
int map[9][9];
int ans = -1;
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<Node> virus;
int bfs() {
	
	queue<Node> que;
	bool used[9][9] = {};
	for (int a = 0; a < virus.size(); ++a) {
		que.push(virus[a]);
	}
	int cnt = 0;
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		que.pop();

		for (int a = 0; a < 4; ++a) {
			int xx = x + mov[a][0];
			int yy = y + mov[a][1];

			if (xx >= 0 && xx < N && yy >= 0 && yy < M && map[xx][yy] == 0 && !used[xx][yy]) {
				used[xx][yy] = 1;
				que.push({ xx,yy });
			}
		}
	}

	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			if (map[a][b] == 0 && !used[a][b]) {
				++cnt;
			}
		}
	}


	return cnt;
}
void dfs(int x,int y,int cnt) {
	if (cnt == 3) {
		int num = bfs();
		if (num > ans)
			ans = num;
		return;
	}

	++y;
	if(y >= M){
		y = 0;
		x++;
		if (x >= N)
			return;

	}

	for (int a = x; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			if (a == x && b < y) continue;
			if (map[a][b] == 0) {
				map[a][b] = 1;
				dfs(a, b, cnt + 1);
				map[a][b] = 0;
			}
		}
	}
}

void solve() {
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			if (map[a][b] == 0) {
				map[a][b] = 1;
				dfs(a,b, 1);
				map[a][b] = 0;
			}
		}
	}
}
void input() {
	cin >> N >> M;
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			cin >> map[a][b];
			if (map[a][b] == 2) {
				virus.push_back({ a,b });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	cout << ans;
	return 0;
}
