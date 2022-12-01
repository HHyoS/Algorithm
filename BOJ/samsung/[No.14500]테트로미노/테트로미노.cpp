#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int map[501][501];
int N, M;
int maxi = 0;
int mov[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int T[4][4][2] = { {{0,0},{0,1},{0,2},{1,1}},{{0,0},{0,1},{-1,1},{1,1}},{{0,0},{0,1},{0,2},{-1,1}},{{0,0},{1,0},{2,0},{1,1} } };
int check[501][501];
void dfs(int deep,int x,int y,int sum) {
	if (deep == 4) {
		if (sum > maxi)
			maxi = sum;
		return;
	}

	for (int a = 0; a < 4; ++a) {
		int xx = x+mov[a][0];
		int yy = y+mov[a][1];

		if (xx >= 0 && xx < N && yy >= 0 && yy < M && !check[xx][yy]) {
			check[xx][yy] = 1;
			dfs(deep + 1, xx, yy, sum + map[xx][yy]);
			check[xx][yy] = 0;
		}
	}

}

void input() {
	cin >> N >> M;

	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			cin >> map[a][b];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			check[i][j] = 1;
			dfs(1, i, j, map[i][j]);
			check[i][j] = 0;
			for (int a = 0; a < 4; ++a) {
				int tot = 0;
				for (int b = 0; b < 4; ++b) {
					int xx = i + T[a][b][0];
					int yy = j + T[a][b][1];

					if (xx >= 0 && xx < N && yy >= 0 && yy < M) {
						tot += map[xx][yy];
					}
					else {
						tot = -1;
						break;
					}
				}
				if (tot != -1 && tot > maxi)
					maxi = tot;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	input();
	cout << maxi;
	return 0;

}
