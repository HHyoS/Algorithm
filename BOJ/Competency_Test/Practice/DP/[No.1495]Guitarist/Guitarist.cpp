#include <iostream>
#include <cstring>
using namespace std;
 
int sound[1010];
int DP[1010][2];
 
int main(int argc, char *argv[])
{
 
	int N, S, M;
	cin >> N >> S >> M;
 
	for (int a = 1; a <= N; ++a) {
		cin >> sound[a];
	}
 
	DP[S][0] = 1;
 
	for (int a = 1; a <= N; ++a) {
		for (int b = 0; b <= M; ++b) {
			if (DP[b][0] != 0) {
				if (b - sound[a] >= 0) {
					DP[b - sound[a]][1] = 1;
				}
				if (b + sound[a] <= M) {
					DP[b + sound[a]][1] = 1;
				}
			}
		}
		for (int b = 0; b <= M; ++b) {
			DP[b][0] = DP[b][1];
			DP[b][1] = 0;
		}
	}
	
	for (int a = M; a >= 0; --i) {
		if (DP[a][0] == 1) {
			cout << a << endl;
			break;
		}
		if (a == 0) {
			cout << "-1" << endl;
		}
	}
 
 	return 0;
}
