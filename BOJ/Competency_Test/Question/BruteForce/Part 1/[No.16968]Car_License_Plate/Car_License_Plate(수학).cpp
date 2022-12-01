#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int N;
string iput;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// 소문자 a = 97 z = 123
//	freopen("Input.txt", "r", stdin);
	cin >> iput;
	long answer;
	if (iput.at(0) == 'd') {
		answer = 10; 
	}
	else{
		answer = 26;
	}
	for (int a = 1; a < iput.size(); ++a) {
		if (iput.at(a) == 'd') {
			if (iput.at(a - 1) == 'd') {
				answer = answer * 9;
			}
			else {
				answer = answer * 10;
			}
		}
		else {
			if (iput.at(a - 1) == 'd'){
				answer = answer * 26;
			}
			else {
				answer = answer * 25;
			}
		}
	}
	cout << answer;
	return 0;
}

