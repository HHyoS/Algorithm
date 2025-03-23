#include<iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <memory.h>
#include <string>
using namespace std;




struct Node {
	int x;
	int y;
};
int N, K, L;
int mov[4][2] = { {-1,0},{0,1},{1,0}, {0,-1} };
bool apple[110][110];
// empty == 0, body == 1, apple = 2  
int mp[110][110];
vector<Node> body; // 앞은 꼬리, 뒤는 머리
int tIDX = 0; // tail IDX, 꼬리 위치 관리용
Node head;
int snakeHead = 1;

bool Go() { // 그냥 직진
	int nx = head.x + mov[snakeHead][0];
	int ny = head.y + mov[snakeHead][1];


	if (nx > N || nx <= 0 || ny > N || ny <= 0) { // 벽
		return 0;
	}

	if (mp[nx][ny] == 1){ // 몸
		return 0;
	}

	if (mp[nx][ny] == 0) { // 사과가 없다면 꼬리 자르기
		mp[body[tIDX].x][body[tIDX].y] = 0;
		tIDX++;
	}		
	body.push_back({ nx,ny });
	head = { nx,ny };
	mp[nx][ny] = 1;

	return true;

}
int Solve() {
	int nTime = 0;
	body.push_back({1,1}); // 좌표 1,1에 머리는 오른쪽(위 = 0, 오른쪽 = 1, 아래 = 2, 왼쪽은 = 3)
	mp[1][1] = 1;
	head = { 1,1 };
	for (int a = 0; a < L; ++a) {
		int time;
		char command;

		cin >> time >> command;

    // 머리 돌리기 전까지 직진
		while (nTime < time) {
      // 시뮬레이션 결과는 1초 후의 미래임
			++nTime;
      // 일단 가봐
			bool checker = Go();
			if (checker == 0) {
				return nTime;
			}
		}

		if (command == 'L') {
			snakeHead = (snakeHead + 3) % 4;
		}
		else {
			snakeHead = (snakeHead + 1) % 4;
		}
	}

  // command 내에 정리가 안됬다면 무한 loop 시작
	while (1) {
    // 항상 시간은 1초 흐르고 시작
		++nTime;
		bool checker = Go();
		if (checker == 0)
			return nTime;

	}

}


void Input() {
	cin >> N >> K;
	for (int a = 0; a < K; ++a) {
		int x, y;
		cin >> x >> y;
		mp[x][y] = 2;
	}
	cin >> L;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	

	Input();
	cout << Solve();
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
