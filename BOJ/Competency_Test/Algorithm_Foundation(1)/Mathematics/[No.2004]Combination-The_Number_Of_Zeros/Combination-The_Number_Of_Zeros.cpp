#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

long long N, M;

long long two(long long num) {
	long long two_count = 0;
	for (long long a = 2; a <= num; a *= 2) {
		two_count += num / a;
	}
	return two_count;
}
long long five(long long num) {
	long long five_count = 0;
	for (long long a = 5; a <= num; a *= 5) {
		five_count += num / a;
	}
	return five_count;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//	freopen("Input.txt", "r", stdin);
	/*(n)  =   n! / ( m! * (n-m)! ) 
	  (m)       */
	cin >> N >> M;
	cout << min(two(N) - two(N - M) - two(M), five(N) - five(N - M) - five(M));
	return 0;
}
