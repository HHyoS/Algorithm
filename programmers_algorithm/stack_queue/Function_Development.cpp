#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> t;
    int check = 0;
    int size= 0;
    int p_size = progresses.size();
    
    for(int a = 0; a < p_size; ++a)
        t.push(a);
    
    while(true){
        if(check != 0)
            answer.push_back(check);
        
        check=0;
        size = t.size();
        
        if(size ==0)
            break;
        
        for(int a = p_size - size; a < p_size; ++a)
            progresses[a] = progresses[a] + speeds[a];
        
        for(int c =0; c < size; ++c){
            if(progresses[t.front()] >= 100){
                t.pop();
                ++check;
            }
        }
    }
    return answer;
}
