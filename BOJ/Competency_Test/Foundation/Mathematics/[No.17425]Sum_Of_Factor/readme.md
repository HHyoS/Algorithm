문제 사이트 : https://www.acmicpc.net/problem/17425

문제 설명 : 

	두 자연수 A와 B가 있을 때, A = BC를 만족하는 자연수 C를 A의 약수라고 한다. 
	
	예를 들어, 2의 약수는 1, 2가 있고, 24의 약수는 1, 2, 3, 4, 6, 8, 12, 24가 있다. 
	
	자연수 A의 약수의 합은 A의 모든 약수를 더한 값이고, f(A)로 표현한다.
	
	x보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값은 g(x)로 표현한다.

	자연수 N이 주어졌을 때, g(N)을 구해보자.

입력

	첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 100,000)가 주어진다. 둘째 줄부터 테스트 케이스가 한 줄에 하나씩 주어지며 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

출력

	각각의 테스트 케이스마다, 한 줄에 하나씩 g(N)를 출력한다.

예제 입력 1 

	5
	1
	2
	10
	70
	10000

예제 출력 1 

	1
	4
	87
	4065
	82256014

해결 알고리즘

	1. 주어진 처음에 테스트케이스 갯수를 생각하지않고 케이스 당 계산을 하는 알고리즘을 구현했을 때 시간 초과가 발생했었습니다. 
	2. 주어진 테스트 케이스가 최대 100,000개이므로, 만약 각 테스트케이스에 대해서 합을 구하는 연산 보다는 미리 계산한 뒤 값을 주는 방법이 시간적으로 더욱 효율적.
	3. 자연수의 범위는 1,000,000 까지고, 1 ~ 1,000,000 사이의 값들이 가지는 약수의 합은 int범위 내에서 처리가 가능.
	4. g(N) = g(N-1) + f(N) 이므로 DP 방식을 이용한 알고리즘으로 해결가능!

[ 구현 ]
	
  	for (int a = 1; a <= 1000000; ++a) {
		for (int b = 1; a * b <= 1000000; ++b) {
			arr[a * b] += a;
		}
	}

(1) arr배열은 f(a)를 의미하고,
(2) arr[a*b] += a 는 A = BC라는 약수의 성질을 이용하여 B자리에 올 수 있는 값을 찾아내어, f(a)를 완성시키는 점화식입니다.


	sum[1] = 1; 
	for (int a = 2; a <= 1000000; ++a) {
		sum[a] = sum[a - 1] + arr[a];
	}

(3) sum 배열은 g(N)을 의미하는 배열. sum[1] = 1 은 for문을 2부터 시작하기위 미리 입력된 값으로, 없어도 큰 의미는 없습니다.
(4) sum[a] = sum[a - 1] + arr[a] 는 위의 풀이 알고리즘 4. 에서 언급했던 점화식으로 for문을 반복하여 g(a)를 채워나가는 점화식입니다. 


	for (int a = 0; a < n; ++a) {
		cin >> num;
		cout << sum[num] << "\n";
  }
  
(5) 준비된 g(N)을 출력!
