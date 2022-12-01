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
	int arr[100001];

//	freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	for (int a = 1; a <= n; ++a) {
		scanf("%d", &arr[a]);
	}

	int num = 1;
	int check = 0;
	for (int a = 1; a <= n;) {
		check = a;
		while (num <= arr[a]) {
			hs.push(num++);
			giho[giho_index++] = '+';
			giho[giho_index++] = '\n';
		}
		while (hs.top() == arr[a]) {
			hs.pop();
			giho[giho_index++] = '-';
			giho[giho_index++] = '\n';
			++a;
		}
		if (check == a) {
			printf("NO");
			return 0;
		}
	}
	printf("%s", giho);
	return 0;
}
