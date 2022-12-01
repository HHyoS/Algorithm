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
