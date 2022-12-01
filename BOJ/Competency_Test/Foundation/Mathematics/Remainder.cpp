#include <string>
#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	printf("%d\n",(a+b)%c);
	printf("%d\n",((a%c)+(b%c))%c);
	/*	abc = ((a & (c - 1)) + (b & (c - 1))) & (c - 1);
		cba = ((a & (c - 1)) * (b & (c - 1))) & (c - 1);*/
		// 비트연산을 사용해서 구현해보려고 햇으나 쉽지가않다..
	printf("%d\n",(a*b)%c);
	printf("%d\n",((a%c)*(b%c))%c);
	return 0;
}
 
