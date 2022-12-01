#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n;
bool primeN[10000];
bool check[10000];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("Input.txt", "r", stdin);
	for (int a = 2; a <= 9999; ++a) {
		if (primeN[a] == 1)
			continue;
		else
			for (int b = 2; a*b <= 9999; ++b)
				primeN[a*b] = 1;
	}
	cin >> n;
	int num_1, num_2;
	for (int a = 0; a < n; ++a) {
		cin >> num_1 >> num_2;
		int answer = 0;
		int aans = -1;
		queue<int> que;
		if (num_1 == num_2) {
			aans = 0;
			answer = 1;
		}
		else {
			que.push(num_1);
		}
		while (!que.empty()) {
			int size = que.size();
			for (int b = 0; b < size; ++b) {
				int num = que.front();
				que.pop();
				if (num == num_2) {
					aans = 0;
					que = queue<int>();
					memset(check, 0, sizeof(check));
					break;
				}
				int namuzi[4];
				namuzi[0] = num % 10;
				namuzi[1] = num % 100 - num % 10;
				namuzi[2] = num % 1000 - num % 100;
				namuzi[3] = num - num % 1000;
				int temp = num - namuzi[0];

				for (int c = 0; c <= 9; ++c) {
					if (!check[temp + c] && !primeN[temp + c]) {
						que.push(temp + c);
						check[temp + c] = 1;
					}
				}
				temp = num - namuzi[1];
				for (int c = 0; c <= 90; c += 10) {
					if (!check[temp + c] && !primeN[temp + c]) {
						check[temp + c] = 1;
						que.push(temp + c);
					}
				}

				temp = num - namuzi[2];
				for (int c = 0; c <= 900; c += 100) {
						if (!check[temp + c] && !primeN[temp + c]) {
							check[temp + c] = 1;
							que.push(temp + c);
						}
					}
				temp = num - namuzi[3];

				for (int c = 1000; c <= 9000; c += 1000) {
					if (!check[temp+c] && !primeN[temp + c]) {
						check[temp + c] = 1;
						que.push(temp + c);
					}
				}

			}
			++answer;
		}
		if (aans == -1) {
			cout << "Imppossible\n";
		}
		else
			cout << answer-1<<"\n";
	}
	return 0;
}

