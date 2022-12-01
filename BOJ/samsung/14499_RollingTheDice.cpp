#include <string>
#include <map>
#include <utility>
#include <iostream>
using namespace std;

pair<int,int> move(int command, pair<int, int> xy, int M, int N) {
	switch(command){
		case 1:
			if (xy.second + 1 < M)
				xy.second = xy.second + 1;
			break;
		case 2 :
			if (xy.second - 1 >= 0)
				xy.second = xy.second - 1;
			break;
		case 3 :
			if (xy.first - 1 >= 0)
				xy.first = xy.first - 1;
			break;
		case 4 :
			if (xy.first + 1 < N)
				xy.first = xy.first + 1;
			break;
	}
	return xy;
}
int main() {
	int ju[4][6] = { {1,5,0,3,4,2},{2,0,5,3,4,1},{4,1,2,0,5,3} ,{3,1,2,5,0,4} };
	int n, m, x, y, c;
	int jusa[6] = { 0,0,0,0,0,0 };
	int temp[6];
	cin >> n >> m >> x >> y >> c;
	map<pair<int, int>, int> mp;
	int q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> q;
			mp[{i, j}] = q;
		}
	}
	pair<int, int > ttemp;
	pair<int, int > now = { x, y };
	for (int i = 0; i < c; ++i) {
		int command;
		cin >> command;
		ttemp = move(command, now, m, n);
		if (!((now.first == ttemp.first) && (now.second == ttemp.second))){
			now = ttemp;
			for (int d = 0; d < 6; ++d)
				temp[d] = jusa[d];

			for (int j = 0; j < 6; ++j) {
				jusa[j] = temp[ju[command-1][j]];
			}
			if (mp[now] == 0)
				mp[now] = jusa[0];
			else {
				jusa[0] = mp[now];
				mp[now] = 0;
			}
				printf("%d\n", jusa[5]);
		}

	}
	return 0;
}
