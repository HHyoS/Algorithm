#include <iostream>
#include <string>
using namespace std;


int num[27];
string S;
double stk[202];
int idx = 0;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	//freopen("Input.txt", "r", stdin);
	cin >> N >> S;
	for (int a = 0; a < N; ++a) {
		cin >> num[a];
	}
	for (int a = 0; S[a]; ++a) {
		if (S[a] >= 65 && S[a] <= 90) {
			stk[idx++] = num[S[a] - 65];
		}
		else { 
			if (S[a] == '*') {
				stk[idx - 2] = stk[idx - 2] * stk[idx - 1];
				--idx;
			}
			else if (S[a] == '+') {
				stk[idx - 2] = stk[idx - 2] + stk[idx - 1];
				--idx;

			}
			else if (S[a] == '/') {
				stk[idx - 2] = stk[idx - 2] / stk[idx - 1];
				--idx;
			}
			else {
				stk[idx - 2] = stk[idx - 2] - stk[idx - 1];
				--idx;
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout<< stk[0];

	return 0;
}
