#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

long long N;
int B;
string answer;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("Input.txt", "r", stdin);

	cin >> N >> B;
	long long gop = 1;
	while (1) {
		gop *= B;
		if (N / gop == 0) {
			gop /= B;
			break;
		}
	}
	while (gop > 0) {
		char t;
		if (N / gop >= 10) {
			t = N / gop + 55;
			answer += t;
		}
		else {
			answer += to_string(N / gop);
		}
		N %= gop;
		gop /= B;
	}
	cout << answer;
	return 0;
}
