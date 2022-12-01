문제 사이트 : 

문제 설명 :

	3×3 표에 다음과 같이 수가 채워져 있다. 오른쪽 아래 가장 끝 칸은 비어 있는 칸이다.

	1	2	3
	4	5	6
	7	8	 
	
	어떤 수와 인접해 있는 네 개의 칸 중에 하나가 비어 있으면, 
	
	수를 그 칸으로 이동시킬 수가 있다. 물론 표 바깥으로 나가는 경우는 불가능하다. 
	
	우리의 목표는 초기 상태가 주어졌을 때, 최소의 이동으로 위와 같은 정리된 상태를 만드는 것이다. 다음의 예를 보자.

	1	 	3
	4	2	5
	7	8	6
	1	2	3
	4	 	5
	7	8	6
	1	2	3
	4	5	 
	7	8	6
	1	2	3
	4	5	6
	7	8	 
	
	가장 윗 상태에서 세 번의 이동을 통해 정리된 상태를 만들 수 있다. 이와 같이 최소 이동 횟수를 구하는 프로그램을 작성하시오.

입력

	세 줄에 걸쳐서 표에 채워져 있는 아홉 개의 수가 주어진다. 한 줄에 세 개의 수가 주어지며, 빈 칸은 0으로 나타낸다.

출력

	첫째 줄에 최소의 이동 횟수를 출력한다. 이동이 불가능한 경우 -1을 출력한다.

예제 입력 1 

	1 0 3
	4 2 5
	7 8 6
	
예제 출력 1 

	3

예제 입력 2 

	3 6 0
	8 1 2
	7 4 5
	
예제 출력 2 

	-1

코드

	#include <iostream> 
	#include <queue>
	#include <map>
	#include <string>
	using namespace std;
	queue < pair<string, pair<int, int>>> q;
	map <string, bool> m;
	int dx[4] = { -3, 3, -1, 1 };
	int success = -1, idx;
	string tmp;
	char tmp2;

	void Bfs() {
		while (!q.empty()) {
			if (q.front().first == "123456780") {
				success = q.front().second.second;
				break;
			}
			for (int i = 0; i < 4; i++) {
				tmp = q.front().first;
				idx = q.front().second.first + dx[i]; //0의 위치를 기준으로 상하좌우 검색
				if (i == 0 && !(idx >= 0 && idx < 6)) continue; //상
				else if (i == 1 && !(idx >= 3 && idx < 9)) continue; //하
				else if (i == 2 && !(idx >= 0 && idx < 8 && idx != 2 && idx != 5)) continue; //좌
				else if (i == 3 && !(idx >= 1 && idx < 9 && idx != 3 && idx != 6)) continue; //우
				tmp2 = tmp[idx];
				tmp[idx] = tmp[q.front().second.first];
				tmp[q.front().second.first] = tmp2; //위치 교환
				if (!m.count(tmp)) {
					m[tmp] = true;
					q.push(make_pair(tmp, make_pair(idx, q.front().second.second + 1)));
				}
			}
			q.pop();
		}
	}

	int main() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> tmp2;
				if (tmp2 == '0') idx = tmp.size();
				tmp += tmp2;
			}
		}
		q.push(make_pair(tmp, make_pair(idx, 0)));
		Bfs();
		cout << success;
		return 0;
	} 
