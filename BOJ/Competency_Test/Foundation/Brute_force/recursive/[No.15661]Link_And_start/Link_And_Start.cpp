#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int n;
int arr[20][20];
bool team[20];
int target;
int answer = 2147480000;
void ssum() {
	int team_a = 0;
	int team_b = 0;
	for (int a = 0; a < n; ++a) {
		for (int b = a + 1; b < n; ++b) {
			if ((team[a] == 1) && (team[b] == 1)) {
				team_a += arr[a][b] + arr[b][a];
			}
			else if ((team[a] == 0) && (team[b] == 0)) {
				team_b += arr[a][b] + arr[b][a];
			}
		}
	}
	if (answer > abs(team_a - team_b)) {
		answer = abs(team_a - team_b);
	}
}
void dfs(int index, int count) {
	if (count == 0) {
		ssum();
		return;
	}
		
	++index;
	if (index >= n)
		return;

	for (int b = index; b < n; ++b) {
		if (!team[b]) {
			team[b] = 1;
			dfs(b, count -1);
			team[b] = 0;
		}
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("Input.txt", "r", stdin);

	cin >> n;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			cin >> arr[a][b];
		}
	}

	for (int a = 2; a <= n - 2; ++a) {
		for (int b = 0; b <= n-a; ++b) {
			team[b] = 1;
			dfs(b, a-1);
			team[b] = 0;
		}
	}

	cout << answer;
	return 0;
}
