#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
vector<int> weak;
vector<int> dist;
int size;
void dfs(vector<int> w, vector<int> d, int start, int man, int n, int count){
    if(count >= answer)
        return;
    if(dist[man] >= n){
        answer = 1;
        return;
        }
    int leng = weak[start] + dist[man];
    w[start] = 1;
    d[man] = 1;

    count++;
    int e = start+1;
    for(int a= 0; a< weak.size(); ++a){
        if(w[e%size] == 1)
            break;
        if(leng >= n){
            if(e < size)
                w[e] = 1;
            else{
                if(weak[e%size] <= leng%n)
                    w[e%size] = 1;
                else
                    break;
            }
        }
        else{
            if(e >= size)
                break;
            else{
                if(weak[e] >= weak[start] && leng >= weak[e])
                    w[e] = 1;
                else
                    break;
            }
        }
        ++e;
    }
    
    for(int a = 0; a < size; ++a){
        if(w[a] == 0)
            break;
        else if(a == size-1){
            if(answer > count){
                answer = count;
                return;
            }
            else
                return;
        }
    }
    for(int a = 0; a < size; ++a){
        if(w[a] == 0){
            for(int b=  0; b < dist.size(); ++b){
                if(d[b] == 0 && count+1 < answer){
                    dfs(w,d, a, b, n, count);
                }
            }
        }
    }
}
int solution(int n, vector<int> wk, vector<int> dt) {
    weak.assign(wk.begin(),wk.end());
    dist.assign(dt.begin(), dt.end());
    answer = dist.size()+1;
    sort(dist.begin(), dist.end(), greater<int>());
    vector<int> check_w(weak.size(),0);
    vector<int> check_d(dist.size(),0);
    size = weak.size();
    int count = 0;
    for(int a = 0; a < weak.size(); ++a){
        for(int b = 0; b < dist.size(); ++b){
            dfs(check_w,check_d, a, b,n,count);
        }
    }
    if(answer == dist.size()+1)
        return -1;
    return answer; 
}
