#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int,int> check;
void dfs(vector<int> temp,int chance){
    if(temp.size() == 1&& (check[temp[0]] == 0)){
        check[temp[0]] = 1;
        return;
    }
    else{
        vector<int> tt;
        for(int a = 0; a < temp.size()-1; ++a){ 
            tt.assign(temp.begin(), temp.end());
            if(tt[a] > tt[a+1]){
                tt.erase(tt.begin()+a);
                dfs(tt, chance);
                if(chance ==1){
                    tt.assign(temp.begin(), temp.end());
                    tt.erase(tt.begin()+a+1);
                    dfs(tt, 0);
                }
            }
            else{
                tt.erase(tt.begin()+a+1);
                dfs(tt, chance);
                if(chance == 1){
                    tt.assign(temp.begin(), temp.end());
                    tt.erase(tt.begin()+a);
                    dfs(tt, 0);
                }
            }
        }
    }
}
int solution(vector<int> n) {
    int answer = 0;
    vector<int> temp;
    temp.assign(n.begin(), n.end());
    
    dfs(temp,1);
    for(int a : n){
        if(check[a] == 1)
            ++answer;
    }
    return answer;
        
}
