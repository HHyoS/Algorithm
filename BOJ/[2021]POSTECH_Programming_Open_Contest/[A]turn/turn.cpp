#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
vector<int> arr;
long long gop[9] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000 };
int main() {

/*	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/

//	freopen("Input.txt", "r", stdin);
	int a = 0;
	int num;
	while (scanf("%1d", &num) != -1) {
		arr.push_back(num);
		++a;
	}
	long long answer = 0;
	int size = arr.size();
	for (int a = 0; a < size; ++a) {
		for (int b = 0; b < arr.size(); ++b) {
			answer = answer + (arr[(a+b)%size] * gop[size - b -1]);
		}
	}
	printf("%lld\n", answer);
	return 0;
}

