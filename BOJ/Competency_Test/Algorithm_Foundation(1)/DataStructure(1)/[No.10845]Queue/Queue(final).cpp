#include <cstdio>
#include <cstring>
#define MAX_QUEUE_SIZE 10000
using namespace std;

class hq {
private:
	int front, back;
	int que[10001] = { 0, };
public:
	hq() {
		front = 0;
		back = 0;
	}

	void push(int x) {
		que[back++] = x;
	}

	int pop() {
		if (front >= back) return -1;
		else return que[front++];
	}

	int size() {
		return back - front;
	}

	int empty() {
		if (front >= back) return 1;
		else return 0;
	}

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
	char command[20];
	scanf("%d", &n);
	int X;
	for (int a = 0; a < n; ++a) {
		scanf("%s", &command);
		if (command[0] == 'p') {
			if (command[1] == 'u') {
				scanf("%d", &X);
				q.push(X);
			}
			else {
				printf("%d\n", q.pop());
			}
		}
		else if (command[0] == 's') printf("%d\n", q.size());

		else if (command[0] == 'e') printf("%d\n", q.empty());

		else if (command[0] == 'f') printf("%d\n", q.ft());

		else if (command[0] == 'b') printf("%d\n", q.bk());
	}

	return 0;
}
