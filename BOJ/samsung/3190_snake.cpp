#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <queue>
using namespace std;
int n = 0;
int big = 0;
int size = 0;


int main() {
	char mov = 'R';
//	freopen("Input.txt", "r", stdin);
	cin >> n;
	int count;
	map<pair<int, int>, char> mp;
	pair<int, int> head = { 1,1 };
	char command = 'R';
	int x, y;
	cin >> count;
	vector<pair<int, int>> ap;
	queue<pair<int, int>> tail;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			mp[{a, b}] = 'g';
		}
	}
	for (int a = 0; a < count; ++a) {
		cin >> x >> y;
		mp[{x, y}] = 'A';
	}
	mp[{1, 1}] = 'H';
	int move;
	cin >> move;
	int time = 0;
	for (int a = 0; a < move; ++a) {
		int sec;
		char direc;
		cin >> sec >> direc;
		while (!(sec - time == 0)) {
			++time;
			pair<int, int> temp = head;
			if (command == 'R') {
				head.second += 1;
			}
			else if (command == 'L') {
				head.second -= 1;
			}
			else if (command == 'U') {
				head.first -= 1;
			}
			else if (command == 'D') {
				head.first += 1;
			}

			if (head.first > n || head.second > n || mp[head] == 'B' || head.first <1 || head.second < 1) {
				printf("%d", time);
				return 0;
			}
			else if(mp[head] == 'A') {
				mp[head] = 'H';
				mp[temp] = 'B';
				tail.push(temp);
			}
			else if(mp[head] == 'g'){
				mp[head] = 'H';
				if (!tail.empty()) {
					mp[tail.front()] = 'g';
					tail.push(temp);
					mp[temp] = 'B';
					tail.pop();
				}
				else
					mp[temp] = 'g';

			}
		}
		if (command == 'R') {
			if (direc == 'L')
				command = 'U';
			else
				command = 'D';
		}
		else if(command == 'L'){
			if (direc == 'L')
				command = 'D';
			else
				command = 'U';
		}
		else if(command == 'U') {
			if (direc == 'L')
				command = 'L';
			else
				command = 'R';
		}
		else if(command == 'D') {
			if (direc == 'L')
				command = 'R';
			else
				command = 'L';

		}
	}while (true) {
		++time;
		pair<int, int> temp = head;
		if (command == 'R') {
			head.second += 1;
		}
		else if (command == 'L') {
			head.second -= 1;
		}
		else if (command == 'U') {
			head.first -= 1;
		}
		else if (command == 'D') {
			head.first += 1;
		}

		if (head.first > n || head.second > n || mp[head] == 'B' || head.first < 1 || head.second < 1) {
			printf("%d", time);
			return 0;
		}
		else if (mp[head] == 'A') {
			mp[head] = 'H';
			mp[temp] = 'B';
			tail.push(temp);
		}
		else if (mp[head] == 'g') {
			mp[head] = 'H';
			if (!tail.empty()) {
				mp[tail.front()] = 'g';
				tail.push(temp);
				mp[temp] = 'B';
				tail.pop();
			}
			else
				mp[temp] = 'g';

		}
	}
	printf("%d", time);
	return 0;
}
