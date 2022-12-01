#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;


char alpa[27] = "abcdefghijklmnopqrstuvwxyz";
int main() {

	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		string tmp;
		cin >> tmp;
		int cnt = 0;
		for (int a = 0; a < tmp.length(); ++a) {
			if (alpa[a] == tmp[a]) {
				++cnt;
			}
			else
				break;
		}
		cout << "#" << t << " " << cnt << "\n";
	}
	return 0;
}
