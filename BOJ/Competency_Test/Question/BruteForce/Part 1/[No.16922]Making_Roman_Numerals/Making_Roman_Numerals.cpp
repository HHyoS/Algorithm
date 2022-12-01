#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
int N;
int roma[4] = { 1,5,10,50 };
bool check[1001];
int answer = 0;
void dfs(int count,int sum,int idx){
	if(count ==0){
		if (!check[sum]){
			check[sum] = 1;
			++answer;
		}
		return;
	}
	else {
		for (int a = idx; a < 4; ++a) {
			dfs(count - 1, sum + roma[a],a);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


//	freopen("Input.txt", "r", stdin);

	//dfs(X, Y,0);
	cin >> N;
	for (int a = 0; a < 4; ++a) {
		dfs(N - 1, roma[a],a);
	}

	cout << answer;
	return 0;
}
