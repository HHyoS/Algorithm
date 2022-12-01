#include <iostream>
#include <algorithm>

using namespace std;



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	//	freopen("Input.txt", "r", stdin);
	while (cin >> n) {
		int num = 1;
		int tens = 1;
		while (1) {
			if (num % n== 0)
				break;
			num = (num % n) * 10 + 1;
			++tens;
		}
		cout << tens << "\n";
	}
	return 0;
}
