문제 사이트 : https://www.acmicpc.net/problem/5557

문제 설명 : 

상근이가 1학년 때, 덧셈, 뺄셈을 매우 좋아했다. 상근이는 숫자가 줄 지어있는 것을 보기만 하면, 마지막 두 숫자 사이에 '='을 넣고, 나머지 숫자 사이에는 '+' 또는 '-'를 넣어 등식을 만들며 놀고 있다. 예를 들어, "8 3 2 4 8 7 2 4 0 8 8"에서 등식 "8+3-2-4+8-7-2-4-0+8=8"을 만들 수 있다.

상근이는 올바른 등식을 만들려고 한다. 상근이는 아직 학교에서 음수를 배우지 않았고, 20을 넘는 수는 모른다. 따라서, 왼쪽부터 계산할 때, 중간에 나오는 수가 모두 0 이상 20 이하이어야 한다. 예를 들어, "8+3+2-4-8-7+2+4+0+8=8"은 올바른 등식이지만, 8+3+2-4-8-7이 음수이기 때문에, 상근이가 만들 수 없는 등식이다.

숫자가 주어졌을 때, 상근이가 만들 수 있는 올바른 등식의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 숫자의 개수 N이 주어진다. (3 ≤ N ≤ 100) 둘째 줄에는 0 이상 9 이하의 정수 N개가 공백으로 구분해 주어진다.

출력
첫째 줄에 상근이가 만들 수 있는 올바른 등식의 개수를 출력한다. 이 값은 263-1 이하이다.

예제 입력 1 
11
8 3 2 4 8 7 2 4 0 8 8
예제 출력 1 
10
예제 입력 2 
40
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
예제 출력 2 
7069052760


코드


	#include <iostream>
	#include <cstring>
	using namespace std;

	int n = 0, val = 0;
	int arr[100] = { 0 };
	long long before[21] = { 0 };
	long long current[21] = { 0 };

	int main() {
		cin >> n;
		for (int a = 0; a < n-a; ++a) {
			cin >> arr[a];
		}
		cin >> val;

		before[arr[0]] = 1; 
		for (int a = 1; a < n - 1; ++a) {
			memset(current, 0, sizeof(current));
			for (int b = 0; b <= 20; b++) {
				if (before[b] != 0){
					if ((b + arr[a]) <= 20)
						current[(b + arr[a])] += before[b];
					if((b - arr[a]) >= 0)
						current[(b - arr[a])] += before[b];
				}
			}
			for (int b = 0; b <= 20; ++b)
				before[b] = current[b];

		}

		cout << current[val] << '\n';
	}

해설

위 코드는 현재값을 저장하는 current 배열과 이전값을 저장하는 before배열을 정의하고 시작합니다.

초기 입력값을 arr배열에 입력받아 저장한 뒤, 2중 for문을 통해 dp 방식으로 이전 값을 저장하는 before[x] 값을 이용하여 before 배열값에서 current 값을 더하고, 빼는 연산을 통해

cureent 배열에 저장하도록 하였습니다. 2중 for문이 종료 된 이후 마지막값의 인덱스[val]의 current 배열값을 출력합니다. 
