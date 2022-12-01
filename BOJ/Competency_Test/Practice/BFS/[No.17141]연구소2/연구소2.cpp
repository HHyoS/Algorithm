#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

struct Node {
	int x;
	int y;
};
int N, M;
int map[51][51];
bool checker[51][51];
vector<Node> virus;
int room_counter = 0;
vector<Node> choice;
int mov[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int mini = 21e8;
int bfs() {
	if (room_counter == 0)
		return 0;
	queue<Node> que;
	bool checker[51][51] = {};
	for (int a = 0; a < M; ++a) {
		que.push(choice[a]);
		checker[choice[a].x][choice[a].y] = 1;
	}
	int cnt = 1;
	int rooms = 0;
	while (!que.empty()) {
		int size = que.size();
		for (int a = 0; a < size; ++a) {
			int x = que.front().x;
			int y = que.front().y;
			que.pop();

			for (int b = 0; b < 4; ++b) {
				int xx = x + mov[b][0];
				int yy = y + mov[b][1];

				if (xx >= 0 && xx < N && yy >= 0 && yy < N && map[xx][yy] == 0 && !checker[xx][yy]) {
					++rooms;
					if (rooms == room_counter)
						return cnt;

					checker[xx][yy] = 1;
					que.push({ xx,yy });
				}
			}
		}
		++cnt;
	}
	return 21e8;
}
void dfs(int idx, int count) {
	if (count == M) {
		int temp =bfs();
		if (temp < mini) {
			mini = temp;
		}
		return;
	}

	if (virus.size() - idx - 1 + count < M) return;
	for (int a = idx + 1; a < virus.size(); ++a) {
		choice.push_back(virus[a]);
		dfs(a, count + 1);
		choice.pop_back();
	}
}
void solve() {

	for (int a = 0; a < virus.size(); ++a) {
		choice.push_back(virus[a]);
		dfs(a, 1);
		choice.pop_back();
	}
}
void input() {
	cin >> N >> M;

	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < N; ++b) {
			cin >> map[a][b];
			if (map[a][b] == 0) {
				++room_counter;
			}
			else if (map[a][b] == 2) {
				map[a][b] = 0;
				virus.push_back({ a,b });
			}
		}
	}

	room_counter = room_counter + virus.size() - M;
}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	if (mini == 21e8)
		cout << -1;
	else
		cout << mini;
	return 0;

}
