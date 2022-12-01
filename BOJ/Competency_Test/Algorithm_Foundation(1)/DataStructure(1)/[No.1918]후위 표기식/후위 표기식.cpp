#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string S;
	//freopen("Input.txt", "r", stdin);
	cin >> S;
	stack<char> stk;
	string answer;
	for (int a = 0; S[a]; ++a) {
		if (S[a] >= 'A' && S[a] <= 'Z') {
			answer = answer + S[a];
		}
		else {
			if (S[a] == '+' || S[a] == '-') {
				while (!stk.empty() && stk.top() != '(') {
					answer += stk.top();
					stk.pop();
				}
				stk.push(S[a]);
			}
			else if (S[a] == '*' || S[a] == '/') {
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
					answer += stk.top();
					stk.pop();
				}
				stk.push(S[a]);
			}
			else {
				if (S[a] == '(') {
					stk.push(S[a]);
				}
				else {
					while (stk.top() != '(') {
						answer += stk.top();
						stk.pop();
					}
					stk.pop();
				}
			}
		}
	}
	while (!stk.empty()) {
		answer += stk.top();
		stk.pop();
	}
	cout << answer;
	return 0;
}
