#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

struct Node {
	int x;
	int y;
	int dust;
};
int R, C,T;
int map[51][51];
bool flag;
queue<Node> que;
int tx, ty;
int mov[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };


void print() {
	int ans = 0;
	while (!que.empty()) {
		ans += que.front().dust;
		que.pop();
	}
	cout << ans;
}
void cleaner(int x, int y) {

	for (int a = x; a > 0; --a) {
		map[a][y] = map[a - 1][y];
	}

	for (int a = 0; a < C-1; ++a) {
		map[0][a] = map[0][a + 1];
	}
	for (int a = 0; a < x; ++a) {
		map[a][C - 1] = map[a + 1][C - 1];
	}

	for (int a = C - 1; a > 1; --a) {
		map[x][a] = map[x][a - 1];
	}
	map[x][1] = 0;
	map[x][y] = -1;

	int xx = x + 1;
	int yy = y;

	for (int a = xx; a < R-1; ++a) {
		map[a][yy] = map[a + 1][yy];
	}

	for (int a = 0; a < C - 1; ++a) {
		map[R - 1][a] = map[R - 1][a + 1];
	}

	for (int a = R - 1; a > xx ; --a) {
		map[a][C - 1] = map[a - 1][C - 1];
	}

	for (int a = C - 1; a > 1; --a) {
		map[xx][a] = map[xx][a - 1];
	}

	map[xx][yy + 1] = 0;
	map[xx][yy] = -1;

	for (int a = 0; a < R; ++a) {
		for (int b = 0; b < C; ++b) {
			if (map[a][b] > 0) {
				que.push({ a,b,map[a][b] });
				map[a][b] = 0;
			}
		}
	}
}
void bfs() {
	
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int dust = que.front().dust;
		que.pop();
		int wind = dust / 5;
		if (wind != 0) {
			for (int a = 0; a < 4; ++a) {
				int xx = x + mov[a][0];
				int yy = y + mov[a][1];

				if (xx >= 0 && xx < R && yy >= 0 && yy < C && map[xx][yy] >= 0) {
					map[xx][yy] += wind;
					dust -= wind;
				}
			}
		}
		map[x][y] += dust;
	}

	cleaner(tx,ty);

}

void input() {
	cin >> R >> C >> T;

	int tmp;
	for (int a = 0; a < R; ++a) {
		for (int b = 0; b < C; ++b) {
			cin >> tmp;
			if (tmp > 0) {
				que.push({ a,b,tmp });
				map[a][b] = 0;
			}
			else {
				map[a][b] = tmp;
				if (tmp == -1 && flag == 0) {
					tx = a;
					ty = b;
					flag = 1;
				}
			}
		}
	}

}

void solve() {
	while (T--) {
		bfs();
	}
	print();
}
int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	return 0;

}
