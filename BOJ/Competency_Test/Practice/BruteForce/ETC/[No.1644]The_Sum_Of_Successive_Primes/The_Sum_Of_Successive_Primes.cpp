#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
int N;
long long M;
bool prime[4000001];
int answer = 0;
int prime_num[283146];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	//freopen("Input.txt", "r", stdin);

	cin >> N;
	int idx = 0;
	for (int a = 2; a <= sqrt(N); ++a) {
		if (prime[a])
			continue;
		for (int b = 2; a * b <= N; ++b) {
			prime[a * b] = 1;
		}
	}
	for (int a = 2; a <= N; ++a) {
		if (!prime[a]) {
			prime_num[idx++] = a;
		}
	}

	for (int a = 0; a < idx; ++a) {
		int sum = 0;
		if (prime_num[a] > N)
			break;
		else {
			for (int b = a; b < idx; ++b) {
				sum += prime_num[b];
				if (sum > N)
					break;
				else if (sum == N) {
					++answer;
					break;
				}
			}
		}

	}
	cout << answer;
	return 0;
}
