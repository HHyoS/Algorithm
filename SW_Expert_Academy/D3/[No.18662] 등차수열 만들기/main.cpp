
#include<iostream>
#include <algorithm>
using namespace std;

int N;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cout << fixed;
	cout.precision(1);
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		double a, b, c;
		cin >> a >> b >> c;
		double ans = 0;
		double bb = b * 2;
		double ac = a + c;
		// case 1 - 그냥 성립
		if (bb == ac) {
			ans = 0;
		}
		// case 2 - b가 a+c 보다 작음
		else {
			// b는 x만 줄여도 2x가 줄어드는 효과가 있으므로 a나 c에 빼는 케이스를 생각하지 않아도 됌.
			ans = abs(bb - ac) / 2;
		}
        cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
