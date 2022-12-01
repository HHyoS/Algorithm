#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

char stick[100010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);

	cin >> stick;
	int answer = 0;
	int count = 0;
	for (int a = 0; stick[a]; ++a) {
		if (stick[a] == '(') {
			if (stick[a + 1] == ')') {
				answer += count;
				++a;
			}
			else {
				++count;
			}
		}
		else {
			++answer;
			--count;
		}
	}
	cout << answer;
	return 0;
}
