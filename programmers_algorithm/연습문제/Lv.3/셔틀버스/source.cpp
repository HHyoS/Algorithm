#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Node{
    int hour;
    int min;
};

bool operator<(Node a, Node b){
    if(a.hour == b.hour){
        return a.min > b.min;
    }
    
    return a.hour > b.hour;
}

string getAnswer(int hour,int min){
    
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<Node> que;
    int jump = t*(n-1);
    int endH = 9 + jump/60;
    int endM = jump%60;
    cout << endH << " " << endM << "\n";
    for(int a = 0; a < timetable.size(); ++a){
        int hour = stoi(timetable[a].substr(0,2));
        int min = stoi(timetable[a].substr(3,2));
        if(hour > endH) continue;
        if(hour == endH && endM < min) continue;
        que.push({hour,min});
    }
    int nowH = 9;
    int nowM = 0;
    int lastH = 0;
    int lastM = 0;
    for(int a = 0; a < n; ++a){
        
        for(int b= 0; b < m; ++b){
            if(que.empty()){
                lastH = nowH;
                lastM = nowM;
                break;
            }
            if(que.top().hour > nowH) break;
            if(que.top().hour == nowH && que.top().min >nowM) break;
            lastH = que.top().hour;
            lastM = que.top().min-1;
            if(lastM == -1){
               --lastH;
                lastM = 59;
            }
            que.pop();
        }
        nowM += t;
        if(nowM >= 60){
            ++nowH;
            nowM = nowM%60;
        }
    }
    string hour = to_string(lastH);
    string min = to_string(lastM);
    if(lastH < 10)
        hour = "0"+hour;
    if(lastM < 10)
        min = "0"+min;
    return answer = hour+":"+min;
}
