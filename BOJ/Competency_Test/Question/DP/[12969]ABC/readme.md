문제 사이트 : https://www.acmicpc.net/problem/12969

문제 설명 :

	정수 N과 K가 주어졌을 때, 다음 두 조건을 만족하는 문자열 S를 찾는 프로그램을 작성하시오.

	문자열 S의 길이는 N이고, 'A', 'B', 'C'로 이루어져 있다.
	문자열 S에는 0 ≤ i < j < N 이면서 S[i] < S[j]를 만족하는 (i, j) 쌍이 K개가 있다.

입력

	첫째 줄에 N과 K가 주어진다. (3 ≤ N ≤ 30, 0 ≤ K ≤ N(N-1)/2)

출력

	첫째 줄에 문제의 조건을 만족하는 문자열 S를 출력한다. 가능한 S가 여러 가지라면, 아무거나 출력한다. 만약, 그러한 S가 존재하지 않는 경우에는 -1을 출력한다.

예제 입력 1 

	3 3

예제 출력 1 

	ABC

예제 입력 2 

	3 0

예제 출력 2 

	CBA

예제 입력 3 

	5 10

예제 출력 3 

	-1

예제 입력 4 

	15 36

예제 출력 4 

	CABBACCBAABCBBB


코드 및 풀이 

	#include <iostream>
	#include <vector>
	#include <string>
	using namespace std;

	bool cache[31][31][31][450];
	char ans[32];

	int N, K;
	// n의 수 , a의 수, b의 수 , k의 수
	bool solve(int n, int a, int b, int k)
	{
		if (n == N) {
			if (K == k) return true;
			else return false;
		}

		if (cache[n][a][b][k]) return false;
		cache[n][a][b][k] = true;

		ans[n] = 'A';
		// a값이 추가 된다면 a보다 작은 것은 없기에 k는 추가 되지 않는다. 
		if (solve(n + 1, a + 1, b, k)) return true;

		//배열이니 덮어쓴다.
		ans[n] = 'B';
		// b값이 추가 되면 이전에 있던 a값들 만큼 k에 ++ 될것. a < b < c
		if (solve(n + 1, a, b + 1, k + a)) return true;

		ans[n] = 'C';
		// C가 추가 되면 a, b값들 만큼 k에 ++ 될것. a < b < c
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

1. n은 0부터 N까지 증가하게 되면서 A나 B나 C를 담는다고 생각하면,

2. 많은 답중 하나만 맞으면 되기 때문에 ans배열에 재귀호출시 마다 A,B,C를 저장. A를 저장했다가 실패시 B를 저장하고 재귀호출 실패시 C를 저장하고 재귀호출 하면 문제해결!
