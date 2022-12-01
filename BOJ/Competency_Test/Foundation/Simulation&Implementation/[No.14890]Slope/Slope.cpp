#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n , l ;
int arr[100][100];

bool x_down(int x, int y) {
	for (int a = 1; a < l; ++a) {
		if ((x + a >= n) || (arr[x][y] != arr[x+a][y]))
			return 0;
	}
	return 1;
}
bool y_down(int x, int y) {
	for (int a = 1; a < l; ++a) {
		if ((y + a >= n) || (arr[x][y] != arr[x][y + a]))
			return 0;
	}
	return 1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("Input.txt", "r", stdin);
	cin >> n >> l;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			cin >> arr[a][b];
		}
	}
	int num = 0;
	int answer = 0;
	for (int a = 0; a < n; ++a) { // -> 이동
		int leng = 1;
		++num;
		for (int b = 0; b < n-1; ++b) {
			if (arr[a][b] == arr[a][b+1]) {
				++leng;
			}
			else if (arr[a][b] - arr[a][b+1] == 1){
				if (y_down(a, b+1)) {
					b += l-1;
					leng = 0;
				}
				else
					break;
			}
			else if(arr[a][b] - arr[a][b+1] == -1){
				if (leng >= l) {
					leng = 1;
				}
				else
					break;
			}
			else {
				break;
			}
			if (b >= n - 2) {
				++answer;
			}
		}

	}
	for (int b = 0; b < n; ++b) { // -> 이동
		int leng = 1;
		++num;
		for (int a = 0; a < n - 1; ++a) {
			if (arr[a][b] == arr[a+1][b]) {
				++leng;
			}
			else if (arr[a][b] - arr[a+1][b] == 1) {
				if (x_down(a+1, b)) {
					a += l - 1;
					leng = 0;
				}
				else
					break;
			}
			else if (arr[a][b] - arr[a+1][b] == -1) {
				if (leng >= l) {
					leng = 1;
				}
				else
					break;
			}
			else {
				break;
			}
			if (a >= n - 2) {
				++answer;
			}
		}

	}
	cout << answer;
	return 0;
}
