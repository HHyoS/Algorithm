#include <string>
#include <vector>

using namespace std;

int pibo[100001];
int solution(int n) {
    int answer = 0;
    pibo[0] = 0;
    pibo[1] = 1;
    for(int a = 2; a <= n; ++a){
        pibo[a] = (pibo[a-1]+pibo[a-2])%1234567;
    }
    return answer = pibo[n];
}
