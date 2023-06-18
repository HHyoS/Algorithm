#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M;
int Map[400][400];
bool visited[400][400];
int mnum = 0;

vector <pair<int, int>> v;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void melting() {
	int x, y, nx, ny;
	int tmp[400][400];

	for (int a = 0; a < v.size(); ++a) {
		x = v[a].first;
		y = v[a].second;
		if (Map[x][y] == 0) continue;

		int cnt = 0;
		for (int b = 0; b < 4; ++b) {
			nx = x + dx[b];
			ny = y + dy[b];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (Map[nx][ny] == 0)cnt++;
		}

		if (Map[x][y] - cnt <= 0) {
			mnum--;
			tmp[x][y] = 0;
		}
		else tmp[x][y] = Map[x][y] - cnt;
	}

	for (int a = 0; a < v.size(); ++a) {
		if (Map[v[a].first][v[a].second] == 0) continue;
		Map[v[a].first][v[a].second] = tmp[v[a].first][v[a].second];
	}
}

void dfs(int x, int y) {
	visited[x][y] = true;

	int nx, ny;
	for (int a = 0; a < 4; ++a) {
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny]) continue;
		if (Map[nx][ny] > 0) {
			dfs(nx,ny); 
		}
	}
}

bool chuck() {
	int cnt = 0;
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			if (!visited[a][b] && Map[a][b] > 0) {
				dfs(a, b);
				cnt++;
			}
		}
	}
	if (cnt >= 2) return true;
	else return false;
}

void Solve() {
	int year = 0;
	while (1) {
		year++;
		melting();
		if (mnum == 0) {
			cout << 0 << endl;
			return;
		}
		memset(visited, false, sizeof(visited));//visited 초기화
		if (chuck()) {
			cout << year << endl;
			return;
		}
	}

}

int main() {
	cin >> N >> M;
	for (int a = 0; a < N; ++a)
		for (int b = 0; b < M; ++b) {
			cin >> Map[a][b];
			if (Map[a][b] != 0) {
				v.push_back({ a,b});
				mnum++;
			}
		}

	Solve();

	return 0;
}
