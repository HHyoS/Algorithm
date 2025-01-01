#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


int stone;
string name[2];
void Solve() {

	int turn = (1 + stone / 3)%2; // 3이상이면 연산의 횟수를 줄이기 위해 미리 빼주기
	stone = stone % 3;
	while (stone) {
		stone -= 1;
		turn = (turn + 1) % 2;
	}
	if (stone == 0) { // stone의 마지막을 가져간 사람 출력
		cout << name[turn];
	}

	return;
}
void Input() {
	cin >> stone;
	name[0] = "SK";
	name[1] = "CY";
}
int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
    return 0;
}
