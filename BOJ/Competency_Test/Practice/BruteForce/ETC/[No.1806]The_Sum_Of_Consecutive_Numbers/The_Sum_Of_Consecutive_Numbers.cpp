#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
int N;
long long S;
int num[100000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	freopen("Input.txt", "r", stdin);

	cin >> N >> S;
	long long sum = 0;
	for (int a = 0; a < N; ++a) {
		cin >> num[a];
		sum += num[a];
	}
	if (sum < S) {
		cout << "0";
		return 0;
	}
	int left = 0, right = 0;
	sum = num[0];
	int leng = N;
	while ((left <= right) && (right < N)) {
		if (sum < S) {
			sum += num[++right];
		}
		else if (sum >= S) {
			leng = min(leng,right - left + 1);
			sum -= num[left++];
		}
	}
	cout << leng;
	return 0;
}
