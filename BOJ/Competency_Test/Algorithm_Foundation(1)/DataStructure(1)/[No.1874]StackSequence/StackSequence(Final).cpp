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



int main() { // 1차 개선 코드보다 메모리 사용이 줄어든 코드입니다.

	int n;
	Hs hs;

//	freopen("Input.txt", "r", stdin);
	scanf("%d", &n);

	int num = 1;
	int inp = 0;
	for (int a = 0; a < n; ++a) { 
		scanf("%d", &inp); // 기존 코드에서는 미리 입력받아 arr배열에 넣어 사용했지만, 2차 개선 코드에서는 46의 for문을 이용하여 입력 즉시 사용하여 arr배열을 사용하지 않아 메모리 사용이 줄어들었씁니다.
		while (num <= inp) {
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
