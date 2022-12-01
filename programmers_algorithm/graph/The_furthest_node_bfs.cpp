#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> map;
void bfs(queue<int> que, int deep, vector<int>& array, bool check[]){
    ++deep;
    int size = que.size();
    for(int a = 0; a < size; ++a){
        int parent = que.front();
        que.pop();
        for(int b = 0; b < map[parent].size(); ++b){
            if(check[map[parent][b]] == true){
                if(array[map[parent][b]] > deep){
                    check[map[parent][b]] = false;
                    array[map[parent][b]] = deep;
                    que.push(map[parent][b]);
            }
                
        }
    }
        if(que.empty())
            return;
    }
    if(!que.empty())
        bfs(que, deep, array,check);
}
    
int solution(int n, vector<vector<int>> edge) {
    bool check[n+1];
    int answer = 0;
    vector<int> array;
    vector<int>temp;
    for(int a = 0; a <= n; ++a){
        map.push_back(temp);
        array.push_back(999999);
        check[a] = true;
    }
    check[1] = false;
    array[1] = 0;
    sort(edge.begin(), edge.end());
    
    for(vector<int> a : edge){
        map[a[0]].push_back(a[1]);
        map[a[1]].push_back(a[0]);
   }
    queue<int> que;
    que.push(1);
    bfs(que,  0, array, check);;
    
    sort(array.begin(),array.end());
    
    int max = array[n-1];
    
    
    for(int a = n-1; a > 0; --a){
        if(max == array[a])
            answer++;
        else
            break;
    }
    
    return answer;
}
