#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;
int N;
int visited[20001] = {0};
pair<int, char> arr[20001];

void BFS(){
    memset(visited, 0, sizeof(visited));
    queue<int> que;
    que.push(1);       
    
    //가장 첫 루트 노드
    arr[1].first = -1;   
    arr[1].second = '1'; 

    visited[1] = 1;
    
    
    while(!que.empty()){
        
        int cur = que.front();
        que.pop();
        
        
       
        int node[2];
        node[0] = (cur*10 + 0) % N;
        node[1] = (cur*10 + 1) % N;
        
        for(int i = 0; i<2; i++){
            if(visited[node[i]]==1) continue;
            
            arr[node[i]].first = cur;   
            arr[node[i]].second = i + '0';   
            
            if(node[i]==0) return;      
            
            visited[node[i]] = 1;      
            que.push(node[i]);
            
            
        }
        
        
    }
    
}

void printReverse(int parent){
    if(parent==-1) return;      
    
    printReverse(arr[parent].first);
    cout << arr[parent].second;
    
}


int main(){
    
    
    int T; cin >> T;
    
    for(int test_case = 1; test_case<=T; test_case++){
        
         cin >> N;
        if(N==1) {
            cout << 1 << endl;     
            continue;
        }
        
        BFS();
        printReverse(0);           
        cout << endl;
        
        
    }
    
    return 0;
}
