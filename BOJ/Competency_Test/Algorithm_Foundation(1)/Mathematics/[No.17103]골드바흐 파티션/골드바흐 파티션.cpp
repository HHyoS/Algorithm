#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

int arr[1000001];
int N;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("Input.txt", "r", stdin);

	for (int a = 2; a <= sqrt(1000000); ++a) {
		if (arr[a] == 1) continue;
		for (int b = 2; a * b <= 1000000; ++b) {
			arr[a*b] = 1;
		}
	}
	cin >> N;
	for (int a = 0; a < N; ++a) {
		int temp;
		cin >> temp;
		int count = 0;
		for (int b = 2; b <= temp / 2; ++b) {
			if (arr[b] == 1)
				continue;
			if (arr[temp - b] == 0)
				++count;
		}
		cout << count << "\n";
	}
	return 0;
}
