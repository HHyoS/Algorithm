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
	if (N <= 1) {
		cout << 0;
		return 0;
	}

	int count = 0;
	long long num = N--;
	while (N > 1){
		num = num * N;
		while ((num % 10) == 0) {
			++count;
			num = num / 10;
		}
		num %= 1000000;
		N -= 1;
	}
	cout << count;
	return 0;
}
