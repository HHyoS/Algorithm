
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

unordered_map<string, int> mp;
string color[6] = { "blue","green","yellow","orange","red","purple" };
void init() {
	mp["blue"] = 0;
	mp["green"] = 1;
	mp["yellow"] = 2;
	mp["orange"] = 3;
	mp["red"] = 4;
	mp["purple"] = 5;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	init();
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (t1 == t2) {
			cout << "E\n";
		}
		else {
			int AIndex = (mp[t1] + 1) % 6;
			int AAIndex = (mp[t1] + 5) % 6;
			int CIndex = (mp[t1] + 3) % 6;
			if (mp[t2] == AIndex || mp[t2] == AAIndex) {
				cout << "A\n";
			}
			else if (mp[t2] == CIndex) {
				cout << "C\n";
			}
			else {
				cout << "X\n";
			}
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
