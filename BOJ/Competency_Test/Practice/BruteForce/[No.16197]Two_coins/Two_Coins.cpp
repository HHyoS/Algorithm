#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
int N, M;            
char board[22][22]; 
queue<pair<int,int>> coin_1;
queue<pair<int,int>> coin_2;
int mov[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool check[21][21][21][21];

bool two_out(pair<int, int> coin_1, pair<int, int>coin_2) {
	if ((coin_1.first == coin_2.first) && (coin_1.second == coin_2.second))
		return 1;
	if ((board[coin_1.first][coin_1.second] == '-') && (board[coin_2.first][coin_2.second] == '-'))
		return 1;
	return 0;
}
int main() {
	/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/

	//freopen("Input.txt", "r", stdin);
	scanf("%d %d ", &N, &M);
	int x[2], y[2];
	int idx = 0;
	for (int a = 0; a <= N+1; ++a) {
		for (int b = 0; b <= M +1; ++b) {
			board[a][b] = '-';
		}
	}
	for (int a = 1; a <= N; ++a) {
		for (int b = 1; b <= M-1; ++b) {
			scanf("%c", &board[a][b]);
			if (board[a][b] == 'o') {
				x[idx] = a;
				y[idx++] = b;
			}

		}
		scanf("%c ", &board[a][M]);
		if (board[a][M] == 'o') {
			x[idx] = a;
			y[idx++] = M;
		}
	}
/*	for (int a = 0; a <= N + 1; ++a) {
		for (int b = 0; b <= M + 1; ++b) {
			printf("%c ", board[a][b]);
		}
		printf("\n");
	}*/
	coin_1.push({ x[0],y[0] });
	coin_2.push({ x[1],y[1] });
	check[x[0]][y[0]][x[1]][y[1]] = 1;
	int count = 1;
	int answer = 0;
	while (count < 11) {
		int size = coin_1.size();
		for (int a = 0; a < size; ++a) {
			int xx_1 = coin_1.front().first;
			int yy_1 = coin_1.front().second;

			int xx_2 = coin_2.front().first;
			int yy_2 = coin_2.front().second;

			coin_1.pop();
			coin_2.pop();

			for (int b = 0; b < 4; ++b) {
				int xxx_1 = xx_1 + mov[b][0];
				int yyy_1 = yy_1 + mov[b][1];

				int xxx_2 = xx_2 + mov[b][0];
				int yyy_2 = yy_2 + mov[b][1];

				if (two_out({ xxx_1,yyy_1 }, { xxx_2,yyy_2 }))
					continue;

				if (board[xxx_1][yyy_1] == '#') {
					xxx_1 = xx_1;
					yyy_1 = yy_1;
				}
				else {
					if (board[xxx_1][yyy_1] == '-') {
						printf("%d", count);
						return 0;
					}
				}
				if (board[xxx_2][yyy_2] == '#') {
					xxx_2 = xx_2;
					yyy_2 = yy_2;
				}
				else {
					if (board[xxx_2][yyy_2] == '-') {
						printf("%d", count);
						return 0;
					}
				}
				if (!check[xxx_1][yyy_1][xxx_2][yyy_2]) {
					coin_1.push({ xxx_1,yyy_1 });
					coin_2.push({ xxx_2,yyy_2 });
					check[xxx_1][yyy_1][xxx_2][yyy_2] = 1;
				}
			}

		}
		++count;
	}
	printf("-1");
	return 0;
}

