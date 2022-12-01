a#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int arr[1000][1000];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("Input.txt", "r", stdin);

	cin >> N >> K;
	int num = N * N;
	int mov = 0;
	// 0 = down, 1 = right , 2 = up , 3 = left
	int down = N, right = N, up = 1, left = 2;
	int x = 1, y = 1;
	while (num != 0) {
		
		if (mov == 0) {
			for (int a = 0; x + a <= down; ++a) {
				arr[x + a][y] = num--;
			}
			mov = 1;
			x = down;
			--down;
			++y;
		}
		else if (mov == 1) {
			for (int a = 0; y+a <= right; ++a) {
				arr[x][y + a] = num--;
			}
			mov = 2;
			y = right;
			--right;
			--x;
		}
		else if (mov == 2) {
			for (int a = 0; x-a >= up; ++a) {
				arr[x - a][y] = num--;
			}
			mov = 3;
			x = up;
			++up;
			--y;
		}
		else {
			for (int a = 0; y-a >= left; ++a) {
				arr[x][y - a] = num--;
			}
			mov = 0;
			y = left;
			x = x + 1;
			++left;
		}
	}

	int answer_x, answer_y;
	for (int a = 1; a <= N; ++a) {
		for (int b = 1; b <= N; ++b) {
			cout << arr[a][b] << " ";
			if (K == arr[a][b]) {
				answer_x = a;
				answer_y = b;
			}
		}
		cout << "\n";
	}
	cout << answer_x << " " << answer_y;
	return 0;
}
