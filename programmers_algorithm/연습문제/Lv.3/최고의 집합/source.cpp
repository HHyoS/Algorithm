#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int nanugi = s/n;
    
    if(nanugi == 0){
        answer.push_back(-1);
        return answer;
    }
    for(int a = 0; a < n; ++a){
        answer.push_back(nanugi);
    }
    
    int total = nanugi*n;
    int end = s-total;
    
    for(int a = 0; a < end; ++a){
        ++answer[n-a-1];
    }
    
    return answer;
}
