#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int num[20];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);

	cin >> n;
	for (int a = 0; a < n; ++a) {
		cin >> num[a];
	}
	sort(num, num + n);
	int answer = 1;
	for (int a = 0; a < n; ++a) {
		if (num[a] > answer)
			break;
		else
			answer += num[a];
	}
	cout << answer;
	return 0;
}

