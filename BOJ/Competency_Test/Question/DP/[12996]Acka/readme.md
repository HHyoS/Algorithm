문제 사이트 : https://www.acmicpc.net/problem/12996

문제 설명 :

	BOJ 알고리즘 캠프에 강사로 참여하고 있는 dotorya, kesakiyo, hongjun7은 301호에서 도원결의를 맺고 프로젝트 아이돌 그룹 Acka을 결성했다. 

	Acka의 데뷔 앨범에는 총 S개의 곡이 수록될 예정이다. 각각의 곡은 세 사람중 적어도 한 명이 불러야 한다. 즉, 어떤 곡은 두 사람이 불러도 되고, 세 사람이 모두 함께 불러도 된다.

	세 사람이 녹음해야 하는 곡의 수가 주어질 때, 앨범을 만들 수 있는 방법의 수를 구하는 프로그램을 작성하시오.

	두 앨범 A와 B가 있을 때, 참여한 사람이 다른 곡이 존재한다면, 두 앨범은 다른 앨범이라고 한다. 

입력

	첫째 줄에 앨범에 포함된 곡의 개수 S와 dotorya, kesakiyo, hongjun7이 불러야 하는 곡의 수가 주어진다. (1 ≤ S ≤ 50, 1 ≤ dotorya, kesakiyo, hongjun7 ≤ S)

출력

	첫째 줄에 앨범을 만들 수 있는 방법의 수를 1,000,000,007로 나눈 나머지를 출력한다.

예제 입력 1 

	3 1 1 1

예제 출력 1 

	6

예제 입력 2 

	3 3 1 1

예제 출력 2 

	9

예제 입력 3 

	50 10 10 10

예제 출력 3 

	0

예제 입력 4 

	18 12 8 9

예제 출력 4 

	81451692

예제 입력 5 

	50 25 25 25

예제 출력 5 

	198591037




코드

	#include <iostream>
	#include <cstring>//memset
	using namespace std;

	int S;
	long long DP[51][51][51][51];
	int Mod = 1000000007;

	long long solution(int S, int a, int b, int c) {
		//모든 곡 다 불렀으면
		if (S == 0) {
			//각자 불러야 하는 곡 다 불렀으면
			if (a == 0 && b == 0 && c == 0) {
				return 1;
			}
			else
				return 0;
		}

		long long& res = DP[S][a][b][c];
		//이미 구해 놓은 경우면
		if (res != -1)
			return res;
		res = 0;

		res += solution(S - 1, a - 1, b, c);//a만 부를 경우
		res += solution(S - 1, a, b - 1, c);//b만 부를 경우
		res += solution(S - 1, a, b, c - 1);//c만 부를 경우
		res += solution(S - 1, a - 1, b - 1, c);//a,b가 부를 경우
		res += solution(S - 1, a - 1, b, c - 1);//a,c가 부를 경우
		res += solution(S - 1, a, b - 1, c - 1);//b,c가 부를 경우
		res += solution(S - 1, a - 1, b - 1, c - 1);//a,b,c가 부를 경우
		res %= Mod;

		return res;
	}

	int main() {
		int a, b, c;
		memset(DP, -1, sizeof(DP));
		cin >> S >> a >> b >> c;
		cout << solution(S, a, b, c) << '\n';

		return 0;
	}

풀이

	DP의 메모이제이션으로 풀어야 하는 문제였습니다.

	위의 주석을 제외하고 추가설명을 덧붙이면 3명을 a,b,c라고 했을 때 곡을 부르는 경우는 (a),(b),(c),(a,b),(a,c),(b,c),(a,b,c) 이렇게 7가지가 있으므로

	각 곡마다 중복을 제거하면서 더해주는 방식으로 문제를 풀이하였습니다.

	DP[s][x][y][z] 변수는 곡이 s개 남고 a가 x곡, b가 y곡, c가 z곡 남았을 때의 경우의 수를 의미합니다.
