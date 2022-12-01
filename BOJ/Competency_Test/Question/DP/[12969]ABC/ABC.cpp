#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool cache[31][31][31][450];
char ans[32];

int N, K;
bool solve(int n, int a, int b, int k)
{
	if (n == N) {
		if (K == k) return true;
		else return false;
	}

	if (cache[n][a][b][k]) return false;
	cache[n][a][b][k] = true;

	ans[n] = 'A';
	if (solve(n + 1, a + 1, b, k)) return true;
	
	ans[n] = 'B';
	if (solve(n + 1, a, b + 1, k + a)) return true;

	ans[n] = 'C';
  
	if (solve(n + 1, a, b, k + a + b)) return true;

	return false;
}
int main()
{
	cin >> N >> K;
	if (solve(0, 0, 0, 0))
		cout << ans << "\n";
	else
		cout << -1 << "\n";
	return 0;
}
