#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
int N;
long long M;
int num[10000];
int answer = 0;
void dfs(int idx, long long sum) {
	++idx;
	if (sum == M) {
		++answer;
		return;
	}
	else if ((idx >= N) || (sum+num[idx] > M)) {
		return;
	}
	else {
		dfs(idx, sum + num[idx]);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	//freopen("Input.txt", "r", stdin);

	cin >> N >> M;
	for (int a = 0; a < N; ++a){
		cin >> num[a];
	}
	for (int a = 0; a < N; ++a) {
		dfs(a, num[a]);
	}
	cout << answer;
	return 0;
}
