#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

long long N;
int arr[1000001];
int answer[1000001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("Input.txt", "r", stdin);

	cin >> N;
	int temp;
	stack<int> st;
	for (int a = 0; a < N; ++a) {
		cin >> arr[a];
	}
	for (int a = N - 1; a >= 0; --a) {
		while(!st.empty() && (arr[a] >= st.top())) {
			st.pop();
		}  
		if (st.empty())
			answer[a] = -1;
		else
			answer[a] = st.top();
		st.push(arr[a]);
	}
	for (int a = 0; a < N; ++a) {
		cout << answer[a] << " ";
	}
	return 0;
}
