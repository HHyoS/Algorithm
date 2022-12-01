#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int n, m;
int mini = -1;
char arr[1000][1000];
int mov[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int check[1000][1000];
void dfs(int count, int x, int y, int minute) {
	if (count == 6) {
		if ((minute == -1) || (minute < mini))
			mini = minute;
		return;
	}
	if (mini != -1) {
		if (mini < minute + 1) {
			return;
		}
	}
	for (int a = 0; a < 4; ++a) {
		int xx = x + mov[a][0];
		int yy = y + mov[a][1];
		if ((xx >= 0) && (xx < n) && (yy >= 0) && (yy < m)) {
			if (check[xx][yy] <= count) {
				if (arr[xx][yy] == 'X') {
					continue;
				}
				else if (arr[xx][yy] == 'K') {
					arr[xx][yy] = '.';
					check[xx][yy] += count;
					dfs(count +1, xx, yy, minute + 1);
					check[xx][yy] -= count;
					arr[xx][yy] = 'K';

				}
				else {
					check[xx][yy] += count;
					dfs(count, xx, yy, minute + 1);
					check[xx][yy] -= count;
				}
			}
		}
	}
	return;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("Input.txt", "r", stdin);
	cin >> n >> m;
	int s_x = 0, s_y = 0;
	int target = 0;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			cin >> arr[a][b];
			if (arr[a][b] == 'S') {
				s_x = a;
				s_y = b;
			}
		}
	}
	check[s_x][s_y] = 1;
	dfs(1, s_x, s_y, 0);
	cout << mini;
	return 0;
}

