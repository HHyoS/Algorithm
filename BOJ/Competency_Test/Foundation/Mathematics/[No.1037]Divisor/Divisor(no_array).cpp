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
	int big = -1;
	int sm = 1000001;
	int num;
	for (int a = 0; a < n; ++a) {
		cin >> num;
		if (big < num)
			big = num;
		if (sm > num)
			sm = num;
	}
	cout << big * sm;
	return 0;
}
