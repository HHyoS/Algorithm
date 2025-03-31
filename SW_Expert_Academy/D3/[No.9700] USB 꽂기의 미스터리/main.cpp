#include<iostream>

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
		double p, q;
		cin >> p >> q;

    // 확률 계산하기
		double s1 = (1 - p) * q;
		double s2 = p * (1 - q) * q;

    
		cout << "#" << test_case << " ";
		if (s1 > s2) {
			cout <<"NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
