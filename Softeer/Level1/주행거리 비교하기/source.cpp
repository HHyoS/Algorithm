#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int N,M;
	cin >> N >> M;
	if(N==M)
		cout << "same";
	else if(N > M)
		cout << "A";
	else if(N < M)
		cout << "B";
	return 0;
}
