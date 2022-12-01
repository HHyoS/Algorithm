#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string N;
int B;
long long answer = 0;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);

	cin >> N >> B;
	int leng = N.length();
	long long gop = 1;
	for (int a = leng - 1; a >= 0; --a) {
		int num;
		if (N[a] >= 'A' && N[a] <= 'Z') {
			num = N[a] - 55;
		}
		else {
			num = N[a] - 48;
		}
		answer = answer + num * gop;
		gop = gop * B;
	}
	cout << answer;
	return 0;
}
