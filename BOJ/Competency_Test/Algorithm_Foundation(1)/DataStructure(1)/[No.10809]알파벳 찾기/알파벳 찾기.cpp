#include <iostream>
#include <cstring>
using namespace std;

char S[101];
int alpha[26];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("Input.txt", "r", stdin);
	for (int a = 0; a < 26; ++a) {
		alpha[a] = -1;
	}

	cin >> S;
	for (int a = 0; S[a]; ++a) {
		if (alpha[S[a] - 97] == -1)
			alpha[S[a] - 97] = a;
	}

	for (int a = 0; a < 26; ++a) {
		cout << alpha[a] << " ";
	}

	return 0;
}
