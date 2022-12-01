#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int N;
int temp;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("Input.txt", "r", stdin);

	cin >> N;
	priority_queue<int> big;
	priority_queue<int, vector<int>, greater<int>> small;
	for (int a = 0; a < N; ++a) {
		cin >> temp;
		if (big.size() == small.size())
			big.push(temp);
		else
			small.push(temp);
		
		if(!big.empty() && !small.empty() && big.top()> small.top()){
			int big_num, small_num;

			big_num = big.top();
			small_num = small.top();

			big.pop();
			small.pop();

			big.push(small_num);
			small.push(big_num);
		}
		cout << big.top() << "\n";
	}
	return 0;
}
