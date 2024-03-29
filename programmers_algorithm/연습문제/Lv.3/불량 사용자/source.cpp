#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
set<string> s;
bool check[8]={false,};
int len;
vector<string> bi,ui;

void dfs(int idx){
    if(idx==len){
        string str="";
        for(int i=0;i<ui.size();i++){
            if(check[i]) str+=(i+'0');            
        }
        s.insert(str);
        return;
    }
    for(int a=0;a<ui.size();++a){
        if(check[a]) continue;
        string su = ui[a];
        string sb = bi[idx];
        if(su.size()!=sb.size()) continue;
        bool avail=true;
        for(int b=0;b<su.size();++b){
            if(sb[b]=='*') continue;
            if(sb[b]!=su[b]){
                avail=false;
                break;
            }
        }
        if(avail){
            check[a]=true;
            dfs(idx+1);
            check[a]=false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    len = banned_id.size();
    bi = banned_id;
    ui = user_id;
    
    dfs(0);
    return answer = s.size();
}
