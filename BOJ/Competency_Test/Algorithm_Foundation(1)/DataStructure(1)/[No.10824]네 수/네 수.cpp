#include <iostream>
#include <string>
using namespace std;


int num[8] = { 1,10,100,1000,10000,100000,1000000,10000000 };
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long A, B, C, D;
	long long sum_A, sum_B;
	//freopen("Input.txt", "r", stdin);
	cin >> A >> B >> C >> D;
	int idx = 0;
	while ((B / num[idx]) != 0) {
		++idx;
	}
	sum_A = A * num[idx] + B;
	idx = 0;
	while ((D / num[idx]) != 0) {
		++idx;
	}
	sum_B = C * num[idx] + D;
	cout << sum_A+ sum_B;
	return 0;
}
