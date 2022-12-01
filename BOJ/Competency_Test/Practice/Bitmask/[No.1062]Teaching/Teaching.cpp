#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int N, K;
bool alpa[26];
string wd[50];
bool ck[26];
// a  = 97 z = 122
int ct = 0;

void dfs(int count, int idx) {
	if (count == 0) {
		int answer = 0;
		int num;
		for (int a = 0; a < N; ++a) {
			bool check = 0;
			for (int b = 4; b < wd[a].size()-4; ++b) {
				num = wd[a].at(b)-97;
				if (!alpa[num]) {
					check = 1;
					break;
				}
			}
			if (!check)
				++answer;
		}
		if (answer > ct)
			ct = answer;
		return;
	}               
	else {
		++idx;
		if ((idx >= 26) || (26-idx-count< 0)) {
			return;
		}
		
		if (ck[idx]) {
			alpa[idx] = 1;
			dfs(count - 1, idx);
			alpa[idx] = 0;
		}
		dfs(count, idx);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("Input.txt", "r", stdin);
	cin >> N >> K;
	if (K < 5) {
		cout << "0";
		return 0;
	}
	else {
		K -= 5;
		alpa[97 -97] = 1; // a
		alpa[99 - 97] = 1; // c
		alpa[105 - 97] = 1; // i
		alpa[110 - 97] = 1; // n
		alpa[116 - 97] = 1; // t
		for (int a = 0; a < N; ++a) {
			cin >> wd[a];
			for (int b = 4; b < wd[a].size() - 4; ++b) {
				int num = wd[a].at(b) - 97;
				if (!ck[num] && !alpa[num])
					ck[num] = 1;
			}
		}
	
		ck[97 - 97] = 0; // a
		ck[99 - 97] = 0; // c
		ck[105 - 97] = 0; // i
		ck[110 - 97] = 0; // n
		ck[116 - 97] = 0; // t
		dfs(0, 0);
		for (int b = 0; b < K; ++b) {
			for (int a = 0; a < 26; ++a) {
				if (ck[a]) {
					alpa[a] = 1;
					dfs(b, a);
					alpa[a] = 0;
				}
			}
		}
	}
	cout << ct;
	return 0;
}

