#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int start;
    int end;
};

bool cmp(Node a,Node b){
    if(a.end == b.end){
        return a.start < b.start;
    }
    return a.end < b.end;
}
vector<Node> v;
int solution(vector<vector<int>> targets) {
    int answer = 1;
    for(int a =0; a < targets.size(); ++a){
        v.push_back({targets[a][0],targets[a][1]});
    }
    sort(v.begin(),v.end(), cmp);
    int end = v[0].end;
        
    for(int a =1; a < targets.size(); ++a){
        if(v[a].start >= end){
            ++answer;
            end = v[a].end;
        }
    }
    return answer;
}
