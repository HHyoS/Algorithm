#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];

long long sum[1000001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long num;
	//	freopen("Input.txt", "r", stdin);
	cin >> n;
	for (int a = 1; a <= 1000000; ++a) {
		for (int b = 1; a * b <= 1000000; ++b) {
			arr[a * b] += a;
		}
	}
	sum[1] = 1;
	for (int a = 2; a <= 1000000; ++a) {
		sum[a] = sum[a - 1] + arr[a];
	}
	for (int a = 0; a < n; ++a) {
		cin >> num;
		cout << sum[num] << "\n";
	}
	return 0;
}
