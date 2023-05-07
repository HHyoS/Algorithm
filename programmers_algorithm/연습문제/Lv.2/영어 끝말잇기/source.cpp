#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,bool> mp;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    int turn = 1;
    int size = words.size();
    int idx = 1;
    
    // 첫번째 사람은 어찌됫는 첫 단어에서 짤릴일이 없음
    mp[words[0]]=1;
    char before = words[0].back();
    
    for(int a = 1; a < size; ++a){
        if((before != words[a][0]) || (mp.count(words[a])==1)){
            answer[0] = idx+1;
            answer[1] = turn;
            break;
        }
        else{
            before = words[a].back();
            mp[words[a]] = 1;
            ++idx;
            if(idx == n){
                idx = 0;
                ++turn;
            }
        }
    }
    return answer;
}
