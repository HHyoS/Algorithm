#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int n;
int main() {
//	freopen("Input.txt", "r", stdin);
	scanf("%d ", &n);
	char ch = ' ';
	stack<char> que;

	int size = 0;
	while(scanf("%c",&ch) != -1){
		if ((ch != ' ') && (ch != '\n')){
			que.push(ch);
		}
		else {
			size = que.size();
			for (int a = 0; a < size; ++a) {
				printf("%c", que.top());
				que.pop();
			}
			printf("%c",ch);
		}
		

	}
	return 0;
}
