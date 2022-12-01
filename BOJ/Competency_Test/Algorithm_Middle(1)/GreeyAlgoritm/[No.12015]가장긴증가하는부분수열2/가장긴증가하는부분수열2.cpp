#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int big = 0;
int N;
vector<int> arr = { 0 };
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);

	cin >> N;

	for (int a = 0; a < N; ++a) {
		int temp;
		cin >> temp;
		if (temp > arr.back())
			arr.push_back(temp);
		else {
			int idx = lower_bound(arr.begin(), arr.end(), temp) - arr.begin();
			arr[idx] = temp;
		}
	}
	cout << arr.size()-1;
	return 0;
}
