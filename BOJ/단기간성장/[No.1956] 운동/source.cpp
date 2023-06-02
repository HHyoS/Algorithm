#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

int v, e;
long long arr[401][401];

void solve() {
	for (int c = 1; c <= v; ++c)
		for (int a = 1; a <= v; ++a)
			for (int b = 1; b <= v; ++b)
				arr[a][b] = min(arr[a][b], arr[a][c] + arr[c][b]);

	long long result = 21e8;

	for (int a = 1; a <= v; ++a)
		for (int b = 1; b <= v; ++b) {
			if (a == b) continue;
			result = min(result, arr[a][b] + arr[b][a]);
		}
	if (result == 21e8)
		cout << -1 << endl;
	else
		cout << result << endl;
}

void input() {
	cin >> v >> e;
	for (int a = 1; a <= v; ++a) {
		for (int b = 1; b <= v; ++b) {
			if (a == b) arr[a][b] = 0;
			else arr[a][b] = 21e8;
		}
	}
	int from, to, cost;
	for (int a = 0; a < e; ++a) {
		cin >> from >> to >> cost;
		if (arr[from][to] > cost) //중복경로
			arr[from][to] = cost;
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
