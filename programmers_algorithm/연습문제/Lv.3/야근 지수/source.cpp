#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> que;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    int size = works.size();
    for(int a = 0; a < size; ++a){
        que.push(works[a]);
    }
    for(int a = 0; a < n; ++a){
        if(que.top() == 0) break;
        int num = que.top();
        que.pop();
        que.push(num-1);
    }
    
    while(!que.empty()){
        long long num = que.top();
        que.pop();
        answer += (num*num);    
    }
    
    return answer;
}
