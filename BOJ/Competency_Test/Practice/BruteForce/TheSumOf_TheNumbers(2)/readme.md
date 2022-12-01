문제 사이트 : https://www.acmicpc.net/problem/2003

문제 설명 :

	N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다.
	
	이 수열의 i번째 수부터 j번째 수까지의 합 A[i] + A[i+1] + … + A[j-1] + A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.
	
입

	첫째 줄에 N(1 ≤ N ≤ 10,000), M(1 ≤ M ≤ 300,000,000)이 주어진다. 다음 줄에는 A[1], A[2], …, A[N]이 공백으로 분리되어 주어진다. 각각의 A[x]는 30,000을 넘지 않는 자연수이다.

출력

	첫째 줄에 경우의 수를 출력한다.

예제 입력 1 

	4 2
	1 1 1 1

예제 출력 1 

	3


코드 및 설명

	#include <iostream> 상

	// 비트마스크를 이용하였고, 상하좌우 숫자가 칸막이를 상하, 좌우로 친다고 정의하고, 
	// 가로와 세로를 0 or 1을 넣어도 최대값만 구하면 되는 이 문제에서는 똑같은 경우가 나오므로 가로를 0, 세로를 1로 정하여 풀이를 시작하였습니다. 
	// 종이 조각을 0과 1로 표시하는 식으로 구성하고, 0은 가로로 이어지는 조각, 1은 세로로 이어지는 조각으로 하였습니다.
	// 그렇게되면 모든 종이조각 판의 경우의 수를 만든뒤 가로, 세로로 한번씩 반복문을 돌려 최대값을 업데이트 후 동작하게 되며
	// countMAX()에서 MAX가 최대가 되는 값을 찾고출력하도록하여 문제를 해결했습니다. 

	using namespace std;

	int N, M;
	int paper[4][4];

	int countMax()
	{
		int MAX = 0;
		int sum = 0;
		for(int bitMask = 0; bitMask < (1 << N * M); ++bitMask) {
			//horizonal traverse
			for(int i = 0; i < N; ++i) {
				int tmp = 1;
				for(int j = M - 1; j >= 0; --j) {
					if(~bitMask & (1 << (i * M + j))) {
						sum += tmp * paper[i][j];
						tmp *= 10;
					}
					else tmp = 1;
				}
			}

			for(int i = 0; i < M; ++i) {
				int tmp = 1;
				for(int j = N - 1; j >= 0; --j) {
					if(bitMask & (1 << (j * M + i))) {
						sum += tmp * paper[j][i];
						tmp *= 10;
					}
					else tmp = 1;
				}
			}
			if(MAX < sum) MAX = sum;
			sum = 0;
		}
		return MAX;
	}

	int main()
	{
		string temp;
		cin >> N >> M;
		for(int i = 0; i < N; ++i) {
			cin >> temp;
			for(int j = 0; j < M; ++j) 
				paper[i][j] = static_cast<int>(temp[j] - '0');
		}
		cout << countMax();

		return 0;
	}
