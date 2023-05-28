#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

int N;
int arr[2001];
bool possible[2001][2001];

void solve(int start, int end) {
	int left = start;
	int right = end;
	while (left <= right) {
		if (arr[left] != arr[right]) {
			possible[start][end] = 0;
			return;
		}
		++left;
		--right;
	}
	possible[start][end] = 1;
}

void input() {
	int N,M;
	cin >> N;
	for (int a = 1; a <= N; ++a) {
		cin >> arr[a];
	}
	cin >> M;
	for (int a = 1; a <= N; ++a) {
		if (a != N && arr[a] == arr[a+1]) {
			possible[a][a + 1] = 1;
		}
		possible[a][a] = 1;
	}
	
	for (int a = N - 1; a >= 1; --a) {
		for (int b = a + 2; b <= N; ++b) {
			if (arr[a] == arr[b] && possible[a + 1][b - 1]) {
				possible[a][b] = 1;
			}
		}
	}
	for (int a = 0; a < M; ++a) {
		int start, end;
		cin >> start >> end;
		cout << possible[start][end] << "\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	
	input();

	return 0;	
}
