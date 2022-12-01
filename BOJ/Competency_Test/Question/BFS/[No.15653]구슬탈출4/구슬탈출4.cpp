#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node {
	int x;
	int y;
};
int N, M;
char map[11][11];
bool check[11][11][11][11]; // blue /red순
queue<Node> blue;
queue<Node> red;

bool checker;
int cnt;
void left(int rx, int ry, int bx, int by) {

	int nry = ry;
	int nby = by;

	while (1) {
		nry -= 1;
		if (map[rx][nry] != '#') {
			if (map[rx][nry] == 'O')
				break;
			else
				continue;
		}
		else {
			nry += 1;
			break;
		}
	}
	while (1) {
		nby -= 1;
		if (map[bx][nby] != '#') {
			if (map[bx][nby] == 'O')
				return;
			else
				continue;
		}
		else {
			nby += 1;
			break;
		}
	}
	if (rx == bx && nry == nby) {
		if (ry < by) {
			nby = nby + 1;
		}
		else {
			nry = nry + 1;
		}
	}
	if (map[rx][nry] == 'O') {
		checker = 1;
		return;
	}
	if (check[rx][nry][bx][nby])
		return;
	else {
		check[rx][nry][bx][nby] = 1;
		red.push({ rx,nry });
		blue.push({ bx,nby });
	}
}
void right(int rx, int ry, int bx, int by) {

	int nry = ry;
	int nby = by;

	while (1) {
		nry += 1;
		if (map[rx][nry] != '#') {
			if (map[rx][nry] == 'O')
				break;
			else
				continue;
		}
		else {
			nry -= 1;
			break;
		}
	}
	while (1) {
		nby += 1;
		if (map[bx][nby] != '#') {
			if (map[bx][nby] == 'O')
				return;
			else
				continue;
		}
		else {
			nby -= 1;
			break;
		}
	}
	if (rx == bx && nry == nby) {
		if (ry > by) {
			nby = nby - 1;
		}
		else {
			nry = nry - 1;
		}
	}
	if (map[rx][nry] == 'O') {
		checker = 1;
		return;
	}
	if (check[rx][nry][bx][nby])
		return;
	else {
		check[rx][nry][bx][nby] = 1;
		red.push({ rx,nry });
		blue.push({ bx,nby });
	}
}
void up(int rx, int ry, int bx, int by) {

	int nrx = rx;
	int nbx = bx;

	while (1) {
		nrx -= 1;
		if (map[nrx][ry] != '#') {
			if (map[nrx][ry] == 'O')
				break;
			else
				continue;
		}
		else {
			nrx += 1;
			break;
		}
	}
	while (1) {
		nbx -= 1;
		if (map[nbx][by] != '#') {
			if (map[nbx][by] == 'O')
				return;
			else
				continue;
		}
		else {
			nbx += 1;
			break;
		}
	}
	if (nrx == nbx && ry == by) {
		if (rx < bx) {
			nbx = nbx + 1;
		}
		else {
			nrx = nrx + 1;
		}
	}
	if (map[nrx][ry] == 'O') {
		checker = 1;
		return;
	}
	if (check[nrx][ry][nbx][by])
		return;
	else {
		check[nrx][ry][nbx][by] = 1;
		red.push({ nrx,ry });
		blue.push({ nbx,by });
	}
}

void down(int rx, int ry, int bx, int by) {

	int nrx = rx;
	int nbx = bx;

	while (1) {
		nrx += 1;
		if (map[nrx][ry] != '#') {
			if (map[nrx][ry] == 'O')
				break;
			else
				continue;
		}
		else {
			nrx -= 1;
			break;
		}
	}
	while (1) {
		nbx += 1;
		if (map[nbx][by] != '#') {
			if (map[nbx][by] == 'O')
				return;
			else
				continue;
		}
		else {
			nbx -= 1;
			break;
		}
	}
	if (nrx == nbx && ry == by) {
		if (rx >bx) {
			nbx = nbx - 1;
		}
		else {
			nrx = nrx - 1;
		}
	}
	if (map[nrx][ry] == 'O') {
		checker = 1;
		return;
	}
	if (check[nrx][ry][nbx][by])
		return;
	else {
		check[nrx][ry][nbx][by] = 1;
		red.push({ nrx,ry });
		blue.push({ nbx,by });
	}
}
int bfs() {
	check[blue.front().x][blue.front().y][red.front().x][red.front().y] = 1;

	cnt = 1;
	while (!red.empty()) {


		int size = red.size();
		for (int i = 0; i < size; ++i) {
			int rX = red.front().x;
			int rY = red.front().y;
			int bX = blue.front().x;
			int bY = blue.front().y;
			red.pop();
			blue.pop();

			for (int a = 0; a < 4; ++a) {
				if (a == 0) {
					left(rX, rY, bX, bY);
				}
				else if (a == 1) {
					right(rX, rY, bX, bY);
				}
				else if (a == 2) {
					up(rX, rY, bX, bY);
				}
				else {
					down(rX, rY, bX, bY);
				}

				if (checker) {
					return cnt;
				}
			}
		}
		++cnt;
	}

	return -1;
}
void input() {
	cin >> N >> M;
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			cin >> map[a][b];
			if (map[a][b] == 'B') {
				blue.push({ a,b });
				map[a][b] = '.';
			}
			else if (map[a][b] == 'R') {
				red.push({ a,b });
				map[a][b] = '.';
			}
			else
				continue;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	cout << bfs();
	return 0;
}
