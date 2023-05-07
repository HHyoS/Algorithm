#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
using namespace std;

struct Node{
    int idx;
    int cnt;
};
int arr[100030];
unordered_map<int,int> mp;
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int maxi = 0;
    for(int a = 0; a < tangerine.size(); ++a){
        if(mp.count(tangerine[a])==0){
            mp[tangerine[a]]= mp.size();
        }
        int idx = mp[tangerine[a]];
        arr[idx]++;
    }
    sort(arr,arr+mp.size(),greater<int>());
    int tempK = k;
    int size = mp.size();
    for(int a = 0;a < size; ++a){
        tempK -= arr[a];
        if(tempK <= 0){
            answer = a+1;
            break;
        }
    }
    if(answer == 0)
        answer = mp.size();
    return answer;
}
