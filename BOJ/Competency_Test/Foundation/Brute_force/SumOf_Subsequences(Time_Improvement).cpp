#include <iostream>
#include <algorithm>
using namespace std;
 
int n, s;
int* arr;
int answer = 0;
 
void dfs(int id, int count, int sum){
    if(id == n){
        if(count != 0 && sum == s)
            ++answer;
        return;
    }
    
    if(id < n){
        if(arr[id] > 0 && sum > s)
            return;
        else{
            dfs(id + 1, count+1, sum + arr[id]);
            dfs(id + 1, count, sum);
        }
    }
    
    return;
}
 
int main() {
    cin >> n >> s;
    arr = (int*)malloc(sizeof(int)*n);
    for(int a = 0; a < n; a++){
        cin >> arr[a];        
    }
    sort(arr, arr+n);
    dfs(0, 0, 0);
    printf("%d",answer);
    return 0;
}
