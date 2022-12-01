문제 사이트 : https://www.acmicpc.net/problem/10866

문제 설명 : 

	정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

	명령은 총 여덟 가지이다.

	push_front X: 정수 X를 덱의 앞에 넣는다.
	push_back X: 정수 X를 덱의 뒤에 넣는다.
	pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 덱에 들어있는 정수의 개수를 출력한다.
	empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
	front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	
입력

	첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
	둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 
	문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력

	출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

예제 입력 1 

	15
	push_back 1
	push_front 2
	front
	back
	size
	empty
	pop_front
	pop_back
	pop_front
	size
	empty
	pop_back
	push_front 3
	empty
	front
	
예제 출력 1 

	2
	1
	2
	0
	2
	1
	-1
	0
	1
	-1
	0
	3
	
예제 입력 2 

	22
	front
	back
	pop_front
	pop_back
	push_front 1
	front
	pop_back
	push_back 2
	back
	pop_front
	push_front 10
	push_front 333
	front
	back
	pop_back
	pop_back
	push_back 20
	push_back 1234
	front
	back
	pop_back
	pop_back
	
예제 출력 2 

	-1
	-1
	-1
	-1
	1
	1
	2
	2
	333
	10
	10
	333
	20
	1234
	1234
	20



코드(주석) 및 풀이 // 추가예정... 

	#include <cstdio>
	#include <cstring>
	#define MAX_QUEUE_SIZE 10000
	using namespace std;

	class Hd { // Hyosang Deque
	private:
		int start; // 시작햇는지 체크용
		int front, back;
		int que[20010] = { 0, };
	public:

		Hd() { // 선언되면 입력값이 최대 10000개 이므로 push_front, push_back 두가지 중 한가지 명령어를 만번했을경우를 가정하여 +10000  , - 10000 해도 인덱스를 벗어나지 않도록 생성자 실행
			start = 10005; // 시작안햇다면 10005가 입력 시작
			front = 0; // 빈 Hd에 size와 같은 명령어를 사용했을 때, 빈 Hd임을 표현하기 위해서 front = 0, back = 1 을 저장.
			back = 1;
		}
		void push_front(int x) { // front 선언시 
			if (start == 10005) { // 아직 Hd 에 한번도 push 명령어가 실행되지 않았다면
				que[start] = x; // start 위치에 x를 입력하고
				start = -1; // start는 비활성화
				front = 10004; // 이후 입력은 front, back에 입력
				back = 10006;
			}
			else // 이미 한번이상 입력이 실행되었다면
				que[front--] = x; // front에 x 입력후 front의 인덱스 한칸떙기기


		}

		void push_back(int x) { // push_front와 같은 동작으로, front가 아닌 back에 입력실시 
			if (start == 10005) {
				que[start] = x;
				start = -1;
				front = 10004;
				back = 10006;
			}
			else
				que[back++] = x; 
		}

// 이후 명령어들은 Hd에 저장된 정수가 없을경우 특정값을 출력하는 명령어들입니다.
// back - front = 2 일경우 Hd에 입력된 정수가 한 개인것을 의미하므로, back - front = 1 이거나 1 이하일경우 Hd에 정수가 없는상태를 의미하므로 back - front <= 1 -> back -1 <= front 일 경우 명령들을 실행시킬 수 없는 상태이기떄문에
// 해당 조건을 바탕으로 if문을 구성하여 출력하도록 구현하였습니다.

		int pop_front() {
			if (front >= back-1) return -1;


			else return que[++front];
		}

		int pop_back() {
			if (front >= back-1) return -1;
			else return que[--back];
		}

		int size() {
			return back - front - 1; // 사이즈 
		}

		int empty() {
			if (front >= back-1) return 1;
			else return 0;
		}

		int ft() {
			if (front >= back-1) return -1;
			else return que[front+1];
		}

		int bk() {
			if (front >= back-1) return -1;
			else return que[back-1];
		}
	};

	int main() {


	//	freopen("Input.txt", "r", stdin);

		int n;
		Hd q;
		char command[25];
		scanf("%d", &n);
		int X;
		for (int a = 0; a < n; ++a) {
			scanf("%s", &command);
			if (command[0] == 'p') {
				if (command[1] == 'u') {
					scanf("%d", &X);
					if (command[5] == 'f') {
						q.push_front(X);
					}
					else {
						q.push_back(X);
					}
				}
				else {
					if (command[4] == 'f')	printf("%d\n", q.pop_front());
					else printf("%d\n", q.pop_back());
				}
			}
			else if (command[0] == 's') printf("%d\n", q.size());

			else if (command[0] == 'e') printf("%d\n", q.empty());

			else if (command[0] == 'f') printf("%d\n", q.ft());

			else if (command[0] == 'b') printf("%d\n", q.bk());
		}

		return 0;
	}
