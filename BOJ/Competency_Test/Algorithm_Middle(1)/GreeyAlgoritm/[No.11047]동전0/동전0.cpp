#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int N;
int K;
int coin[10];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);

	cin >> N >> K;
	for (int a = 0; a < N; ++a) {
		cin >> coin[a];
	}
	int answer = 0;
	for (int a = N-1; a >= 0; --a) {
		if (K < coin[a])
			continue;
		else {
            		answer += K/coin[a];
			K %= coin[a];
		}
	}
	cout << answer;
	return 0;
}
