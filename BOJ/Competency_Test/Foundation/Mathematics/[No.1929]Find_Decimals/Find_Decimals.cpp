#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool arr[1000001];


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	//	freopen("Input.txt", "r", stdin);
	cin >> n >> m;
	arr[1] = 1;
	for (int a = 2; a <= sqrt(m); ++a) {
		if (!arr[a]) {
			for (int b = 2; b * a <= m; ++b) {
				arr[a * b] = 1;
			}
		}
	}
	for (int a = n; a <= m; ++a) {
		if (!arr[a])
			cout << a << "\n";
	}
	return 0;
}
