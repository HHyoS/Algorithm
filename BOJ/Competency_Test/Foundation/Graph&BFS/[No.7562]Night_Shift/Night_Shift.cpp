#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
bool map[301][301] = { 0, };
int mmove[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("Input.txt", "r", stdin);
	cin >> n;
	int x, y;
	int tar, gett;
	queue<pair<int, int>> que;
	for (int a = 0; a < n; ++a) {
		cin >> m >> x >> y >> tar >> gett;
		que.push({ x,y });
		memset(map, 0, sizeof(map));
		int count = 0;
		while (!que.empty()) {
			int size = que.size();
			for (int a = 0; a < size; ++a) {
				x = que.front().first;
				y = que.front().second;
				que.pop();
				if ((x == tar) && (y == gett)) {
					cout << count << "\n";
					que = queue<pair<int, int>>();
					break;
				}
				for (int a = 0; a < 8; ++a) {
					if ((x + mmove[a][0] >= 0) && (x + mmove[a][0] < m) && (y + mmove[a][1] >= 0) && (y + mmove[a][1] < m)) {
						if (!map[x + mmove[a][0]][y + mmove[a][1]]) {
							que.push({ x + mmove[a][0], y + mmove[a][1] });
							map[x + mmove[a][0]][y + mmove[a][1]] = 1;
						}
					}
				}
			}
			++count;
		}
	}
	return 0;
}
