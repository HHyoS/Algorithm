#include <iostream>
#include <algorithm>

using namespace std;

char input_char[100001] = { 0, };
char l_st[600001];
char r_st[600001];


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); // 13~15 line 사용시 cin의 성능이 scanf보다 빨라짐
	int n;
//	freopen("Input.txt", "r", stdin);
	string inp;
	cin >> inp;
	int l_index = -1, r_index = -1;

	for (int a = 0; a < inp.length(); ++a) {
		l_st[++l_index] = inp.at(a);
	}
	cin >> n;
	while (n--) {
		char command;
		cin >> command;
		if ((command == 'L') && (l_index > -1))
			r_st[++r_index] = l_st[l_index--];
		else if ((command == 'D') && (r_index > -1))
			l_st[++l_index] = r_st[r_index--];
		else if ((command == 'B') && (l_index > -1))
			l_index--;
		else if (command == 'P') {
			cin >> command;
			l_st[++l_index] = command;
		}

	}

	l_st[l_index + 1] = r_st[r_index + 1] = 0;
	reverse(r_st, r_st + r_index + 1);
	cout << l_st << r_st;
	return 0;
}
