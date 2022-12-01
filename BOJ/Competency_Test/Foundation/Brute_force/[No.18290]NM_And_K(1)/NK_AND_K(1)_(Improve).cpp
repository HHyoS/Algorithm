#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;
#define MIN -1000001
int n, m, k;

int arr[11][11];
int able[11][11];
int cant[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int big = MIN;
void dfs(int x, int y, int num, int count) {
	if(count == k){
		if (big < num) {
			big = num;
		}
		return;
	}
	++y;
	if (y == m) y = 0, ++x;
	if (x == n) return;

	if (able[x][y] == 0) {
		dfs(x, y, num, count);
		for (int c = 0; c < 4; ++c) {
			if ((x + cant[c][0] >= 0) && (x + cant[c][0] < n) && (y + cant[c][1] >= 0) && (y + cant[c][1] < m)) {
				++able[x + cant[c][0]][y + cant[c][1]];
			}
		}
		++able[x][y];
		dfs(x, y, num + arr[x][y], count + 1);
		--able[x][y];

		for (int c = 0; c < 4; ++c) {
			if ((x + cant[c][0] >= 0) && (x + cant[c][0] < n) && (y + cant[c][1] >= 0) && (y + cant[c][1] < m)) {
				--able[x + cant[c][0]][y + cant[c][1]];
			}
		}
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("Input.txt", "r", stdin);

	cin >> n >> m >> k;

	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			cin >> arr[a][b];
		}
	}
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {

			for (int c = 0; c < 4; ++c) {
				if ((a + cant[c][0] >= 0) && (a + cant[c][0] < n) && (b + cant[c][1] >= 0) && (b + cant[c][1] < m)) {
					++able[a + cant[c][0]][b + cant[c][1]];
				}
			}
			++able[a][b];
			dfs(a, b, arr[a][b], 1);
			--able[a][b];


			for (int c = 0; c < 4; ++c) {
				if ((a + cant[c][0] >= 0) && (a + cant[c][0] < n) && (b + cant[c][1] >= 0) && (b + cant[c][1] < m)) {
					--able[a + cant[c][0]][b + cant[c][1]];
				}
			}
		}
	}
	cout << big;

	return 0;
}
