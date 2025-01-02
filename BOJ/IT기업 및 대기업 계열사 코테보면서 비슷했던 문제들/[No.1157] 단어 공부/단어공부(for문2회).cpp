#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int stone;
string word;
int cnt[30];
void Solve() {
	int size = word.size();
	int first = 28;
	int second = 29;
	for (int a = 0; a < size; ++a) {
		char alpa;
		if (word[a] >= 'a' && word[a] <= 'z') {
			alpa = word[a] - 'a';
		}
		else {
			alpa = word[a] - 'A';
		}
		cnt[alpa]++;

		if (cnt[alpa] >= cnt[first]) {
			if (alpa != first) {
				second = first;
			}
			first = alpa;
		}
	}
	
	if (cnt[first] == cnt[second])
		cout << "?";
	else
		cout << char(first + 'A');
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
