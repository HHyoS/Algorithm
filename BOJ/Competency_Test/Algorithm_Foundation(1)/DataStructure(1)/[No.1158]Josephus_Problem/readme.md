문제 사이트 : https://www.acmicpc.net/problem/1158

문제 설명 :

	요세푸스 문제는 다음과 같다.

	1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 
	
	이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
	
	이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 
	
	예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

	N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

입력

	첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 5,000)

출력

	예제와 같이 요세푸스 순열을 출력한다.

예제 입력 1 

	7 3
	
예제 출력 1 

	<3, 6, 2, 7, 5, 1, 4>

코드 및 풀이 // 현재 4% 이후 "틀림" 발생으로 여러 반례를 대입하면서 수정 중입니다. 21.11.03 풀이완료


	#include <cstdio>
	#include <cstring>
	#include <stdlib.h>

	using namespace std;

	struct Node { // 현재 값과 다음 위치의 Node 주소값을 저장하는 Node 구조체 선언
		int value = 0;
		struct Node *tail = NULL;
	};

	Node nd[5001];
	int main() {

		int n, k;
	//	freopen("Input.txt", "r", stdin);
		scanf("%d %d", &n,&k);
		for (int a = 1; a <= n; ++a) { // 입력받은 n을 바탕으로 nd[1] ~ nd[n]에   1 , 2 , 3 , 4 .... n 저장
			nd[a].value = a ;
			nd[a].tail = &nd[a + 1];
		}

		nd[n].tail = &nd[1]; // nd[n]의 다음 node는 nd[1];


		Node* ptr = &nd[n]; // Node들의 주소를 바탕으로 탐색을 이어나갈 Node의 주소를 저장하는 변수 ptr 선언 후 nd[n]의 주소입력
		printf("<");
		for (int a = 1; a < n; ++a) {
			for (int b = 0; b < k-1; ++b) { // ptr의 주소를 k-1번만큼 ptr = ptr->tail; 을 반복하고
				ptr = ptr->tail;
			}
			printf("%d, ", ptr->tail->value); // ptr->tail->value 값을 print한뒤
			ptr->tail = ptr->tail->tail; // ptr->tail에 ptr->tail->tail 값을 저장하는 동작으로, ptr->tail을 요세푸스 순열값에 사용 후 Node연결에서 제외시킴
		} 
		printf("%d>", ptr->value); // 마지막 남은값을 출력
		return 0;
	}

주어진 n개의 정수 수열에서 k번 건너뛰기를 한 뒤 해당값을 출력하고 제거하는 행위를 n번 반복하여 요세푸스 수열을 출력하는 문제였습니다.

해당 문제의 해결 조건은 다음과 같았습니다

	1. n과 k가 입력되면, 1~n 의 정수가 존재하는 n길이의 수열을 만들고, 원형으로 연결시킵니다.

	2. k번 건너뛰기 한 값을 출력하고, 제거하는 행위를 남은 정수가 없을때까지 반복

으로 정리할 수 있습니다.

해당 조건을 만족하기 위해 

	1. 현재 값과 연결된 다음 노드의 주소를 저장하는 구조체 Node를 선언.

	2. Node[1] ~ Node[n] 까지, (Node[1] =1 , Node[1].tail = &Node[2]), (Node[2] =2 , Node[2].tail = &Node[3]) 과 같은 연산을 반복하여 노드들끼리 연결시켰습니다.

	3. 그 이후 다음의 알고리즘을 통해 문제를 해결했습니다.

	  Node[1]-Node[2]-Node[3]
	    |               |
	  Node[6]-Node[5]-Node[4] 

	 [1] 주어진 원형 수열이 있고, 처음의 ptr이 Node[6] k값이 2가 된다면

	 Node[1]-{ Node[2] }-Node[3]     
	    |               |
	  Node[6]-Node[5]-Node[4] 

	 [2] ptr이 가리키는 주소는 Node[1], 그 이후 Node[1]->tail->value 인 Node[2] 값이 출력되고, 

	 Node[1]---------Node[3]     
	    |               |
	  Node[6]-Node[5]-Node[4]    


	 [3] Node[1]->tail을 Node[3]과 연결시켜 Node[2]를 원형 수열에서 사용하지 않는 Node로 만들어 제거처리합니다.

	 [4] 이 행위를 반복하는 코드가 다음과 같습니다.


		for (int a = 1; a < n; ++a) {
			for (int b = 0; b < k-1; ++b) { // ptr의 주소를 k-1번만큼 ptr = ptr->tail; 을 반복하고
				ptr = ptr->tail;
			}
			printf("%d, ", ptr->tail->value); // ptr->tail->value 값을 print한뒤
			ptr->tail = ptr->tail->tail; // ptr->tail에 ptr->tail->tail 값을 저장하는 동작으로, ptr->tail을 요세푸스 순열값에 사용 후 Node연결에서 제외시킴
		} 

// 53~54 line의 for문의 사용이 n * (k-1) 번 만큼 반복하는 시간복잡도인해 실행시간이 약간 발생하였는데, 이 부분을 개선하는 방법을 찾아보려고 합니다.
