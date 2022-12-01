#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m, k;
int dice[6] = { 0, };// 순서대로 상,하,동,서,남,북
int map[20][20];
int x, y;
void dong() {
	if (y + 1 >= m)
		return;
	else {
		int temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[1];
		cout << dice[0] << "\n";
		if (map[x][y + 1] == 0) {
			dice[1] = dice[2];
			map[x][y + 1] = dice[1];
		}
		else {
			dice[1] = map[x][y + 1];
			map[x][y + 1] = 0;
		}
		dice[2] = temp;
	}
	++y;
	return;

}
void su() {
	if (y <= 0)
		return;
	else {
		int temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[1];
		cout << dice[0] << "\n";
		if (map[x][y - 1] == 0) {
			dice[1] = dice[3];
			map[x][y - 1] = dice[1];
		}
		else {
			dice[1] = map[x][y - 1];
			map[x][y - 1] = 0;
		}
		dice[3] = temp;
	}
	--y;
	return;

}
void nam() {
	if (x + 1 >= n)
		return;
	else {
		int temp = dice[0];
		dice[0] = dice[5];
		dice[5] = dice[1];
		cout << dice[0] << "\n";
		if (map[x + 1][y] == 0) {
			dice[1] = dice[4];
			map[x + 1][y] = dice[1];
		}
		else {
			dice[1] = map[x + 1][y];
			map[x + 1][y] = 0;
		}
		dice[4] = temp;
	}
	++x;
	return;

}
void book() {
	if (x - 1 < 0)
		return;
	else {
		int temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		cout << dice[0] << "\n";
		if (map[x - 1][y] == 0) {
			dice[1] = dice[5];
			map[x - 1][y] = dice[1];
		}
		else {
			dice[1] = map[x - 1][y];
			map[x - 1][y] = 0;
		}
		dice[5] = temp;
	}
	--x;
	return;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//	freopen("Input.txt", "r", stdin);
	cin >> n >> m >> x >> y >> k;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			cin >> map[a][b];
		}
	}
	int command;
	while (k--) {
		cin >> command;
		switch (command) {
		case 1:
			dong();
			break;
		case 2:
			su();
			break;
		case 3:
			book();
			break;
		case 4:
			nam();
			break;
		default:
			break;
		}
	}
	return 0;
}

