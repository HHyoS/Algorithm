#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stack>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
int boat[21][3];
int used[21];
int ans = 0;
void dfs(int before_row, int before_col, int height) {
	int flag = 1;
	for (int a = 0; a < N; ++a) {
		if (used[a] == 0) {
			used[a] = 1;
			if (boat[a][0] <= before_row && boat[a][1] <= before_col) {
				dfs(boat[a][0], boat[a][1], height + boat[a][2]);
			}
			if (boat[a][1] <= before_row && boat[a][2] <= before_col) {
				dfs(boat[a][1], boat[a][2], height+boat[a][0]);
			}
			if (boat[a][0] <= before_row && boat[a][2] <= before_col) {
				dfs(boat[a][0], boat[a][2], height+boat[a][1]);
			}
			used[a] = 0;
		}
	}
	if (flag && ans < height) {
		ans = height;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		for (int a = 0; a < N; ++a) {
			cin >> boat[a][0] >> boat[a][1] >> boat[a][2];
		}
		for (int a = 0; a < N; ++a) {
			sort(boat[a], boat[a] + 3);
		}
		for (int a = 0; a < N; ++a) {
			used[a] = 1;
			dfs(boat[a][0],boat[a][1],boat[a][2]);
			dfs(boat[a][0], boat[a][2], boat[a][1]);
			dfs(boat[a][1], boat[a][2], boat[a][0]);
			used[a] = 0;
		}
		cout << "#"<<t<<" "<< ans << "\n";
		ans = 0;
	}
}
