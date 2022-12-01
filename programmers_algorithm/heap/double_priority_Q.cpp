#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer; 
    vector<int> test;
    bool check;
    for(int a = 0; a < operations.size(); ++a){
        if(operations[a].at(0) =='I'){
            test.push_back(atoi(operations[a].substr(2).c_str()));
            check = false;
        }
        else if(operations[a].at(0) =='D' && !test.empty()){
            if(!check){
                sort(test.begin(), test.end());
                check = true;
            }
            if(operations[a].length() == 3){
                test.erase(test.end()-1);
            }
            else
                test.erase(test.begin());
        }
            
    }
    sort(test.begin(), test.end());
    if(test.empty()){
        answer.push_back(0);
        answer.push_back(0);}
    else{
        answer.push_back(test[test.size()-1]);
        answer.push_back(test[0]);
    }
    return answer;
}
