#include<iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <memory.h>
#include <string>
using namespace std;



int Solve(const string &target) {


	int s = 0;
	int e = target.size() - 1;
	int cnt = 0;
	while (s <= e) {
		if (target[s] == target[e]) {
			++s;
			--e;
		}
		else {
			if (target[s] == 'x') {
				++s;
				++cnt;
			}
			else if (target[e] == 'x') {
				--e;
				++cnt;
			}
			else{
				return -1;
			}
		}
	}
	return cnt;
}


int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string target;
		cin >> target;
		
		cout << Solve(target) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
