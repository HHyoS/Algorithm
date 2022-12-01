#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int N;
int map[17][17];

int mov1[2][2] = { {0,1},{1,1} };
int mov2[2][2] = { {1,0},{1,1} };
int mov3[3][2] = { {0,1},{1,0},{1,1} };
int ans = 0;

void dfs(int x2, int y2, int tp) {
	if (x2 == N - 1 && y2 == N - 1) {
		++ans;
		return;
	}

	if (tp == 0) { // 가로
		for (int a = 0; a < 2; ++a) {
			int x = x2 + mov1[a][0];
			int y = y2 + mov1[a][1];
			if (x < 0 || x >= N || y < 0 || y >= N || map[x][y] == 1) continue;
			if (a == 1) {
				if (map[x2][y2 + 1] || map[x2 + 1][y2]) continue;
			}
			if (a == 0)
				dfs(x, y, 0);
			else
				dfs(x, y, 2);
		}
	}
	else if (tp == 1) { // 세로
		for (int a = 0; a < 2; ++a) {
			int x = x2 + mov2[a][0];
			int y = y2 + mov2[a][1];
			if (x < 0 || x >= N || y < 0 || y >= N || map[x][y] == 1) continue;
			if (a == 1) {
				if (map[x2][y2 + 1] || map[x2 + 1][y2]) continue;
			}
			if (a == 0)
				dfs(x, y, 1);
			else
				dfs(x, y, 2);
		}
	}
	else if (tp == 2) { // 대각선
		for (int a = 0; a < 3; ++a) {
			int x = x2 + mov3[a][0];
			int y = y2 + mov3[a][1];
			if (x < 0 || x >= N || y < 0 || y >= N || map[x][y] == 1) continue;
			if (a == 2) {
				if (map[x2][y2 + 1] || map[x2 + 1][y2]) continue;
			}
			dfs(x, y, a);
		}
	}
}
void solve() {
	if (map[N - 1][N - 1])
		return;
	dfs(0, 1, 0);
}
void input() {
	cin >> N;
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < N; ++b) {
			cin >> map[a][b];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	cout << ans;
	return 0;

}
