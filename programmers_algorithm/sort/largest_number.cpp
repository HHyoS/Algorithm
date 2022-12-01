#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;
bool compare(int a, int b){
    return to_string(a)+to_string(b) > to_string(b)+to_string(a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<int> tset;
    tset.assign(numbers.begin(), numbers.end());

    sort(tset.begin(), tset.end(), compare);
    for(auto t : tset){
        if((answer=="0" || answer=="") && t==0)
            answer = "0";
        else
            answer = answer + to_string(t);
    }
    return answer;
}
