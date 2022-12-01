#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <stack>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;
double work[16][16];
double dp[1 << 16];
double ans = 0;

void dfs(int num,double tot,int deep) {
	if (deep == N) {
		if (tot > ans)
			ans = tot;
		return;
	}

	for (int a = 0; a < N; ++a) {
		int tmp = 1 << a;
		int nnum = num | tmp;
		if (num&tmp) continue;
		double ttmp = tot * work[deep][a];
		if (dp[nnum] < ttmp) {
			dp[nnum] = ttmp;
			dfs(nnum,dp[nnum], deep + 1);
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		for (int a = 0; a < N; ++a) {
			for (int b = 0; b < N; ++b) {
				double tmp;
				cin >> tmp;
				work[a][b] = tmp / 100;
				if (a==0)
					dp[1 << b] = work[a][b];
			}
		}

		for (int a = 0; a < N; ++a) {
			dfs(1<<a,dp[1<<a],1);
		}
		ans *= 100;
		cout << fixed;
		cout.precision(6);
		cout << "#"<<t<<" "<< ans<< "\n";
		ans = 0;
		memset(dp, 0, sizeof(dp));
	}
}
