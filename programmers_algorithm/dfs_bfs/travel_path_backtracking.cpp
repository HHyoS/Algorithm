#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
 
using namespace std;
    
vector<string> vt;

void dfs(vector<vector<string>> tickets, int index, string begin, vector<string> path){
    tickets.erase(tickets.begin() +index);
    path.push_back(begin);
    if(!vt.empty() && !path.empty()){
        for(int a = 0; a < path.size(); ++a){
            if(vt[a] < path[a])
                return;
            else if(vt[a] > path[a])
                break;
        }
    }
    if(tickets.empty())
        vt.assign(path.begin(), path.end());
    else{
        for(int a= 0; a < tickets.size(); ++a){
            if(begin == tickets[a][0])
                dfs(tickets, a, tickets[a][1], path);
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> path;
    path.push_back("ICN");
    
    for(int a = 0; a < tickets.size(); ++a){
        if(tickets[a][0] == "ICN")
            dfs(tickets, a, tickets[a][1], path);
        }
        return vt;
}
