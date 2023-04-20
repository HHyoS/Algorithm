#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct Node{
    int idx;
    int value;
};

bool operator<(Node a,Node b){
    if(a.value == b.value){
        return a.idx < b.idx;
    }
    return a.value < b.value;
}
priority_queue<Node> que;
int solution(vector<int> stones, int k) {
    
    int size = stones.size(); 
    for(int a = 0; a < k; ++a){
        que.push({a,stones[a]});
    }
    int mini = que.top().value;
    for(int a = k; a < size; ++a){
        que.push({a,stones[a]});
        
        int end = a-k+1;
        while(1){
            if(que.top().idx < a-k+1){
                que.pop();
            }
            else{
                mini = min(mini,que.top().value);
                break;
            }
                
        }
    }
    
    int end = size-k;
    while(!que.empty()){
        if(que.top().idx < end){
            que.pop();
        }
        else{
            mini = min(mini,que.top().value);
            break;
            que.pop();
        }
    }
    return mini;
}
