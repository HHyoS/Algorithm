#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    s += " ";
    int leng = s.length();
    int idx = 0;
    int jump = 'a'-'A';
    while(1){
        int ret = s.find(" ",idx);
        if(ret == -1)
            break;
        
        if(s[idx] >= 'a' && s[idx]<='z'){
            s[idx] = s[idx]-jump;
        }
        for(int a = idx+1; a < ret; ++a){
            if(s[a] >= 'A' && s[a] <= 'Z'){
                s[a] = s[a]+jump;
            }
        }
        idx = ret+1;
    }
    return answer = s.substr(0,s.length()-1);
}
