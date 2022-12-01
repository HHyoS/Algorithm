

#include <iostream>
#include <deque>
#include <math.h>
using namespace std;

deque <bool> wheels[4];

void Rotate(int num, int rotate_dir, int spread_dir) {
	
	if (spread_dir == 0 || spread_dir == 1) {
		if (num > 0) {
			if (wheels[num][6] != wheels[num - 1][2])
				Rotate(num - 1, -1 * rotate_dir, 0);
		}
	}
	if (spread_dir == 1 || spread_dir == 2) {
		if (num < 3) {
			if (wheels[num][2] != wheels[num + 1][6])
				Rotate(num + 1, -1 * rotate_dir, 2);
		}
	}

	if (rotate_dir == -1) {
		bool temp = wheels[num].front();
		wheels[num].pop_front();
		wheels[num].push_back(temp);
	}

	if (rotate_dir == 1) {
		bool temp = wheels[num].back();
		wheels[num].pop_back();
		wheels[num].push_front(temp);
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		char c;
		for (int j = 0; j < 8; j++) {
			cin >> c;
			wheels[i].push_back(c - 48);
		}
	}
	int K, N, D;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N >> D;
		Rotate(N - 1, D, 1); 
	}

	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (wheels[i].front() == true)
			answer += pow(2, i);
	}
	cout << answer;
	return 0;
}
