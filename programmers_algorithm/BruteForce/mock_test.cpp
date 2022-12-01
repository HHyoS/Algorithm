#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool sortinrev(pair<int,int> a,  
               pair<int,int> b) 
{ 
       return (a.first > b.first); 
} 
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a,b,c;
    vector<pair<int, int>> grade;
    for(int g =1; g <= 3; ++g){
        grade.push_back(make_pair(0,g));
    }
    int abc = 0;
    a = {1, 2, 3, 4, 5 };
    b = {2, 1, 2, 3, 2, 4, 2, 5};
    c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    for(int t : answers){
        if(a[abc%a.size()] == t)
            ++grade[0].first;
        if(b[abc%b.size()] == t)
            ++grade[1].first;
        if(c[abc%c.size()] == t)
            ++grade[2].first;
        ++abc;
    }
    sort(grade.begin(), grade.end(), sortinrev);
    int maxG = grade[0].first;
    
    for(auto p : grade){
        if(p.first == maxG)
            answer.push_back(p.second);
        else
            break;
    }
        
    return answer;
}
