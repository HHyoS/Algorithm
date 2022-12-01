#include <iostream>
#include <string>
using namespace std;

string S;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("Input.txt", "r", stdin);
	getline(cin, S);
	for (int a = 0; S[a]; ++a) {
		if (S[a] >= 65 && S[a] <= 77) { // 대문자
			S[a] = S[a] + 13;
		}
		else if (S[a] >= 78 && S[a] <= 90) {
			S[a] = (S[a] + 13) % 91 + 65;
		}
		else if (S[a] >= 97 && S[a] <= 109) { // 소문자
			S[a] = S[a] + 13;;
		}
		else if (S[a] >= 110 && S[a] <= 122) {
			S[a] = (S[a] + 13) % 123 + 97;
		}
		else
			continue;
	}
	cout << S;
	return 0;
}
