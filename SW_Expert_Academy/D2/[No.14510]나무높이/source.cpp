#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int tree[110];
int T, N;
int ans = 0;
int one;
int two;
void test() {
	for (int a = 0; a < N - 1; ++a) {
		if (tree[a] == tree[N - 1]) return;
		int num = (tree[N - 1] - tree[a]);
		int cnt = num >> 1;
		int namuzi = num & 1;
		two += cnt;
		one += namuzi;
	}
}
int main()
{

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		ans = 0;
		one = 0;
		two = 0;
		for (int a = 0; a < N; ++a) {
			cin >> tree[a];
		}
		sort(tree, tree + N);
		test();
		if (one > two) {
			ans = two<<1;
			one -= two;
			ans = ans + 1 + ((one - 1) << 1);
		}
		else if (one < two) {
			ans = one*2;
			two -= one;
			int cnt = two / 3;
			ans = ans + (cnt <<2);
			two = two % 3;
			if (two == 1) {
				ans += 2;
			}
			else if (two == 2) {
				ans += 3;
			}
		}
		else {
			ans = (one << 1);
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
