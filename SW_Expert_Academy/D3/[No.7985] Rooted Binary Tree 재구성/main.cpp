#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> inorder;
vector<vector<int>> levels;

// l..r 구간으로 서브트리를 구성하며, 현재 깊이를 depth에 기록
void build(int l, int r, int depth) {
    if (l > r) return;
    int mid = (l + r) / 2;
    levels[depth].push_back(inorder[mid]);
    build(l, mid - 1, depth + 1);
    build(mid + 1, r, depth + 1);
}
int main(int argc, char** argv)
{
	int test_case;
	//freopen("input.txt", "r", stdin);
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;                      // 트리 깊이 n
		int size = (1 << n) - 1;       // 노드 수 = 2^n - 1

		inorder.resize(size);
		for (int i = 0; i < size; i++) {
			cin >> inorder[i];        // 중위 순회 결과 입력
		}

		levels.assign(n + 1, {});     // 깊이 1..n 사용

		build(0, size - 1, 1);        // 깊이 1부터 트리 구성

		cout << "#" << test_case << " ";
		// 결과 출력: 깊이 1~n
		for (int d = 1; d <= n; d++) {
			for (int x : levels[d]) {
				cout << x << ' ';
			}
			cout << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
