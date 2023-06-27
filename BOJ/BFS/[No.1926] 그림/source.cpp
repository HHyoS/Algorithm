#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <stack>
using namespace std;


struct Node {
	int x;
	int y;
};
bool map[501][501];
bool visited[501][501];
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int largestPaint;
int paintCnt;
int N, M;
void bfs(int x,int y) {
	visited[x][y] = 1;
	queue<Node> que;
	que.push({ x,y });
	int cnt = 1;
	while (!que.empty()) {
		Node now = que.front();
		que.pop();

		for (int a = 0; a < 4; ++a) {
			int nx = now.x + mov[a][0];
			int ny = now.y + mov[a][1];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (map[nx][ny] == 0) continue;
			if (visited[nx][ny]) continue;

			visited[nx][ny] = 1;
			++cnt;
			que.push({ nx,ny });
		}
	}
	largestPaint = max(largestPaint, cnt);
}

void input() {
	cin >> N >> M;
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			cin >> map[a][b];
		}
	}
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < M; ++b) {
			if (map[a][b] && visited[a][b] == 0) {
				++paintCnt;
				bfs(a, b);
			}
		}
	}
	cout << paintCnt << "\n" << largestPaint;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
	
	input();
	return 0;	
}
