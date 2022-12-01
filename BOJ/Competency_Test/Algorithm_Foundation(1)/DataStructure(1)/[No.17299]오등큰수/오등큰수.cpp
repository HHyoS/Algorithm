#include <iostream>
#include <string>
#include <stack>
using namespace std;

int ary[1000001];
int N;
int F[1000001];
stack<int> NGF;
stack<int> st;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);
	cin >> N;
	for (int a = 0; a < N; ++a) {
		cin >> ary[a];
		++F[ary[a]];
	}
	for (int a = N-1; a >= 0; --a) {
		while (!st.empty()) {
			if (F[ary[a]] >= F[st.top()]) st.pop();
			else {
				break;
			}
		}
		if (st.empty()) NGF.push(-1);
		else NGF.push(st.top());
		st.push(ary[a]);
	}
	while (!NGF.empty()) {
		cout << NGF.top() << " ";
		NGF.pop();
	}
	return 0;
}
