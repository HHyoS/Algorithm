#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

string N;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);

	cin >> N;
	stack<int> st;
	int leng = N.length();
	for (int a = N.length() - 1; a >= 0; --a) {
		int num = 1;
		int answer = 0;
		for (int b = 0; b < 3; ++b) {
			if (a < b)
				break;
			int temp = N[a - b] - 48;
			answer = answer + num * temp;
			num *= 2;
		}
		a -= 2;
		st.push(answer);
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}
