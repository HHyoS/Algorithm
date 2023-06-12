#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack <int> binary;

	if (N == 0) {
		binary.push(0);
	}
	else {

		while (N != 0) {
			if (N % -2 == -1) {
				binary.push(1);
				N = N / -2 + 1;
			}
			else {
				binary.push(N % -2);
				N /= -2;
			}
		}
	}
	while (!binary.empty()) {
		cout << binary.top();
		binary.pop();
	}
	cout << "\n";

	return 0;
}
