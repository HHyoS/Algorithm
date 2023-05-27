#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

int parent[10001];
bool visit[10001];
int T, N, A, B, u, v;

void input() {
	cin >> T;
	while (T--)
	{
		cin >> N;

		// 초기화
		for (int a = 1; a <= N; ++a)
		{
			visit[a] = false;
			parent[a] = a;
		}

		// 간선정보 입력
		for (int a = 0; a < N - 1; ++a)
		{
			cin >> A >> B;
			parent[B] = A;
		}

		// LCA 찾기
		cin >> u >> v;
		visit[u] = true;

		while (u != parent[u])
		{
			u = parent[u];
			visit[u] = true;
		}
		while (true)
		{
			if (visit[v])
			{
				cout << v << '\n';
				break;
			}
			v = parent[v];
		}

	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	
	input();

	return 0;	
}
