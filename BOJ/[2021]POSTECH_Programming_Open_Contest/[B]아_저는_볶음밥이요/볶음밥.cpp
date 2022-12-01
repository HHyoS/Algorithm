#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
long long n;
long long menu[3];
vector<pair<long long, long long>> arr(4);
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("Input.txt", "r", stdin);
	cin >> n >> menu[0] >> menu[1] >> menu[2];

	for (int a = 0; a < 2; ++a) {
		menu[a] = n- menu[a] % n;
	}
	arr[0] = { 1 + (menu[2] - menu[0]) / n,menu[2] - menu[0] };
	arr[1] = { 1 + (menu[2] - menu[1]) / n,menu[2] - menu[1] };
	arr[2] = { 2 + (menu[2] - menu[0] - menu[1]) / n,menu[2] - menu[0] - menu[1] };
	arr[3] = { menu[2] / n,menu[2] };
	sort(arr.begin(), arr.end(), greater<>());
	cout << arr[0].second;

	return 0;
}

