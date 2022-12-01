#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//	freopen("Input.txt", "r", stdin);
	cin >> N;
	long num = N--;
	if (N < 0) {
		cout << 1;
		return 0;
	}
	while (N > 1) {
		num *= N--;

	}
	cout << num;
	return 0;
}
