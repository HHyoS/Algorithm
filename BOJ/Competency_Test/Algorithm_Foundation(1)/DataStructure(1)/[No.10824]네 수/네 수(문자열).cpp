#include <iostream>
#include <string>
using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string A, B, C, D;
	//freopen("Input.txt", "r", stdin);
	cin >> A >> B >> C >> D;

	A = A + B;
	C = C + D;

	cout << stoll(A) + stoll(C);
	return 0;
}
