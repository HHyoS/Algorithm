#include<iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <memory.h>
using namespace std;



int N, B;
int ans = 21e8;
int employee[21];
void dfs(int idx, int tSum) {
	if (tSum >= B) {
		if (abs(B - tSum) < ans) {
			ans = abs(B - tSum);
		}
		return;
	}
	if (idx == N)
		return;

	dfs(idx + 1, tSum);

	dfs(idx + 1, tSum + employee[idx]);
	
}
void Solve() {
	dfs(0, 0);
}


int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> B;
		ans = 21e8;
		for (int a = 0; a < N; ++a) {
			cin >> employee[a];
		}
		Solve();
		
		cout << "#"<<test_case<< " "<< ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
