문제 사이트 : https://www.acmicpc.net/problem/12869

문제 설명 : 

	수빈이는 강호와 함께 스타크래프트 게임을 하고 있다. 수빈이는 뮤탈리스크 1개가 남아있고, 강호는 SCV N개가 남아있다.

	각각의 SCV는 남아있는 체력이 주어져있으며, 뮤탈리스크를 공격할 수는 없다. 즉, 이 게임은 수빈이가 이겼다는 것이다.

	뮤탈리스크가 공격을 할 때, 한 번에 세 개의 SCV를 공격할 수 있다.

	첫 번째로 공격받는 SCV는 체력 9를 잃는다.
	두 번째로 공격받는 SCV는 체력 3을 잃는다.
	세 번째로 공격받는 SCV는 체력 1을 잃는다.
	
	SCV의 체력이 0 또는 그 이하가 되어버리면, SCV는 그 즉시 파괴된다. 한 번의 공격에서 같은 SCV를 여러 번 공격할 수는 없다.

	남아있는 SCV의 체력이 주어졌을 때, 모든 SCV를 파괴하기 위해 공격해야 하는 횟수의 최솟값을 구하는 프로그램을 작성하시오.

입력

	첫째 줄에 SCV의 수 N (1 ≤ N ≤ 3)이 주어진다. 둘째 줄에는 SCV N개의 체력이 주어진다. 체력은 60보다 작거나 같은 자연수이다.

출력

	첫째 줄에 모든 SCV를 파괴하기 위한 공격 횟수의 최솟값을 출력한다.

예제 입력 1 

	3
	12 10 4
	
예제 출력 1 

	2
	
예제 입력 2 

	3
	54 18 6
	
예제 출력 2 

	6

예제 입력 3 

	1
	60

예제 출력 3 

	7

예제 입력 4 

	3
	1 1 1

예제 출력 4 

	1

예제 입력 5 

	2
	60 40

예제 출력 5 

	9

힌트

	1, 3, 2 순서대로 공격을 하면, 남은 체력은 (12-9, 10-1, 4-3) = (3, 9, 1)이다. 2, 1, 3 순서대로 공격을 하면, 남은 체력은 (0, 0, 0)이다.

코드 및 설명 :

	#include <iostream>
	#include <algorithm>//min
	#include <cstring>//memset
	using namespace std;

	int N;
	int DP[61][61][61];
	int HP[3] = { 0, };//SCV없으면 그냥 0

	int solution(int x, int y, int z) {
		//파괴된 SCV가 있을 경우
		if (x < 0)return solution(0, y, z);
		if (y < 0)return solution(x, 0, z);
		if (z < 0)return solution(x, y, 0);

		//모든 SCV가 파괴된 경우
		if (x == 0 && y == 0 && z == 0)
			return 0;

		int& res = DP[x][y][z];

		//이미 구해둔 값이면
		if (res != -1)
			return res;

		res = 99999999;
		res = min(res, solution(x - 9, y - 3, z - 1) + 1);
		res = min(res, solution(x - 9, y - 1, z - 3) + 1);
		res = min(res, solution(x - 3, y - 9, z - 1) + 1);
		res = min(res, solution(x - 1, y - 9, z - 3) + 1);
		res = min(res, solution(x - 3, y - 1, z - 9) + 1);
		res = min(res, solution(x - 1, y - 3, z - 9) + 1);

		return res;
	}

	int main() {
		cin >> N;
		memset(DP, -1, sizeof(DP));
		for (int i = 0; i < N; i++) {
			cin >> HP[i];
		}
		cout << solution(HP[0], HP[1], HP[2]) << '\n';

		return 0;
	}

