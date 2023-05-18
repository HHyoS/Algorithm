#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    int start = numbers.size()-1;
    vector<int> temp;
    for(int a = start; a >=0; --a){
        if(st.empty()){
            answer.push_back(-1);
            st.push(numbers[a]);
        }
        else if(st.top() <= numbers[a]){
            while(!st.empty()){
                if(st.top() <= numbers[a]){
                    st.pop();
                }
                else{
                    break;
                }
            }
            if(st.empty()){
                answer.push_back(-1);
            }
            else{
                answer.push_back(st.top());
            }
            st.push(numbers[a]);
            
        }
        else{
            answer.push_back(st.top());
            st.push(numbers[a]);
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
