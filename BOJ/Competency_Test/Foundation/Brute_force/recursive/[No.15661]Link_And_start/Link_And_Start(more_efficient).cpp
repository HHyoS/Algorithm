#include <iostream>

using namespace std;

int n;
int arr[20][20];
bool team[20];
int target;
int answer = 2147480000;

int abs(int x){
	if (x < 0) return x * -1;
	else return x;
}
void ssum() {
	int start[20], link[20];
	int s_count = 0, l_count = 0;

	for (int a = 0; a < n; a++) {
		if (team[a] == 0) {
			link[l_count] = a;
			++l_count;
		}
		else {
			start[s_count] = a;
			++s_count;
		}
	}

	int team_l = 0;
	int team_s = 0;
	for (int a = 0; a < s_count; ++a) {
		for (int b = a+1; b < s_count; ++b) {
			team_s += arr[start[a]][start[b]] + arr[start[b]][start[a]];
		}
	}
	for (int a = 0; a < l_count; ++a) {
		for (int b = a+1; b < l_count; ++b) {
			team_l += arr[link[a]][link[b]] + arr[link[b]][link[a]];
		}
	}
	int dif = abs(team_l - team_s);
	if (answer > dif) {
		answer = dif;
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
			team[b] = 1;
			dfs(b, count -1);
			team[b] = 0;
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("Input.txt", "r", stdin);

	cin >> n;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			cin >> arr[a][b];
		}
	}

	for (int a = 2; a <= n /2; ++a) {
		for (int b = 0; b <= n-a; ++b) {
			team[b] = 1;
			dfs(b, a-1);
			team[b] = 0;
		}
	}

	cout << answer;
	return 0;
}
