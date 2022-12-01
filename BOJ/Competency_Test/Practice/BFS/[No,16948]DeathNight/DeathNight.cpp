#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n;
bool check[200][200];
int mv[6][2] = { {-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1} };
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("Input.txt", "r", stdin);
	cin >> n;
	
	queue<pair<int,int>> que;
	int answer = 0;
	int x, y, t_x, t_y;
	cin >> x >> y >> t_x >> t_y;
	check[x][y] = 1;
	que.push({ x,y });
	while (!que.empty()) {
		int size = que.size();
		for (int a = 0; a < size; ++a) {
			int xx = que.front().first;
			int yy = que.front().second;
			que.pop();
			for (int b = 0; b < 6; ++b) {
				int xxx = xx + mv[b][0];
				int yyy = yy + mv[b][1];
				if ((xxx >= 0) && (xxx < n) && (yyy >= 0) && (yyy < n)) {
					if (!check[xxx][yyy]) {
						if ((xxx == t_x) && (yyy == t_y)) {
							++answer;
							cout << answer;
							return 0;
						}
						check[xxx][yyy] = 1;
						que.push({ xxx,yyy });
					}
				}
			}
		}
		++answer;
	}
	cout << "-1";
	return 0;
}

