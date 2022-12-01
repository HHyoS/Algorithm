문제 사이트 : https://www.acmicpc.net/problem/4375


문제 설명 : 

	2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.

입력

	입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, n이 주어진다.

출력

	1로 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다.

예제 입력 1 

	3
	7
	9901

예제 출력 1 

	3
	6
	12

코드



	#include <iostream>
	#include <algorithm>

	using namespace std;



	int main() {

		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n;
		//	freopen("Input.txt", "r", stdin);
		while (cin >> n) { // 입력받을 값이 없다면 cin은 -1을 반환하므로 while 조건문에 cin >> n 입력
			int num = 1; // 1로 이루어진 숫자를 담을 변수 ( n과 나눈 나머지값을 담을 변수)
			int tens = 1; // 자리수 체크
			while (1) {
				if (num % n== 0) // num % n 이 0이라면 1로 이루어진 n의 배수
					break;
				num = (num % n) * 10 + 1; // num % n 을 하여 값을 비교할때 num의 자리수가 증가하면 정수 오버플로우가 발생할 수 있으므로 num 의 값이 num * 1000 일때 나머지를 계산하는 수학공식을 생각해보면
	  // ( num * 1000 ) % n =  ( num % n) * ( num % n) * ( num % n) ... 이므로 계산하는 과정에서 미리 나눈다면 값을 줄여서 계산을 진행할 수 있습니다.
				++tens;
			}
			cout << tens << "\n"; // 자리수 출력.
		}
		return 0;
	}
  
해결 방법. 

	   초기에 문제를 풀때는 값의 증가를 생각하여 long long으로 변수를 선언하여 사용하였으나, 정수의 값이 커짐에 따라 계속 시간초과가 발생하였습니다.

	  그래서 해결방법을 찾던 중 나머지연산을 위의 코드와같이 사용하면 int 범위 내에서 빠르게 처리할 수 있음을 알게되었고 그를 활용하여 문제를 해결하였습니다.
