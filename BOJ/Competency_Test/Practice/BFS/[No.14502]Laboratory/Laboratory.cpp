#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int n,m;
int arr[8][8];
int big = -1;
int mov[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int vir[64][2];
int idx = 0;
void dfs(int x, int y, int count) {
	if (count == 3) {
		queue<pair<int, int>> que;
		for (int a = 0; a < idx; ++a) {
			que.push({ vir[a][0],vir[a][1] });
		}
		int cpy[8][8];
		memcpy(cpy, arr, sizeof(arr));
		while (!que.empty()) {
			int size = que.size();
			for (int a = 0; a < size; ++a) {
				int xx = que.front().first;
				int yy = que.front().second;
				que.pop();
				for (int b = 0; b < 4; ++b) {
					int xxx = xx + mov[b][0];
					int yyy = yy + mov[b][1];
					if ((xxx >= 0) && (xxx < n) && (yyy >= 0) && (yyy < m)) {
						if (cpy[xxx][yyy] == 0) {
							cpy[xxx][yyy] = 2;
							que.push({ xxx,yyy });
						}
					}
				}
			}
		}
		int answer = 0;
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < m; ++b) {
				if (cpy[a][b] == 0)
					++answer;
			}
		}
		if (answer > big) {
			big = answer;
		}
	}
	else {
		++y;
		if(y >= m){
			y = 0;
			++x;
			if (x >= n)
				return;
		}
		if (arr[x][y] == 0) {
			arr[x][y] = 1;
			dfs(x, y, count + 1);
			arr[x][y] = 0;
		}
		dfs(x, y, count);

	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("Input.txt", "r", stdin);

	cin >> n >> m;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			cin >> arr[a][b];
			if (arr[a][b] == 2) {
				vir[idx][0] = a;
				vir[idx][1] = b;
				++idx;
			}
		}
	}


	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			if (arr[a][b] == 0) {
				arr[a][b] = 1;
				dfs(a, b, 1);
				arr[a][b] = 0;
			}
		}
	}
	cout << big;
	return 0;
}

