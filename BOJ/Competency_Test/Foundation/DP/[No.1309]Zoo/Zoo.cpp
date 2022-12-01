#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[2][3];


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("Input.txt", "r", stdin);
	cin >> n;
	
	dp[1][0] = 1; // 1줄에 안넣은 경우
	dp[1][1] = 1; // 1줄 1열에 넣은 경우
	dp[1][2] = 1; // 1줄 2열에 넣은 경우
	int answer = 0;
	bool now;
	bool before;
	for (int a = 2; a <= n; ++a) {
		now = a % 2;
		before = (a + 1) % 2;
		dp[now][0] = (dp[before][0] + dp[before][1] + dp[before][2]) % 9901;
		dp[now][1] = (dp[before][0] + dp[before][2]) % 9901;
		dp[now][2] = (dp[before][0] + dp[before][1]) % 9901;
	}
	int last = n % 2;
	answer = (dp[last][0] + dp[last][1] + dp[last][2]) % 9901;
	cout << answer;
	return 0;
}
