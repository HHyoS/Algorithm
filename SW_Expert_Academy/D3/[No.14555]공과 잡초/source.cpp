#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string tmp;
		cin >> tmp;
		int cnt = 0;
		for (int a = 0; a < tmp.length(); ++a) {
			if (tmp[a] == '(') {
				if (tmp[a + 1] == ')') {
					++a;
				}
				++cnt;
			}
			else if (tmp[a] == ')') {
				++cnt;
			}
		}
		cout << "#" << t << " " << cnt << "\n";
	}
	return 0;
}
