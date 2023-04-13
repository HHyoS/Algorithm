#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    s += " ";
    int idx = 0;
    long long mini = 5000000000;
    long long maxi =-5000000000;
    while(1){
        int ret = s.find(" ",idx);
        if(ret == -1){
            break;
        }
        long long temp = stoll(s.substr(idx,ret-idx));
        if(mini > temp){
            mini = temp;
        }
        if(maxi < temp){
            maxi = temp;
        }
        idx = ret+1;
    }
    answer = to_string(mini)+ " " +to_string(maxi);
    return answer;
}
