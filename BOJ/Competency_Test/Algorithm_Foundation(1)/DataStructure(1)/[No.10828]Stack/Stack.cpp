#include <stdio.h>
#include <cstring>

#define MAX 10001
using namespace std;

class Hs {
private:
	int arr[MAX] = { 0 , };
	int index;
public :
	Hs() {
		index = 0;
	}

	void push(int X) {
		arr[++index] = X;
	}
	
	int pop() {
		if (index <= 0) return -1;
		else return arr[index--];
	}

	int size() {
		return index;
	}

	int empty() {
		if (index <= 0) return 1;
		else return 0;
	}

	int top() {
		if (index <= 0) return -1;
		else return arr[index];
	}
};


int main() {

	int n;
	char ss[16];
	int num = 0;
	Hs st;
//	freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	for (int a = 0; a < n; ++a) {
		scanf("%s", &ss);
		if (ss[0] == 'p') {
			if (ss[1] == 'u') {
				scanf("%d\n", &num);
				st.push(num);
			}
			else {
				printf("%d\n", st.pop());
			}
		}
		else if (ss[0] == 't') {
			printf("%d\n", st.top());
		}
		else if (ss[0] == 's') {
			printf("%d\n", st.size());
		}
		else if (ss[0] == 'e') {
			printf("%d\n", st.empty());
		}
	}
	return 0;
}
