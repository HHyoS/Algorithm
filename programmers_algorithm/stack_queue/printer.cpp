#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue<int> prio; 
    queue<pair<int,int>> q;
    for(int a = 0; a < priorities.size(); ++a){
        prio.push(priorities[a]); //Priority queue sorted in high priority order.
        q.push(make_pair(priorities[a], a));} // pair queue indicating the index of the target with priority 
        //and corresponding priority.
    
    while(true){
        if(q.front().first == prio.top()){  // Verify that the current target is a high-priority target.
            if(q.front().second == location) // Ensure that the target to pop is the target.
                break; 
            q.pop();
            prio.pop();
            ++answer; // Increase the number of times if printed
        }
        else{
            q.push(make_pair(q.front().first, q.front().second));
            q.pop(); // If there is another target with a high priority, push the current target
            //to the back and pop it at the front.
        }
    }
    return answer;
}
