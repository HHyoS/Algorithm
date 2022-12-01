#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

struct Node {
	int x;
	int y;
};
struct T {
	int from;
	int to;
	int cost;
};
int N, M;
int map[11][11];
bool check[11][11];
int mov[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int tot;
int leng[11][11];
int parent[10];



bool operator<(T a, T b) {
	if (a.cost < b.cost) return 0;
	if (a.cost > b.cost) return 1;

	return 0;
}
int Find(int now) {
	if (parent[now] == 0) {
		return now;
	}

	return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {

	int pA = Find(A);
	int pB = Find(B);

	if (pA == pB) return;

	parent[pB] = pA;
}
void finder(int x, int y) {

	int now = map[x][y];
	for (int a = 0; a < 4; ++a) {
		int t = 1;
		while (1) {
			int xx = x + mov[a][0] * t;
			int yy = y + mov[a][1] * t;

			if (xx < 0 || xx >= N || yy < 0 || yy >= M) break;
			if (map[x][y] == map[xx][yy]) break;
			if (map[xx][yy] == 0) {
				++t;
			}
			else {
				if (t <= 2) break;
				int target = map[xx][yy];
				if (leng[now][target] ==0 || leng[now][target] > t-1) {
					leng[now][target] = t-1;
				}
				break;
			}
		}
	}
}


void bfs(int x, int y, int idx) {
	queue<Node> que;
	que.push({ x,y });
	check[x][y] = 1;
	map[x][y] = idx;

	while (!que.empty()) {
		int xx = que.front().x;
		int yy = que.front().y;
		que.pop();

		for (int a = 0; a < 4; ++a) {
			int nx = xx + mov[a][0];
			int ny = yy + mov[a][1];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (map[nx][ny] == 0 || check[nx][ny]) continue;

			que.push({ nx,ny });
			check[nx][ny] = 1;
			map[nx][ny] = idx;
		}
	}
}

void solve() {
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			finder(a, b);
		}
	}

	priority_queue<T> que;
	for (int a = 1; a <= tot; ++a) {
		for (int b = a + 1; b <= tot; ++b) {
			if (leng[a][b] >= 2) {
				que.push({ a,b,leng[a][b] });
			}
		}
	}

	int ans = 0;
	int edge = 0;
	while (!que.empty()) {
		int from = que.top().from;
		int to = que.top().to;
		int cost = que.top().cost;

		que.pop();

		if (Find(from) != Find(to)) {
			ans += cost;
			Union(from, to);
			++edge;
		}
	}
	if (edge+1 != tot)
		cout << -1;
	else
		cout << ans;
}
void input() {
	cin >> N >> M;
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			cin >> map[a][b];
		}
	}

	int cnt = 1;
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			if (map[a][b] == 1 && !check[a][b]) {
				bfs(a, b,cnt);
				++cnt;
			}
		}
	}
	tot = cnt - 1;
	
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
