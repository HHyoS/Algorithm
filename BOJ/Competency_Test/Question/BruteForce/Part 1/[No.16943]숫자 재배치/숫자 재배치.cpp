#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

string first;
string second;
long long f, s;


vector<char> ch;
long long maxi = -1;
bool checker[12];
char ans[12];
bool flag = 0;
void dfs(int deep) {
	if (flag)
		return;
	if (deep == ch.size()) {
		string answer = ans;
		long long bignum = stoll(answer);
		if (bignum < s) {
			maxi = bignum;
			flag = 1;
		}
		return;
	}

	for (int a = 0; a < ch.size(); ++a) {
		if (deep == 0 && ch[a] == '0') continue;
		if (!checker[a]) {
			checker[a] = 1;
			ans[deep] = ch[a];
			dfs(deep + 1);
			checker[a] = 0;
		}
	}
}
void solve() {
		dfs(0);
}
void input() {
	cin >> first >> second;

	for (int a = 0; a < first.length(); ++a)
		ch.push_back(first[a]);

	f = stoll(first);
	s = stoll(second);
	sort(ch.begin(), ch.end(),greater<char>());

}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	cout << maxi;
	return 0;

}
