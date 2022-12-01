#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, L,R, X;
int num[16];
bool check[16];
int answer = 0;
void dfs(long long v,int deep,int frst, int lst,int idx) {
	if (deep == 0) {
		if ((v >= L) && (v <= R) && (lst - frst >= X)) {
	//		cout << frst << " " << lst << " " << v << "\n";
			++answer;
		}
		return;
	}
	else {
		--deep;
		++idx;
		if (idx >= N)
			return;

		if (deep == 0) {
			lst = num[idx];
		}

		dfs(v + num[idx], deep, frst, lst, idx);

		++deep;
		dfs(v, deep, frst, lst, idx);

	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("Input.txt", "r", stdin);

	cin >> N >> L >> R >> X;
	for (int a = 0; a < N; ++a)
		cin >> num[a];
	
	sort(num, num + N);

	for (int a = 2; a <= N; ++a) {
		for (int b = 0; b < N; ++b) {
			dfs(num[b], a-1,num[b],0,b);
		}
	}
	cout << answer;
	return 0;
}

