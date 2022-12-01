#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int N;
int person[1001];
int answer = 0;
int temp = 0;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("Input.txt", "r", stdin);

	cin >> N;
	for (int a = 0; a < N; ++a) {
		cin >> person[a];
	}
	sort(person, person + N);
	for (int a = 0; a < N; ++a) {
		answer = answer + temp + person[a];
		temp += person[a];
	}
	cout << answer;
	return 0;
}
