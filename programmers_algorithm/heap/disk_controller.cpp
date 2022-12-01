#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int solution(vector<vector<int>> jobs) {
    int size = jobs.size();
    int aver = 0;
    int cur = 0;
    sort(jobs.begin(), jobs.end());
    int time = jobs[0][0];
    for(auto j : jobs){
        aver += j[1];
    }
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> a;
    while(true){
        if(cur < jobs.size() && jobs[cur][0]<=time){
            a.push(make_pair(jobs[cur][1], jobs[cur][0]));
            ++cur;
            continue;}
        
        if(!a.empty() && time >= a.top().second){
                aver = aver + time - a.top().second;
                time += a.top().first;
                a.pop();
                if(a.empty() && cur < jobs.size() && jobs[cur][0] > time)
                    time = jobs[cur][0];
        }
        if(cur == jobs.size() && a.empty())
            break;
        
    }
    int answer = aver / size;
    return answer;
}
