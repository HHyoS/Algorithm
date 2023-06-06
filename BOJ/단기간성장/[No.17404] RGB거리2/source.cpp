#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

int N;
int rgb[1001][3];
int cost[1001][3];
void solve() {
	int answer = 21e8;
	for (int b = 0; b < 3; ++b) {
		for (int a = 0; a < 3; ++a) {
			if (a == b) {
				cost[0][a] = rgb[0][a];
			}
			else {
				cost[0][a] = 21e8;
			}
		}
		for (int a = 1; a < N; ++a) {
			cost[a][0] = min(cost[a - 1][1] + rgb[a][0], cost[a - 1][2] + rgb[a][0]);
			cost[a][1] = min(cost[a - 1][0] + rgb[a][1], cost[a - 1][2] + rgb[a][1]);
			cost[a][2] = min(cost[a - 1][0] + rgb[a][2], cost[a - 1][1] + rgb[a][2]);
		}
		for (int a = 0; a < 3; ++a) {
			if (a == b) continue;
			answer = min(answer, cost[N - 1][a]);
		}
	}
	cout << answer;
}

void input() {
	cin >> N;
	for (int a = 0; a < N; ++a) {
		for (int b = 0; b < 3; ++b) {
			cin >> rgb[a][b];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	
	input();
	solve();
	return 0;	
}
