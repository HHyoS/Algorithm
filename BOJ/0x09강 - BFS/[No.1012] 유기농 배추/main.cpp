#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;


struct Node {
	int x;
	int y;
};
int K;
int N, M;
int T;

bool field[55][55]; // 배추 정보
bool visited[55][55]; // 방문 체크용

queue<Node> que;

int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; // 상 우 하 좌 탐색
void bfs(int x, int y) { // 연결된 모든 배추를 연결시켜보자
	que.push({ x,y });
	visited[x][y] = 1;

	while (!que.empty()) {
		Node nNode = que.front();
		que.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = nNode.x + mov[i][0];
			int ny = nNode.y + mov[i][1];

      // 맵을 벗어나거나, 배추가 없거나, 이미 방문했던 배추라면 스킵
			if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
			if (field[nx][ny] == 0) continue;
			if (visited[nx][ny]) continue;

			que.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}
}

void Solve() {
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (field[i][j] && !visited[i][j]) { // 배추가 있고, 아직 방문하지 않은 위치라면
				bfs(i, j); // 연결된 모든 배추를 탐색하고
				++ans; // 배추흰지렁이 한마리 추가
			}
		}
	}
	cout << ans << "\n"; // 정답
}

void Input() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> M >> K;
    // TC가 돌 때 마다 초기화 해주기
		memset(field, 0, sizeof(field));
		memset(visited, 0, sizeof(visited));

    // 배추 정보 입력
		for (int j = 0; j < K; ++j) {
			int x, y;
			cin >> x >> y;
			field[x][y] = 1;
		}
    // 알고리즘 실행
		Solve();
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	return 0;
}
