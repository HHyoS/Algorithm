#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
    int sz=0;
	cin.ignore();
	while (T--) {
		string str, Answer;
		getline(cin, str);
        sz = str.length();
		int Start = 0;
		for (int i = 0; i < sz; i++)
			if (str[i] == ' ') {
				reverse(str.begin() + Start, str.begin() + i);
				Start = i + 1;
			}

		reverse(str.begin() + Start, str.end());

		cout << str << endl;
	}
} // getline 함수와 reverse 함수 사용하여 코드길이와 실행속도 개선
