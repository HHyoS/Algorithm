#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N, K;
int dp[101][100001]; 
int main(){
    memset(dp, 0, sizeof(dp));
    scanf("%d %d",&N,&K);
    int w, v, res=0;
    for(int a=1; a<=N; ++a){
        scanf("%d %d",&w,&v);  
        for(int b=1; b<=K; ++b){   
            dp[a][b] = max(dp[a][b], dp[a-1][b]);
            if(b>=w) dp[a][b] = max(dp[a][b], dp[a-1][b-w] + v);
            res = max(res, dp[a][b]);
        }
    }
    printf("%d",res);
    return 0;
}   
