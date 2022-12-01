#include <iostream>
#include <string>
using namespace std;

string S;
int alpha[26];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("Input.txt", "r", stdin);
	while (getline(cin,S)) {
		int so = 0, dae = 0, space = 0, num = 0;
		for (int a = 0; S[a]; ++a) {
			if (S[a] >= 65 && S[a] <= 90) { // 대문자
				++dae;
			}
			else if (S[a] >= 97 && S[a] <= 122) { // 소문자
				++so;
			}
			else if (S[a] >= 48 && S[a] <= 57) { // 숫자
				++num;
			}
			else {
				++space;
			}
		}
		cout << so << " " << dae << " " << num << " " << space << "\n";
	}
	return 0;
}
