#include <iostream>

using namespace std;
int n,m,k;
int arr[101][101];
int cpy[101][101];
int num;
void one() {
	for (int b = 1; b <= m; ++b) {
		for (int a = 1; a <= n/2; ++a) {
			int temp = arr[a][b];
			arr[a][b] = arr[n-a+1][b];
			arr[n - a + 1][b] = temp;
		}
	}
	return;
}
void two() {
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= m / 2; ++b) {
			int temp = arr[a][b];
			arr[a][b] = arr[a][m-b+1];
			arr[a][m - b + 1] = temp;
		}
	}
	return;
}
void three() {
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= m; ++b) {
			cpy[b][n-a+1] = arr[a][b];
		}
	}
	num = n;
	n = m;
	m = num;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= m; ++b) {
			arr[a][b] = cpy[a][b];
		}
	}
	return;
}
void four() {
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= m; ++b) {
			cpy[m - b + 1][a] = arr[a][b];
		}
	}
	num = n;
	n = m;
	m = num;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= m; ++b) {
			arr[a][b] = cpy[a][b];
		}
	}
	return;
}
void five() {
	int m_jump = m / 2;
	int n_jump = n / 2;
	for (int a = 1; a <= n_jump; ++a) { // 1사분면 -> 2사분면 이동
		for (int b = m_jump + 1; b <= m; ++b) {
			cpy[a + n_jump][b] = arr[a][b];
		}
	}

	for (int a = n_jump + 1; a <= n; ++a) { // 2사분면 -> 3사분면 이동 
		for (int b = m_jump + 1; b <= m; ++b) {
			cpy[a][b - m_jump] = arr[a][b];
		}
	}

	for (int a = n_jump+1; a <= n; ++a) { // 3사분면 -> 4사분면 이동
		for (int b = 1; b <= m_jump; ++b) {
			cpy[a - n_jump][b] = arr[a][b];
		}
	}

	for (int a = 1; a <= n_jump; ++a) { // 4사분면 -> 1사분면 이동
		for (int b = 1; b <= m_jump; ++b) {
			cpy[a][b + m_jump] = arr[a][b];
		}
	}
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= m; ++b) {
			arr[a][b] = cpy[a][b];
		}
	}
	return;
}
void six() {
	int m_jump = m / 2;
	int n_jump = n / 2;
	for (int a = 1; a <= n_jump; ++a) { // 1사분면 -> 4사분면 이동
		for (int b = m_jump + 1; b <= m; ++b) {
			cpy[a][b-m_jump] = arr[a][b];
		}
	}

	for (int a = n_jump + 1; a <= n; ++a) { // 2사분면 -> 1사분면 이동 
		for (int b = m_jump + 1; b <= m; ++b) {
			cpy[a - n_jump][b] = arr[a][b];
		}
	}

	for (int a = n_jump + 1; a <= n; ++a) { // 3사분면 -> 2사분면 이동
		for (int b = 1; b <= m_jump; ++b) {
			cpy[a][b+m_jump] = arr[a][b];
		}
	}

	for (int a = 1; a <= n_jump; ++a) { // 4사분면 -> 3사분면 이동
		for (int b = 1; b <= m_jump; ++b) {
			cpy[a+n_jump][b] = arr[a][b];
		}
	}
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= m; ++b) {
			arr[a][b] = cpy[a][b];
		}
	}
	return;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("Input.txt", "r", stdin);

	cin >> n >> m >> k;
	for (int a = 1; a <= n; ++a){
		for (int b = 1; b <= m; ++b) {
			cin >> arr[a][b];
		}
	}
	int command = 0;
	while (k--) {
		cin >> command;
		switch (command){
			case  1:
				one();
				break;
			case 2:
				two();
				break;
			case 3:
				three();
				break;
			case 4:
				four();
				break;
			case 5:
				five();
				break;
			case 6:
				six();
				break;
			default :
				break;
		}
	}
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= m; ++b) {
			cout << arr[a][b] << " ";

		}
		cout << "\n";
	}
	return 0;
}
