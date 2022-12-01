#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 100000
int n, m;
int check[100001];
bool map[100001];
queue<int> que;

void recur(int num) {
	if (check[num] != -1) {
		recur(check[num]);
		cout << check[num] << " ";
		return;
	}
	return;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
//	freopen("Input.txt", "r", stdin);
	cin >> n >> m;
	que.push(n);
	map[n] = 1;
	check[n] = -1;
	int count = 0;
	while (!que.empty()) {
		int size = que.size();
		for (int a = 0; a < size; ++a) {
			int index = que.front();
			que.pop();
			if (index == m) {
				cout << count << "\n";
				recur(index);
				cout << m;
				que = queue<int>();
				break;
			}
			if ((index > 0) && (map[index - 1] == 0)) {
				que.push(index - 1);
				map[index - 1] = 1;
				check[index - 1] = index;
			}
			if ((index < MAX) && (map[index + 1] == 0)) {
				que.push(index + 1);
				map[index + 1] = 1;
				check[index + 1] = index;
			}
			int gop = index + index;
			if ((gop <= MAX) && (map[gop] == 0)) {
				que.push(gop);
				map[gop] = 1;
				check[gop] = index;
			}
		}
		++count;

	}
	return 0;
}
