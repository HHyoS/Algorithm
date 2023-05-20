#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    int leng = s.length();
    for(int a = 0; a < leng; ++a){
        stack<char> st;
        bool flag = 0;
        for(int b = 0; b < leng; ++b){
            int index= (a+b)%leng;
            if(st.empty()){
                st.push(s[index]);
            }
            else if(s[index]=='(' || s[index] == '[' || s[index]=='{'){
                st.push(s[index]);
            }
            else{
                if(s[index] == ')'){
                    if(st.top() == '(')
                        st.pop();
                    else{
                        flag = 1;
                        break;
                    }
                }
                else if(s[index]== ']'){
                    if(st.top() == '['){
                        st.pop();
                    }
                    else{
                        flag = 1;
                        break;
                    }
                }
                else{
                    if(st.top() == '{'){
                        st.pop();
                    }
                    else{
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag == 1 || !st.empty())
            continue;
        ++answer;
    }
    return answer;
}
