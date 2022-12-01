#include <iostream>
#include <algorithm>

using namespace std;
#define MIN -9223372036854775808
int n, m, k;

int arr[11][11];
int able[11][11];
int cant[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
long long big = MIN;
int answer[22];
void dfs(long long num, int count) {
	if(count == k){
		if (big < num) {
			big = num;
		}
		return;
	}
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			if (able[a][b] == 0) {
				for (int c = 0; c < 4; ++c) {
					if ((a + cant[c][0] >= 0) && (a + cant[c][0] < n) && (b + cant[c][1] >= 0) && (b + cant[c][1] < m)) {
						++able[a + cant[c][0]][b + cant[c][1]];
					}
				}

				answer[count] = arr[a][b];

				++able[a][b];
				dfs(num + arr[a][b], count+1);
				--able[a][b];

				for (int c = 0; c < 4; ++c) {
					if ((a + cant[c][0] >= 0) && (a + cant[c][0] < n) && (b + cant[c][1] >= 0) && (b + cant[c][1] < m)) {
						--able[a + cant[c][0]][b + cant[c][1]];
					}
				}
			}
		}
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("Input.txt", "r", stdin);

	cin >> n >> m >> k;

	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			cin >> arr[a][b];
		}
	}
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			for (int c = 0; c < 4; ++c) {
				if ((a + cant[c][0] >= 0) && (a + cant[c][0] < n) && (b + cant[c][1] >= 0) && (b + cant[c][1] < m)) {
					++able[a + cant[c][0]][b + cant[c][1]];
				}
			}
			answer[0] = arr[a][b];

			++able[a][b];
			dfs(arr[a][b],1);
			--able[a][b];

			for (int c = 0; c < 4; ++c) {
				if ((a + cant[c][0] >= 0) && (a + cant[c][0] < n) && (b + cant[c][1] >= 0) && (b + cant[c][1] < m)) {
					--able[a + cant[c][0]][b + cant[c][1]];
				}
			}
		}
	}
	cout << big;

	return 0;
}
