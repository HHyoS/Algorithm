#include <iostream>
#include <algorithm>

using namespace std;


char arr[51][51];
int xy[2][2] = { {0,1},{1,0} };
int n;
int big = 0;
void check() {
	for (int a = 0; a < n; ++a) {
		int count = 1;
		char stand = arr[a][0];

		int ccount = 1;
		char sstand = arr[0][a];
		for (int b = 1; b < n; ++b) {
			if (stand == arr[a][b])
				++count;
			else {
				if (count > big)
					big = count;
				count = 1;
				stand = arr[a][b];
			}
		}
		if (count > big)
			big = count;


		for (int b = 1; b < n; ++b) {
			if (sstand == arr[b][a])
				++ccount;
			else {
				if (ccount > big)
					big = ccount;
				ccount = 1;
				sstand = arr[b][a];
			}
		}
		if (ccount > big)
			big = ccount;
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string lin;
//	freopen("Input.txt", "r", stdin);
	cin >> n;
	for (int a = 0; a < n; ++a) {
		cin >> lin;
		for (int b = 0; b < n; ++b) {
			arr[a][b] = lin.at(b);
		}
	}
	char temp;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			temp = arr[a][b];
			if (a < n - 1) {
				if (arr[a][b] != arr[a + 1][b]) {
					arr[a][b] = arr[a + 1][b];
					arr[a + 1][b] = temp;
					check();
					arr[a + 1][b] = arr[a][b];
					arr[a][b] = temp;
				}
			}

			if (b < n - 1){
				if (arr[a][b] != arr[a][b+1]) {
					arr[a][b] = arr[a][b + 1];
					arr[a][b + 1] = temp;
					check();
					arr[a][b + 1] = arr[a][b];
					arr[a][b] = temp;
				}
			}

		}
	}
	cout << big;
	return 0;
}
