#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
#include<tuple>
#include<map>

using namespace std;

// (y,x) : 상 하 좌 우
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int bfs(int start) {
	int cnt = 0;

	queue<int> q;
	q.push(start);

	map<int, int> dist;
	dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		string s_cur = to_string(cur);

		int z = s_cur.find('9');
		int y = z / 3;
		int x = z % 3;

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3) continue;

			int before = y * 3 + x;
			int after = ny * 3 + nx;

			string temp = s_cur;
			swap(temp[before], temp[after]);

			int next = stoi(temp);
			if (dist.count(next) == 0) {
				q.push(next);
				dist[next] = dist[cur] + 1;
			}
		}
	}

	if (dist.count(123456789) == 0) {
		return -1;
	}
	else {
		return dist[123456789];
	}
}

int main() {
	int start = 0;

	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		if (num == 0) num = 9;
		start = start * 10 + num;
	}

	cout << bfs(start) << "\n";
}
