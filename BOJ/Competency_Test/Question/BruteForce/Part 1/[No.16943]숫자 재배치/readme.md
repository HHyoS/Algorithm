문제 사이트 : https://www.acmicpc.net/problem/16943

문제 설명 :

    두 정수 A와 B가 있을 때, A에 포함된 숫자의 순서를 섞어서 새로운 수 C를 만들려고 한다. 
    
    즉, C는 A의 순열 중 하나가 되어야 한다. 

    가능한 C 중에서 B보다 작으면서, 가장 큰 값을 구해보자. C는 0으로 시작하면 안 된다.

입력

    첫째 줄에 두 정수 A와 B가 주어진다.

출력

    B보다 작은 C중에서 가장 큰 값을 출력한다. 그러한 C가 없는 경우에는 -1을 출력한다.

제한

    1 ≤ A, B < 109

예제 입력 1 

    1234 3456

예제 출력 1 

    3421

예제 입력 2 

    1000 5

예제 출력 2 

    -1

예제 입력 3 

    789 123

예제 출력 3 
    
    -1
    
풀이 알고리즘

    두 숫자가 N1, N2 가 주어질 때, N1의 각 자리수를 사용하여 N2보다 작은 수 중 가장 큰 수를
    
    만들고, 가능할 경우 출력, 아니면 -1 출력을 하는 문제였습니다.
    
    빠르게 문제를 해결하기 위해, 숫자를 string으로 입력받고 , N1을 내림차순으로 정렬한 후
    
    큰 숫자부터 사용하여 조건에 맞는 가장 큰 수를 만들고, 만들어 졌다면 모든 숫자만들기를
    
    종료시키는 방식으로 알고리즘을 구현했습니다.
    
    문제를 풀면서 계속 오류가 생겼던 부분은 만들어야하는 숫자가 N1 < 새로운 숫자 < N2 라고
    
    생각하고 있었는데, 새로운 숫자는 N1보다 커야하는 조건이 따로 존재하지 않았습니다.
    
    그래서 그 부분을 수정하여 문제를 해결하였습니다.
    
구 현

#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

string first;
string second;
long long f, s;


vector<char> ch;
long long maxi = -1;
bool checker[12];
char ans[12];
bool flag = 0;
void dfs(int deep) {
	if (flag)
		return;
	if (deep == ch.size()) {
		string answer = ans;
		long long bignum = stoll(answer);
		if (bignum < s) {
			maxi = bignum;
			flag = 1;
		}
		return;
	}

	for (int a = 0; a < ch.size(); ++a) {
		if (deep == 0 && ch[a] == '0') continue;
		if (!checker[a]) {
			checker[a] = 1;
			ans[deep] = ch[a];
			dfs(deep + 1);
			checker[a] = 0;
		}
	}
}
void solve() {
		dfs(0);
}
void input() {
	cin >> first >> second;

	for (int a = 0; a < first.length(); ++a)
		ch.push_back(first[a]);

	f = stoll(first);
	s = stoll(second);
	sort(ch.begin(), ch.end(),greater<char>());

}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	cout << maxi;
	return 0;

}
