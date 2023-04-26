#include <string>
#include <vector>
#include <memory.h>
#include <iostream>
using namespace std;

int dp[100001];
int solution(int n, vector<int> money) {
    int answer = 0;
    
    int size = money.size();
    dp[0] = 1;
    for(int a = 0; a < size; ++a){
        
        for(int b = money[a]; b <= n; ++b){
            dp[b] = (dp[b]+dp[b-money[a]])%1000000007;
        }
    }
    
    return answer = dp[n];
}
