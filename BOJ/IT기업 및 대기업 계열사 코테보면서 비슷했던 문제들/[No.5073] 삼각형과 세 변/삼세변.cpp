#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;


void get_answer(int a, int b, int c) {
	if (a == b && a == c) {
		cout << "Equilateral\n";
	}
	else if ((a == b && a != c) || (a == c && a != b) || (b == c && a != b)) {

		int total_sum = a + b + c;
		int max_num = max(a, max(b, c));
		if (total_sum <= max_num * 2) {
			cout << "Invalid\n";
		}
		else {
			cout << "Isosceles\n";
		}
	}
	else {
		int total_sum = a + b + c;
		int max_num = max(a, max(b, c));
		if (total_sum <= max_num * 2) {
			cout << "Invalid\n";
		}
		else {
			cout << "Scalene\n";
		}
	}
}
void Input_And_Solve() {
	int a, b, c;

	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			return;
		}

		get_answer(a, b, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input_And_Solve();

	return 0;
}
