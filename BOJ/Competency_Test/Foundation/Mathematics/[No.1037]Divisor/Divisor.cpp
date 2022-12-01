#include <iostream>
#include <algorithm>

using namespace std;


int arr[51];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	
//	freopen("Input.txt", "r", stdin);
	cin >> n;
	for (int a = 1; a <= n; ++a)
		cin >> arr[a];
	
	sort(arr, arr + n + 1);
	cout << arr[1] * arr[n];
	return 0;
}
