#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

string N;
char answer[1000005];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);

	cin >> N;
	int idx = 0;
	for (int a = 0; a < N.length(); ++a) {
		int fal = 4;
		int num = N[a] -'0';
		while (fal != 0) {
			answer[idx++] = num / fal + '0';
			num %= fal;
			fal /= 2;
		}

	}
	int start = 0;
	while (answer[start] == '0' && start < idx) {
		++start;
	}
	if (idx == start)
		cout << 0;
	else {
		for (int a = start; a < idx; ++a) {
			cout << answer[a];
		}
	}
	return 0;
}
