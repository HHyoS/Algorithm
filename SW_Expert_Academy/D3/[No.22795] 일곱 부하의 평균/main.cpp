
#include<iostream>
#include <algorithm>
using namespace std;

int N;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int maxi = 0;
		int total = 0;
		int h = 0;
		for (int a = 0; a < 6; ++a) {
			cin >> h;
			total += h;
			maxi = max(maxi, h);
		}
		total += maxi;
		int ans = 7-(total % 7) + maxi;
		cout << ans << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
