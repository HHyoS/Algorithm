문제 사이트 : https://www.acmicpc.net/problem/3085

문제 설명 : 

	상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

	가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 
	
	상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다.
	
	이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

	사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

입력

	첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

	다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

	사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

출력

	첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.

예제 입력 1 

	3
	CCP
	CCP
	PPC

예제 출력 1 

	3

예제 입력 2 

	4
	PPPP
	CYZY
	CCPY
	PPCC

예제 출력 2 

	4

예제 입력 3 

	5
	YCPZY
	CYZZP
	CCPPP
	YCYZC
	CPPZZ

예제 출력 3 

	4

풀이 알고리즘

	1. 주어진 N의 크기는 3 ~ 50 이므로 크기가 50인 char배열을 생성.
	2. 4가지 색을 사용한다고 했지만, 출력되는 값은 연속된 최대길이의 값만이 필요하므로 구분할 필요는 크게없음
	3. 두 칸의 값을 바꾸는 연산은 한 탐색당 한번.
	4. 한 번 바꿔서 최대길이의 값을 찾은 이후에는 다시 위치를 바꿔야함.

[ 구현 ]

[ 위치 바꾸기 연산 ]

	char temp;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			temp = arr[a][b];
			if (a < n - 1) {
				if (arr[a][b] != arr[a + 1][b]) {
					arr[a][b] = arr[a + 1][b];
					arr[a + 1][b] = temp;
					check();
					arr[a + 1][b] = arr[a][b];
					arr[a][b] = temp;
				}
			}

			if (b < n - 1){
				if (arr[a][b] != arr[a][b+1]) {
					arr[a][b] = arr[a][b + 1];
					arr[a][b + 1] = temp;
					check();
					arr[a][b + 1] = arr[a][b];
					arr[a][b] = temp;
				}
			}

		}
	}
	cout << big;
	
 1. 2중 for문을 이용하여 탐색실시
 2. 55 ~ 77 line의 코드는 → , ↓ 방향으로 이동하며 바꾸는 연산으로, 다음 위치의 값이 현재 위치의 값과 같다면 연산은 진행 X
 3. 다르면 위치를 바꾼뒤, check() 함수 호출하여 최대값 찾기 실시.
 


[ check() 함수 ]

	void check() {
		for (int a = 0; a < n; ++a) {
			int count = 1;
			char stand = arr[a][0];
			int ccount = 1;
			char sstand = arr[0][a];
			for (int b = 1; b < n; ++b) {
				if (stand == arr[a][b])
					++count;
				else {
					if (count > big)
						big = count;
					count = 1;
					stand = arr[a][b];
				}
			}
			if (count > big)
				big = count;


			for (int b = 1; b < n; ++b) {
				if (sstand == arr[b][a])
					++ccount;
				else {
					if (ccount > big)
						big = ccount;
					ccount = 1;
					sstand = arr[b][a];
				}
			}
			if (ccount > big)
				big = ccount;
		}
	}

  4. 위의 코드는 구현한 check() 함수로. 가로, 세로로 진행하며 같은 값이 연속된 최대길이는 찾아냄
  

  
  
