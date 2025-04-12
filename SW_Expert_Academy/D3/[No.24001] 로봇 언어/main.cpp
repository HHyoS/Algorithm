#include<iostream>
#include<algorithm>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string in_string;
		cin >> in_string;
		int ans_L = 0;
		int ans_R = 0;
		int maxi = 0;
		for (int a = 0; a < in_string.size(); ++a) {
			if (in_string[a] == 'L') {
				--ans_L;
				--ans_R;

			}
			else if (in_string[a] == 'R') {
				++ans_L;
				++ans_R;
			}
			else {
				--ans_L;
				++ans_R;
			}
			maxi = max(maxi,max(abs(ans_L), abs(ans_R)));
		}

		cout << abs(maxi) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
