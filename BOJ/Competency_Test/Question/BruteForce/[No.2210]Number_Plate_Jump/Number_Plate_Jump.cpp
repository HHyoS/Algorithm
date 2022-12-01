#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int N;
int arr[5][5];
set<int> answer;
int mov[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

void dfs(int x, int y, int count,int num) {
	if (count == 6) {
		answer.insert(num);
		return;
	}
	else {
		for (int a = 0; a < 4; ++a) {
			int xx = x + mov[a][0];
			int yy = y + mov[a][1];
			if ((xx >= 0) && (yy >= 0) && (xx < 5) && (yy < 5)) {
				dfs(xx, yy, count+1, num * 10 + arr[xx][yy]);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("Input.txt", "r", stdin);
	for (int a = 0; a < 5; ++a) {
		for (int b = 0; b < 5; ++b) {
			cin >> arr[a][b];
		}
	}
	
	for (int a = 0; a < 5; ++a) {
		for (int b = 0; b < 5; ++b) {
			dfs(a, b, 1,arr[a][b]);
		}
	}
	cout << answer.size();
	return 0;
}

