#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    st.push(s[0]);
    for(int a = 1; a< s.size(); ++a){
        if(st.empty() || st.top() != s[a]){
            st.push(s[a]);
        } 
        else{
            st.pop();
        }
    }
    if(st.empty())
        answer = 1;

    return answer;
}
