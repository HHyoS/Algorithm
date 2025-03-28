
#include<iostream>
#include <algorithm>
using namespace std;


double arr[10];
int N;
double total_sum;
double gop[10] = { 1,2,4,8,16,32,64,128,256,512 };

void dfs(int idx, double total, double cnt) {
	if (idx == N) {
		if (cnt != 0) {
			total_sum += (total/cnt);
		}
		return;
	}
	dfs(idx + 1, total + arr[idx], cnt + 1);
	dfs(idx + 1, total, cnt);
}
void Solve() {
	dfs(0, 0, 0);
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cout << fixed;
	cout.precision(20);
	cout << defaultfloat;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		total_sum = 0;
		cin >> N;
		for (int a = 0; a < N; ++a) {
			cin >> arr[a];
		}

		Solve();
		double ans = total_sum / (gop[N] - 1);
		cout << "#"<<test_case<< " " <<ans<<"\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
