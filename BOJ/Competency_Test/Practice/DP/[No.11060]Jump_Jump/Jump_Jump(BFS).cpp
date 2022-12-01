#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
int arr[1001];
bool check[1001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("Input.txt", "r", stdin);
	cin >> N;
	for (int a = 1; a <= N; ++a)
		cin >> arr[a];
	queue<int> que;
	que.push(1);
	int answer = -1;
	int lop = 1;
	if (N == 1) {
		que.pop();
		answer = 0;
	}
	while (!que.empty()) {
		int size = que.size();
		for (int a = 0; a < size; ++a) {
			int idx = que.front();
			que.pop();

			for (int jump = 1; jump <= arr[idx]; ++jump) {
				if ((idx+jump <= N) && !check[idx + jump]) {
					if (idx + jump == N) {
						answer = lop;
						que = queue<int>();
						a = size;
						break;
					}
					check[idx + jump] = 1;
					que.push(idx + jump);
				}
			}
		}
		++lop;
	}
	cout << answer;
	return 0;
}
