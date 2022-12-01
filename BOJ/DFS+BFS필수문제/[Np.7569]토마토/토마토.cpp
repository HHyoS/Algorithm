#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

struct Tomato {
	int h;
	int x;
	int y;
};
int M, N, H;

int map[101][101][101];
queue<Tomato> que;
int total_tomato = 0;

int mov[6][3] = { {1,0,0},{-1,0,0},{0,-1,0},{0,1,0},{0,0,1},{0,0,-1} };
int bfs() {

	int cnt = 1;
	while (!que.empty()) {
		
		int size = que.size();

		for (int a = 0; a < size; ++a) {
			int h = que.front().h;
			int x = que.front().x;
			int y = que.front().y;
			que.pop();

			for (int b = 0; b < 6; ++b) {
				int hh = h + mov[b][0];
				int xx = x + mov[b][1];
				int yy = y + mov[b][2];

				if (hh >= 0 && hh < H && xx >= 0 && xx < N && yy >= 0 && yy < M && map[hh][xx][yy] == 0) {
					que.push({ hh,xx,yy });
					map[hh][xx][yy] = 1;
					--total_tomato;
				}
			}
		}
		if (total_tomato == 0)
			return cnt;
		++cnt;
	}

	return -1;
}
void input() {
	cin >> M >> N >> H;

	for (int a = 0; a < H; ++a) {
		for (int b = 0; b < N; ++b) {
			for (int c = 0; c < M; ++c) {
				cin >> map[a][b][c];
				if (map[a][b][c] == 0) {
					++total_tomato;
				}
				else if (map[a][b][c] == 1) {
					que.push({ a,b,c, });
				}
			}
		}
	}
	if (total_tomato == 0) {
		cout << 0;
	}
	else {
		cout << bfs();
	}
}
int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	input();
	return 0;

}
