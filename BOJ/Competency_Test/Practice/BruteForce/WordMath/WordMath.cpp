#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

long long ans;
long long n, arr[27];
vector<long long> v;
string S;
int main() {
	cin >> n;
	for (int a = 0; a < n; ++a) {
		cin >> S;
		int cnt = 1;
		for (int b = S.size() - 1; b >= 0; --b) {
			arr[S[b] - 'A'] += cnt;
			cnt *= 10;
		}
	}
	for (int a = 0; a < 27; ++a)
		if (arr[a] != 0) v.push_back(arr[a]);
	sort(v.begin(), v.end());
	int value = 9;
	for (int a = v.size() - 1; a >= 0; a--) {
		ans += v[a] * value;
		value--;
	}
	cout << ans << endl;

	return 0;
}
