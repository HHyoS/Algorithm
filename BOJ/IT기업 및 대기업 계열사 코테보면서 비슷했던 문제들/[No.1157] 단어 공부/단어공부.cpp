#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int stone;
string word;
int cnt[30];
void Solve() {
	int size = word.size();
	int idx = 28;
	for (int a = 0; a < size; ++a) {
		char alpa;
		if (word[a] >= 'a' && word[a] <= 'z') { // 소문자면 'a' 빼주고 indexx 0부터 시작
			alpa = word[a] - 'a';
		}
		else { // 소문자면 'A' 빼주고 indexx 0부터 시작
			alpa = word[a] - 'A';
		}
		cnt[alpa]++;
		if (cnt[alpa] > cnt[idx]) { // 가장 많이 사용한 알파뱃 인덱스 저장
			idx = alpa;
		}
	}
	
	for (int a = 0; a < 27; ++a) { // 알파뱃 for문 돌면서 최대 값과 동일한 친구 확인
		if (a == idx) continue; // 자기 자신은 스킵해주고
		if (cnt[a] == cnt[idx]) { // 최대 갯수와 동일한 친구가 있으면 ? 출력
			cout << "?";
			return;
		}
	}

	cout << char(idx + 'A'); // 동일한 친구가 없다면 현재 index+'A' 더한 캐릭터형 출력
}
void Input() {
	cin >> word;
}
int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
    return 0;
}
