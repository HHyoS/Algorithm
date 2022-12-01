/*#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(int a = 0; a < participant.size(); a++){
        auto iter = find(completion.begin(), completion.end(), participant[a]);
        if(iter!= completion.end()){
           int index = distance(completion.begin(), iter);
            completion.erase(completion.begin()+index);
           }
        else{
            answer = participant[a];
            break;
    }
    }
    return answer;
}*/
// The above code passed the accuracy test but was re-coded using unordered_map to increase efficiency with less efficient code.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> ptp;
    
    for(string name : participant)
        ++ptp[name];
    
    for(string name : completion)
        --ptp[name];
    
    for(auto pair:ptp)
        if(pair.second > 0)
            return pair.first;
}
