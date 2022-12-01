#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(vector<vector<int>> map, int parent, int deep, int array[]){
    ++deep;
    for(auto a : map[parent]){
        if(array[a] > deep){
            array[a] = deep;
            dfs(map, a, deep, array);
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> map;
    vector<int>temp;
    int array[n+1];
    for(int a = 0; a <= n; ++a){
        map.push_back(temp);
        array[a] = 999999;
    }
    array[1] = 0;
    sort(edge.begin(), edge.end());
    for(int a = 0; a < edge.size(); ++a)
        sort(edge[a].begin(), edge[a].end());
    
    for(vector<int> a : edge){
        map[a[0]].push_back(a[1]);
        map[a[1]].push_back(a[0]);
   }
    dfs(map,1, 0, array);
    sort(array+1,array+n+1);
    int max = array[n];
    
    
    for(int a = n; a > 0; --a){
        if(max == array[a])
            answer++;
        else
            break;
    }
    
    return answer;
}
