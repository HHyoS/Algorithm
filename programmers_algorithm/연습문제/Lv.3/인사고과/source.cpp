#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Node{
    int idx;
    int work;
    int coworker;
};

Node temp[1000001];
bool cant[1000001];
vector<Node> ans;
bool cmp(Node a,Node b){
    if(a.work == b.work){
        return a.coworker > b.coworker;
    }
    return a.work > b.work;
}
bool ccmp(Node a,Node b){
    return a.work+a.coworker > b.work+b.coworker;
}

int solution(vector<vector<int>> scores) {
    memset(temp,0,sizeof(temp));
    memset(cant,0,sizeof(cant));
    ans.clear();
    int size = scores.size();
    for(int a = 0; a < size; ++a){
        temp[a] = {a,scores[a][0],scores[a][1]};
    }
    sort(temp,temp+size,cmp);
    for(int a= 0; a < size-1; ++a){
        if(cant[a] ==1 )continue;
        int work = temp[a].work;
        int coworker = temp[a].coworker;
        for(int b = a+1; b < size; ++b){
            if(cant[b] == 1) continue;
            if(work == temp[b].work) continue;
            if(coworker > temp[b].coworker)
                cant[b] = 1;
        }
    }

    for(int a = 0; a < size; ++a){
        if(cant[a] == 1) continue;
        ans.push_back(temp[a]);
    }
    sort(ans.begin(), ans.end(), ccmp);
    int ranking = 0;
    int wait = 1;
    int before = -1;
    for(int a = 0; a < ans.size(); ++a){
        if(before == ans[a].work + ans[a].coworker){
            ++wait;
        }
        else{
            ranking += wait;
            wait=1;
            before = ans[a].work + ans[a].coworker;
        }
        if(ans[a].idx == 0){
            return ranking;
        }
    }
    return -1;
}
