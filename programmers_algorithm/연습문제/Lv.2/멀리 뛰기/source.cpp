#include <string>
#include <vector>
#include <memory.h>
#include <iostream>
using namespace std;

long long jump[2001];
long long solution(int n) {
    memset(jump,0,sizeof(jump));
    
    jump[1] = 1;
    jump[0]=1;
    for(int a = 2; a <= n; ++a){
        jump[a] = (jump[a-1]+jump[a-2])%1234567;
    }
    long long answer = jump[n];
    return answer;
}
