#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
struct str{
    int line;
    int current_idx;
    int start_idx;
    str(int line,int current_idx,int start_idx):line(line),current_idx(current_idx),start_idx(start_idx){};
};
 
int main(){
    
    int N,K;
    cin>>N>>K;
    
    char c;
    vector<vector<int>> vec(2,vector<int>(N+1,0));
    vector<vector<int>> visit(2,vector<int>(N+1,0));
    
    for(int i=0;i<2;i++){
        for(int j=1;j<=N;j++){
            cin>>c;
            vec[i][j]=(int)c-48;
        }
    }
    
    int ans=0;
    queue<str> q;
    q.push(str(0,1,1));
    
    while(!q.empty()){
        int line=q.front().line; 
        int current_idx=q.front().current_idx;  
        int start_idx=q.front().start_idx; 
        
        if(current_idx>N){
            ans=1;
            break;
        }
        
        //이미 확인했는지 체크
        if(visit[line][current_idx])
            continue;
        
        visit[line][current_idx]=1;
        
        if(current_idx+1>N || vec[line][current_idx+1]==1){
            q.push(str(line,current_idx+1,start_idx+1));
        }
        
        if(current_idx-1>=start_idx+1 && vec[line][current_idx-1]==1){
            q.push(str(line,current_idx-1,start_idx+1));
        }
        
        line=(line==0)? 1:0;
        if(current_idx+K>N || vec[line][current_idx+K]==1){
            q.push(str(line,current_idx+K,start_idx+1));
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
