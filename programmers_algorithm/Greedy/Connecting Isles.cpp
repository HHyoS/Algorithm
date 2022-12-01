#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(bool check[], vector<int> temp, vector<vector<int>> map, int n, int& answer){
    int mini = 99999;
    int last = -1;
    for(int ab : temp)
        for(int a = 0; a < n; ++a)
            if(check[a] == false && map[ab][a] != 9999)
                if(mini > map[ab][a]){
                    last = a;
                    mini = map[ab][a];
                }
            
    if(last != -1){
        check[last] = true;
        temp.push_back(last);
        answer += mini;
        dfs(check,temp, map, n, answer);
        }
}
int solution(int n, vector<vector<int>> costs) {
    bool check[n];
    int answer = 0;
    vector<vector<int>> ar(n, vector<int>(n,0));
    
    for(int a = 0; a < n; ++a){
        check[a] = false;
        for(int b = 0; b < n; ++b){
            if(a==b)
                ar[a][b] = 0;
            else
                ar[a][b] = 9999;
        }
    }
    for(auto c : costs){
        ar[c[0]][c[1]] = c[2];
        ar[c[1]][c[0]] = c[2];
    }
    vector<int> temp;
/*    for(int a = 0; a < n; ++a){
        if(check[a] == false){
            temp.push_back(a);
            check[a] = true;
            dfs(check, temp, ar, n, answer);
        }
    }unnecessary code */ 
    
            temp.push_back(0);
    
    temp.clear();
    ar.clear();
    return answer;
}
