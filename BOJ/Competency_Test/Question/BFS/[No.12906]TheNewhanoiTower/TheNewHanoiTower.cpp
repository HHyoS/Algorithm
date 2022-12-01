#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt[3];
	array <string, 3 > s;
	for (int i = 0; i < 3; i++) {
		cin >> cnt[i];
		if (cnt[i] == 0) {
			s[i] = "";
		}
		else {
			cin >> s[i];
		}
	}

	int ans_count[3] = { 0, 0, 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			ans_count[s[i][j] - 'A']++;
		}
	}
	
	map< array<string, 3>, int > d;
	queue< array<string, 3> > q;
	q.push(s);
	d[s] = 0;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				if (now[i].length() == 0) continue;
				auto next = now;
				next[j].push_back(next[i].back());
				next[i].pop_back();
				if (d.count(next) == 0) {
					d[next] = d[now] + 1;
					q.push(next);

				}
			}
		}

	}

	array< string, 3> ans;
  
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < ans_count[i]; j++) {
			ans[i] += 'A' + i;
		}
	}
	cout << d[ans] << '\n';

	
	return 0;
}
