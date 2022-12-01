문제 사이트 : https://www.acmicpc.net/problem/12906

문제 설명 : 

	오늘은 새로운 하노이 탑 게임을 해보려고 한다. 이 게임의 규칙은 다음과 같다.

	막대는 총 세 가지 종류가 있다. 막대 A, 막대 B, 막대 C
	
	게임이 시작될 때, 각각의 막대에는 0개 또는 그 이상의 원판이 놓여져 있다.
	
	모든 원판의 크기는 같으며, 원판의 종류도 A, B, C로 세 가지가 있다. 원판은 원판 A, 원판 B, 원판 C와 같이 표현한다.
	
	한 번 움직이는 것은 한 막대의 가장 위에 있는 원판을 다른 막대의 가장 위로 옮기는 것이다.
	
	게임의 목표는 막대 A에는 원판 A만, 막대 B는 원판 B만, 막대 C는 원판 C만 놓여져 있어야 한다.
	
	되도록 최소로 움직여야 한다.
	
	막대 A, 막대 B, 막대 C에 놓여져 있는 원판의 상태가 주어졌을 때, 게임의 목표를 달성하는데 필요한 움직임의 최소 횟수를 구하는 프로그램을 작성하시오.

입력

	첫째 줄에 막대 A에 놓여져 있는 원판의 개수와 막대 A의 상태,
	
	둘째 줄에 막대 B에 놓여져 있는 원판의 개수와 막대 B의 상태, 
	
	셋째 줄에 막대 C에 놓여져 있는 원판의 개수와 막대 C의 상태가 주어진다. 
	
	막대의 상태는 밑에 있는 원판부터 주어진다.

	각 막대의 상태는 A, B, C로만 이루어진 문자열이며, 모든 막대에 놓여져 있는 원판 개수의 합은 1보다 크거나 같고, 10보다 작거나 같다.


출력
	
	게임의 목표를 달성하는데 필요한 움직임의 최소 횟수를 출력한다.

예제 입력 1 

	1 A
	2 AA
	2 AA

예제 출력 1 

	4

예제 입력 2 

	1 B
	1 C
	1 A

예제 출력 2 

	5

예제 입력 3 

	3 CBA
	0
	0

예제 출력 3 

	5

힌트

	예제 2의 경우에 다음과 같이 움직이면 된다.

		원판 A를 막대 A로
		원판 C를 막대 C로
		원판 A를 막대 C로
		원판 B를 막대 B로
		원판 A를 막대 A로
		
	예제 3의 경우에 다음과 같이 움직이면 된다.

		원판 A를 막대 C로
		원판 B를 막대 B로
		원판 A를 막대 B로
		원판 C를 막대 C로
		원판 A를 막대 A로


코드

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
			// 0 일 경우 입력이 안들어오기 때문에
			// 직접 공백을 넣어준다.
			if (cnt[i] == 0) {
				s[i] = "";
			}
			// 이외에는 직접 입력
			else {
				cin >> s[i];
			}
		}

		int ans_count[3] = { 0, 0, 0 };
		// '++' 연산자 사용을 위해 '0' 초기화
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < cnt[i]; j++) {
				ans_count[s[i][j] - 'A']++;
				// 각 단어가 몇개인지 카운트
			}
		}

		// map< key, value >
		// array 자체를 key 로 사용하는 것이 포인트
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
		// 정답이 들어있는 key 값을 구현
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < ans_count[i]; j++) {
				ans[i] += 'A' + i;
			}
		}
		// value 가 정답이 된다.
		cout << d[ans] << '\n';


		return 0;
	}
