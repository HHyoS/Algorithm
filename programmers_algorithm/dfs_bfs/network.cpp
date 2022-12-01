#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool tset[201];
void dfs(int start, vector<vector<int>> computers, int size){
    tset[start] = true;
    for(int a = 0; a < size; ++a){
        if(!tset[a] && computers[start][a] ==1){
            dfs(a, computers, size);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int a =0; a < n; ++a){
        if(!tset[a]){
            dfs(a, computers, n);
            ++answer;
    }
    }
    return answer;
}
