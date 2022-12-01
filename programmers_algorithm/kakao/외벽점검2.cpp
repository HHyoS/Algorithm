#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
int size;
void dfs(vector<int> weak, int start,int n, int dist, pair<int,int>& bigger, vector<int>& copy, bool check[]){
    int leng = weak[start] + dist;
    vector<int> a;
    a.push_back(start);
    int e = start+1;
    int last = start;
    int total;
    for(int f= 1; f< weak.size(); ++f){
        if(check[e%weak.size()] == true)
            break;
        if(leng >= n){
            if(e < weak.size()){
                a.push_back(e);
                last = e;
            }
            else if(e >= weak.size()){
                if(weak[e%weak.size()] < leng % n){
                    a.push_back(e%weak.size());
                    last = e;
                }
                else
                    break;
            }
        }
        else{
            if(e >= weak.size()){
                if(leng%n >= weak[e%weak.size()]){
                    a.push_back(e%weak.size());
                    last = e %weak.size();
                }
                else
                    break;
            }
            else if(e < weak.size()){
                if(leng >= weak[e]){
                a.push_back(e);
                last = e;
                }
                else
                    break;
            }
        }
    e++;
        }
    if(last >= weak.size())
        total = dist  - (n-weak[start] + weak[last%weak.size()]);
    else
        total = dist - (weak[last]-weak[start]);
    printf("dist = %d,leng = %d, start = %d, last = %d, total = %d\n",dist,leng,start,last,total);
    if(a.size() == bigger.first){
        if(bigger.second > total){
            bigger.second = total;
            copy.assign(a.begin(), a.end());
        }
    }
    else if(a.size() > bigger.first){
        copy.assign(a.begin(), a.end());
        bigger.first = a.size();
        bigger.second = total;
    }
    else
        return;
        
}
int solution(int n, vector<int> weak, vector<int> dist) {
    answer = dist.size()+1;
    bool check[weak.size()];
    pair<int,int> bigger;
    for(int a = 0; a < weak.size(); ++a)
        check[a] = false;
    sort(dist.begin(), dist.end(), greater<int>());
    int count = 0;
    vector<int> copy;
    for(int b = 0; b < dist.size(); ++b){
        for(int a = 0; a < weak.size(); ++a){
            if(check[a] == false){
                bigger = make_pair(0,dist[b]+weak[a]);
                dfs(weak, a,n, dist[b], bigger, copy, check);
                for(int a = 0; a < copy.size(); ++a)
                    printf("%d ",copy[a]);
                printf("\n");
                }
            }
        for(int a : copy){
            check[a] = true;
        }
        for(int a = 0; a < weak.size(); ++a){
            if(check[a] == false)
                break;
            else if(a == weak.size()-1)
                return b+1;
        }
    }
    return -1;
}
