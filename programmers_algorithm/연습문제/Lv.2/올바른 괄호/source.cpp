#include<string>
#include <iostream>
#include <vector>
using namespace std;
vector<char> v;
bool solution(string s)
{
    bool answer = true;
    int leng = s.length();
    for(int a = 0; a < leng; ++a){
        if(s[a] == '('){
            v.push_back(s[a]);
        }
        else{
            if(v.size() == 0 || v.back() == ')')
                return 0;
            else
                v.pop_back();
        }
    }
    if(v.size() > 0)
        answer = false;
    return answer;
}
