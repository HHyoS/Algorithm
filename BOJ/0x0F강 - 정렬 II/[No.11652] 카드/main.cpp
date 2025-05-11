#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
	long long idx;
	int cnt;
};

bool operator<(Node a, Node b) {  // 우선순위 큐 정렬이므로 반대로 세팅
	if (a.cnt == b.cnt) { // 등장 회수가 동일하면 작은 수 앞으로ㅗ
		return a.idx > b.idx;
	}
	return a.cnt < b.cnt; // 등장 회수가 많은 숫자가 우선순위 높음
}
int N;
priority_queue<Node> que;
unordered_map<long long,int> mp;
vector<long long> v;
void Solve() {
	for (int a = 0; a < v.size(); ++a) { // 벡터에 넣은 값을 우선순위 que에 넣어주자
		que.push({ v[a],mp[v[a]] });
	}


	cout << que.top().idx; // 맨 위에 있는 값이 정답.
}
void Input() {
	cin >> N;
	for (int a = 0; a < N; ++a) {
		long long tmp;
		cin >> tmp;
		if (mp.count(tmp) == 0) { // 일단 특정 숫자가  처음 사용되면 벡터에 넣어서 관리
			v.push_back(tmp);
			mp[tmp] = 1;
		}
		else { // 이미 있으면 +1만 해주기
			mp[tmp]++;
		}
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solve();
	return 0;
}
