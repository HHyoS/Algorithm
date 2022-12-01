#include <iostream>

using namespace std;

int n, m;
int arr[4][4];
bool check[4][4];
int big = -1;

void dfs(int x, int y, int sum) {
	if (y >= m) {
		++x;
		if (x == n) {
			if (sum > big)
				big = sum;
			return;
		}
		y = 0;
	}
	if (check[x][y]) {
		dfs(x, y + 1, sum);
	}
	else {
		check[x][y] = 1;
		dfs(x, y + 1, sum + arr[x][y]);
		int temp = arr[x][y];
		for (int a = 1; x + a < n; ++a) {
			if (!check[x + a][y]) {
				for (int b = 1; b <= a; ++b) {
					check[x + b][y] = 1;
				}
				temp = temp * 10 + arr[x + a][y];
				dfs(x, y + 1, sum + temp);
				for (int b = 1; b <= a; ++b) {
					check[x + b][y] = 0;
				}
			}
			else
				break;
		}
		temp = arr[x][y];
		for (int a = 1; y + a < m; ++a) {
			if (!check[x][y + a]) {
				for (int b = 1; b <= a; ++b) {
					check[x][y + b] = 1;
				}
				temp = temp * 10 + arr[x][y + a];
				dfs(x, y + a, sum + temp);
				for (int b = 1; b <= a; ++b) {
					check[x][y + b] = 0;
				}
			}
			else
				break;
		}
		check[x][y] = 0;
	}
}
int main() {

	/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/

	freopen("Input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < m; ++b) {
			scanf("%1d", &arr[a][b]);
		}
	}
	dfs(0 , 0, 0); 
	printf("%d", big);
	return 0;
}
