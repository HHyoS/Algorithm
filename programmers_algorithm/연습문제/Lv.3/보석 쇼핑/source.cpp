#include <string>
#include <vector>
#include <unordered_map>
#include <memory.h>
#include <iostream>
using namespace std;

unordered_map<string,int> mp;
int used[100001];
vector<int> solution(vector<string> gems) {
    memset(used,0,sizeof(used));
    vector<int> answer;
    int typeCnt = 0;
    for(int a = 0; a < gems.size(); ++a){
        if(mp.count(gems[a])==0){
            mp[gems[a]] = mp.size()+1;
        }
    }
    typeCnt = mp.size();
    // 현재 왼쪽 위치
    int left = 0;
    
    int right = 1;
    int totalCnt = 1;
    int ans= 21e8;
    int startIdx= -1;
    int endIdx = -1;
    used[mp[gems[0]]] = 1;
    int size = gems.size();
    while(left <= right){
        if(totalCnt < typeCnt){
            if(right >= size)
                break;
            int idx = mp[gems[right++]];
            if(used[idx] == 0){
                ++totalCnt;
            }
            used[idx]++;
        }
        else{
            if(totalCnt == typeCnt){
                int nowleng = right-left;
                if(ans > nowleng){
                    ans = nowleng;
                    startIdx = left;
                    endIdx= right-1;
                }
            }
            int idx = mp[gems[left]];
            used[idx]--;
            if(used[idx]==0){
                totalCnt--;
            }
            left++;
        }
    }
    answer.push_back(startIdx+1);
    answer.push_back(endIdx+1);
    return answer;
}
