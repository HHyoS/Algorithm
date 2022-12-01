문제 사이트 : https://www.acmicpc.net/problem/10845

문제 설명 :

	정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

	명령은 총 여섯 가지이다.

	push X: 정수 X를 큐에 넣는 연산이다.
	pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 큐에 들어있는 정수의 개수를 출력한다.
	empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
	front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	
입력

	첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
	둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력

	출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

예제 입력 1 

	15
	push 1
	push 2
	front
	back
	size
	empty
	pop
	pop
	pop
	size
	empty
	pop
	push 3
	empty
	front

예제 출력 1 

	1
	2
	2
	0
	1
	2
	-1
	0
	1
	-1
	0
	3

코드 및 풀이

	#include <iostream>
	#include <algorithm>
	#include <string>
	#define MAX_QUEUE_SIZE 10000
	using namespace std;

	struct h_que
	{
		int front = 0;
		int back = -1;
		int queue[MAX_QUEUE_SIZE];
		int size = 0;
	};


	int main() {

		cin.tie(NULL);
		ios::sync_with_stdio(false);

		h_que que;

		int n;

	//	freopen("Input.txt", "r", stdin);

		cin >> n;
		string command = "";

		for (int a = 0; a < n; ++a) {
			cin >> command;
			if (command == "push") {
				cin >> que.queue[++(que.back)];
				++(que.size);
			}
			else {
				if (command == "size") {
					cout << que.size;
				}
				else if (command == "empty") {
					if (que.size == 0)
						cout << "1";
					else
						cout << "0";
				}
				else {
					if (que.size == 0)
						cout << -1;
					else {
						if (command == "back") {

							cout << que.queue[que.back];
						}
						else {
							cout << que.queue[que.front];

							if (command == "pop") {
								que.front += 1;
								--(que.size);
							}

						}
					}
				}
				cout << endl;
			}

		}

		return 0;
	}

간단하게 구현한 큐 문제입니다.

h_que 라는 구조체를 설정하고, 정해진 규칙에 따라 동작을 수행하도록 구현하였습니다.

간단한 문제이기에 추가적인 설명은 추가적으로 하지않고 주석으로 대체하겠습니다.

그것 외에는 실행시간을 줄이기위해 클래스로 구현하여 다시 도전해보려고합니다.




-----------------------------------------------------------큐(개선) - 클래스를 구현하여 문제에서 요구하는 기능을 하도록 만듬!-----------------------------------------------------------





	#include <cstdio>

	#include <cstring> // 코드를 구현하여 실험해본 결과 string 타입을 읽는 cin의 기능이 char 배열형식을 읽어내는 scanf("%s",&string) 보다 더 빨른것을 확인했고, 사용해본 라이브러리 중

	// cstring 라이브러리가 가장 빠른것을 확인하여 사용하였습니다.

	using namespace std;

	class hq { // Hyosang Queue 의 줄임말 hq. 문제에서 요구하는 기능 1. 정수를 저장하는 큐 구현 2. push, pop, size, empty, ft(front), bk(back) 기능을 모두 구현
	private:
		int front, back; // 가장 앞의 숫자 -> front, push로 입력될 숫자의 위치 -> back
		int que[10001] = { 0, }; // 최대 10000개의 숫자라고 했으므로 10000 + 1(여유분)
	public:
		hq() {// 생성자를 이용한 front(가장 앞의 숫자)와 back(가장 뒤의 숫자) 초기화
			front = 0; 
			back = 0; 
		}

		void push(int x) { // push 기능의 구현으로 que[back]의 위차에 입력되는 숫자를 저장하고 back++ 연산자를 통해 저장 뒤 back 증가
			que[back++] = x; 
		}

		int pop() { // pop 기능의 구현으로 가장 앞의 숫자가 back보다 크거나(없어야 하는 케이스지만 혹시 모르므로) 같은(숫자가 없는 상태) 일 경우 -1, 아닐경우 가장 앞의 숫자를 return하고 front++
			if (front >= back) return -1;
			else return que[front++];
		}

		int size() { // size 기능의 구현으로, 처음에는 pop, push 기능을 수행할 때마다 size변수를 두어 증감시키려고 했으나, 모두 시간, 메모리낭비인것으로 생각되어 기능으로 분리
			return back - front; / back - front 가 que[10001]에 남은 정수의 갯수
		}

		int empty() { // empty 기능의 구현, front >= back 이라면 que안에 숫자가 없으므로 1, 아닐 경우 0 return
			if (front >= back) return 1;
			else return 0;
		}

		  /* 이 밑으로는 front, back 의 기능 구현으로 private의 변수와 이름이 겹쳐 ft(), bk()으로 함수를 선언하였고, que[10001]에 정수가 없는 케이스인 front >= back 일떄는 -1, 아닐 경우에는
		  ft() -> return que[front] / bk() -> return que[back-1] 하도록 하였습니다. back-1는 back은 가장 마지막의 숫자 위치가 아닌, 숫자가 입력될 위치를 나타내므로 back-1 하여 숫자를 return
		int ft() {
			if (front >= back) return -1;
			else return que[front];
		}

		int bk() {
			if (front >= back) return -1;
			else return que[back - 1];
		}
	};

	int main() {



		//	freopen("Input.txt", "r", stdin);

		int n;
		hq q;
		char command[15]; // 처음에는 명령어에 필요한 index 5, 숫자에 필요한 index 6, 공백 1 총 12 + 1(여유분) 으로 코딩했으나, 맞은 사람들이 구현하여 나온 실행시간이 0가 아닌
		// 4ms가 나왔고, 하나하나 늘려본결과 index가 15일때 실행시간이 0초가 되는것을 확인했습니다. .. 학교 수업시간에 메모리가 4K단위로 된다고 했었는데, 관련이 있을지도?
		scanf("%d", &n);
		int X;
		for (int a = 0; a < n; ++a) {
			scanf("%s", &command);
			if (command[0] == 'p') { // 첫 알파벳만으로 비교하여 실행시간과 메모리 단축
				if (command[1] == 'u') { // push일경우
					scanf("%d", &X);
					q.push(X);
				}
				else { // 아닐경우
					printf("%d\n", q.pop());
				}
			}
			else if (command[0] == 's') printf("%d\n", q.size()); //size

			else if (command[0] == 'e') printf("%d\n", q.empty()); // empty

			else if (command[0] == 'f') printf("%d\n", q.ft()); // front

			else if (command[0] == 'b') printf("%d\n", q.bk()); // back
		}

		return 0;
	}


