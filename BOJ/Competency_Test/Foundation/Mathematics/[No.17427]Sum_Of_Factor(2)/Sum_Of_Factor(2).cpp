#include <iostream>
#include <algorithm>

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	
//	freopen("Input.txt", "r", stdin);
	cin >> n;
	long long answer = 0;
	for (int a = 1; a <= n; ++a) {
		answer = answer + (n / a) * a;
	}
	cout << answer;
	return 0;
}
