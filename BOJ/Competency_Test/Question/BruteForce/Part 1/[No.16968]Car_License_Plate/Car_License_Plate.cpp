#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int N;
string iput;
long answer;

void dfs(int idx,int before) {
	if (idx == iput.size()) {
		++answer;
		return;
	}
	else {
		if (iput.at(idx) == 'd') {
			++idx;
			for (int a = 0; a < 10; ++a) {
				if (a != before)
					dfs(idx, a);
			}
		}
		else {
			++idx;
			for (int a = 10; a < 36; ++a) {
				if (a != before)
					dfs(idx, a);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);
	cin >> iput;
	
	if (iput.at(0) == 'd') {
		for (int a = 0; a < 10; ++a) {
			dfs(1, a);
		}
	}
	else {
		for (int a = 10; a < 36; ++a) {
			dfs(1, a);
		}
	}
	cout << answer;
	return 0;
}

