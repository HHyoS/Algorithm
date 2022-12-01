#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
int arr[300][300];
vector<int> temp;
void round(int count, int turn) {
	int start_n = 0 + count;
	int start_m = 0 + count;
	int end_n = (n-1) - count;
	int end_m = (m-1) - count;

	for (int a = start_n; a < end_n; ++a) {
		temp.push_back(arr[a][start_m]);
	}
	for (int a = start_m; a < end_m; ++a) {
		temp.push_back(arr[end_n][a]);
	}
	for (int a = end_n; a > start_n; --a) {
		temp.push_back(arr[a][end_m]);
	}
	for (int a = end_m; a > start_m; --a) {
		temp.push_back(arr[start_n][a]);
	}
	int size = temp.size();
	int t = turn % size;
	int index = size - t -1;

	for (int a = start_n; a < end_n; ++a) {
		index = (index + 1) % size;
		arr[a][start_m] = temp[index];
	}
	for (int a = start_m; a < end_m; ++a) {
		index = (index + 1) % size;
		arr[end_n][a] = temp[index];
	}
	for (int a = end_n; a > start_n; --a) {
		index = (index + 1) % size;
		arr[a][end_m] = temp[index];
	}
	for (int a = end_m; a > start_m; --a) {
		index = (index + 1) % size;
		arr[start_n][a] = temp[index];
	}
	temp.clear();
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("Input.txt", "r", stdin);
	cin >> n >> m >> k;

	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			cin >> arr[a][b];
		}
	}
	int min = 0;
	if (n > m)
		min = m;
	else
		min = n;

	for (int a = 0; a < (min / 2); ++a) {
		round(a, k);
	}

	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			cout << arr[a][b] << " ";
		}
		cout << "\n";
	}
	return 0;
}
