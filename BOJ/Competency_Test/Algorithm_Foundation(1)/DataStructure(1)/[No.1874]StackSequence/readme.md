문제 사이트 : https://www.acmicpc.net/problem/1874

문제 설명 :

	스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다.
	
	스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 
	
	제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.

	1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다.
	
	이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 
	
	임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 
	
	있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.

입력

	첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다. 물론 같은 정수가 두 번 나오는 일은 없다.

출력

	입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.

예제 입력 1 

	8
	4
	3
	6
	8
	7
	5
	2
	1

예제 출력 1 

	+
	+
	+
	+
	-
	-
	+
	+
	-
	+
	+
	-
	-
	-
	-
	-
	
예제 입력 2 

	5
	1
	2
	5
	3
	4

예제 출력 2 

	NO

코드 및 설명

	#include <stdio.h>
	#include <cstring>

	#define MAX 100001
	using namespace std;

	char giho[400001] = {}; // 가장 초기 코드에는 class 안에 포함되어 있었지만, class 내부에 변수로 작성할 경우 char 배열의 크기제한이 있어 전역변수로 내보내어 사용하였습니다.
	int giho_index = 0;
	class Hs { // Hyosang stack.  [ push , pop , top ] 세가지 기능만을 가지고 있는 stack
	private:
		int arr[MAX] = { 0 , };
		int index;
	public:
		Hs() {
			index = 0;
		}

		void push(int X) {
			arr[++index] = X;
		}

		void pop() {
			--index;
		}

		int top() {
			if (index <= 0) return -1;
			else return arr[index];
		}


	};



	int main() {

		int n;
		Hs hs;
		int arr[100001];

	//	freopen("Input.txt", "r", stdin);
		scanf("%d", &n);
		for (int a = 1; a <= n; ++a) {
			scanf("%d", &arr[a]);
		}

		int num = 1; // stack에는 1부터 n까지 순서대로 입력되므로 num이라는 변수를 이용하여 입력실행
		int check = 0;
		for (int a = 1; a <= n;) { // a의 움직임을 두번째 while문을 이용하여 이동시키므로 뒤에 a의 증감을 넣지않았습니다.
			check = a; // 주어진 수열의 인덱스를 의미하는 
			while (num <= arr[a]) { // 현재 stack에 넣으려는 숫자가 주어진 수열 arr[a]의 위치값과 일치할 때까지 push
				hs.push(num++);
				giho[giho_index++] = '+';
				giho[giho_index++] = '\n';
			}
			while (hs.top() == arr[a]) { // hs stack의 맨 위 값이 arr[a]의 위치와 같다면 pop연산 실행
				hs.pop();
				giho[giho_index++] = '-';
				giho[giho_index++] = '\n';
				++a; // arr 배열의 위치를 한칸이동하여 비교 재실행
			}
			if (check == a) { / a값이 변하지 않았다면 첫번째 while문에서 arr[a]와 일치하는 값이 존재하지 않았음을 의미하므로 반복문을 반복하더라도 원하는 수열을 완성할 수 없으므로  
				printf("NO"); // No 출력후 프로그램 종료
				return 0;
			}
		}
		printf("%s", giho); // 모든 반복문을 성공적으로 수행했다면 print!
		return 0;
	}

stack의 push, pop 연산을 이용하여 주어진 수열과 일치하는 수열을 만들 수 있는지 확인하는 문제였습니다.

제가 생각한 풀이방법은 

	  1. 1부터 n까지 순서대로 입력받을 stack 을 구현하고

	  2. 주어진 수열을 저장할 int 배열 [ arr 배열 ] 선언

	  3. arr를 위치를 나타내는 index를 사용하여 for 반복문을 실행하고, arr[index]보다 작거나 같은 수라면 stack에 push 연산 실시.

	  4. stack의 top부분의 값과 arr[index]의 값이 같다면 pop 연산 실시 후 index 증가

	  5. 3~4 과정을 하면서 push 연산과 pop 연산을 할때마다 연산의 과정을 저장하는 char 배열에 '+' or '-' 를 입력하고 개행 문자 '\n' 추가

	  6. 만약 3~4 의 실행을 지난 이후에도 index값에 변화가 없다면 3의 연산에서 arr[index]값과 일치하는 값이 없었다는 것을 의미하므로 "NO'출력

	  7. 아니라면 모든 반복문을 성공적으로 수행했으므로 char배열  print

위 문제를 풀면서 고민한 것은 메모리 사용과 실행시간 줄이기 였습니다.

초기에 작성한 코드에는 print를 giho_index만큼 for문을 반복하여 출력하며 메모리와 실행시간 사용이 높았습니다.

이를 개선하기 위해 print 할 때, 한번에 출력하는 방법은 고민하게 되었고, Hs 클래스에서 giho char배열을 전역변수로 뺴면서 실행시간을 개선하였습니다.

추가 개선예정 - 수열을 하나하나 입력받으면서 진행하면 arr배열의 사용이 불필요할것으로 보입니다. 그래서 arr배열을 제거하고 103번의 for문을 하는 과정에서 scanf로 입력받는다면 메모리 사용이 줄어들것으로 예상되어 도전해보려고 합니다.

과거 코딩했던 문제에서는 미리 입력받아 저장하는방법이 실행시간이나 메모리 면에서 더 효율적이였지만, 입력값이 십만개 이상 되는 문제에서 해당 방법을 사용하면 개선이 될지 도전해보겠습니다.





---------------------------------------------------------------------------------- 2차 개선(메모리 사용) 완료-------------------------------------------------------------------------------

	#include <stdio.h>
	#include <cstring>

	#define MAX 100001
	using namespace std;

	char giho[400001] = {};
	int giho_index = 0;
	class Hs {
	private:
		int arr[MAX] = { 0 , };
		int index;
	public:
		Hs() {
			index = 0;
		}

		void push(int X) {
			arr[++index] = X;
		}

		void pop() {
			--index;
		}

		int top() {
			if (index <= 0) return -1;
			else return arr[index];
		}


	};



	int main() {

		int n;
		Hs hs;

	//	freopen("Input.txt", "r", stdin);
		scanf("%d", &n);

		int num = 1;
		int inp = 0;
		for (int a = 0; a < n; ++a) { // 1차 개선 코드에서 미리 입력받아 arr배열에 저장하여 사용하던 수열을
			scanf("%d", &inp);  // 203 line의 for문을 사용하면서 하나하나 입력받아 사용하여 arr배열의 사용이 불필요 해졌고, 그를 통해 메모리 사용을 개선시켰습니다. 
			while (num <= inp) { // 추가적으로 개선이 있을 수 있다면. 210 line의 if문을 while문으로 고쳐서 a의 값을 변경시켜서 무의미하게 205 line의 while 조건문을 false를 발생시키는 연산을 줄여보려고합니다.
				hs.push(num++); 
				giho[giho_index++] = '+';
				giho[giho_index++] = '\n';
			}
			if (hs.top() == inp) {
				hs.pop();
				giho[giho_index++] = '-';
				giho[giho_index++] = '\n';
			}
			else {
				printf("NO");
				return 0;
			}
		}
			printf("%s", giho);
		return 0;
	}
