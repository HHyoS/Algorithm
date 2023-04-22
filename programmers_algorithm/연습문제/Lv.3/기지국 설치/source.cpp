#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int getTower(int now, int left,int leng){
    int namuzi = (left-now)%leng;
    int cnt = (left-now)/leng;
    if(left == now)
        return 1;
    if(namuzi != 0){
        cnt += 1;
    }
    return cnt;
}
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int now = 1;
    int leng = w*2+1;
    int size = stations.size();
    
    int left =0;
    int right = 0;
    for(int a = 0; a < size; ++a){
        left = max(1,stations[a]-w);
        right = min(stations[a]+w, n);
        if(now < left){
            answer= answer + getTower(now,left,leng);
        }
        now = right+1;
    }
    if(right < n){
        answer = answer + getTower(now,n,leng);
    }
    return answer;
}

