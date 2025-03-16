#include<iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <memory.h>
using namespace std;



int N;
bool pick[51];
char player[51];
queue<int> teamA;
queue<int> teamB;
void Solve() {
	bool turn = true;
	int cnt = 0;
	while (cnt != N) {
		if (turn) {
			while (!teamA.empty()) {
				if (pick[teamA.front()] == false) {
					player[teamA.front()] = 'A';
					pick[teamA.front()] = true;
					teamA.pop();
					++cnt;
					break;
				}
				else {
					teamA.pop();
				}
			}
		}
		else {
			while (!teamB.empty()) {
				if (pick[teamB.front()] == false) {
					player[teamB.front()] = 'B';
					pick[teamB.front()] = true;
					teamB.pop();
					++cnt;
					break;
				}
				else {
					teamB.pop();
				}
			}
		}
		turn = !turn;
	}
	for (int a = 1; a <= N; ++a) {
		cout << player[a];
	}
}

void init() {
	memset(player, 0, sizeof(player));
	memset(pick, 0, sizeof(pick));
	while (!teamA.empty()) {
		teamA.pop();
	}

	while (!teamB.empty()) {
		teamB.pop();
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N;
		for (int a = 0; a < N; ++a) {
			int temp;
			cin >> temp;
			teamA.push(temp);
		}
		for (int a = 0; a < N; ++a) {
			int temp;
			cin >> temp;
			teamB.push(temp);
		}

		Solve();
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
