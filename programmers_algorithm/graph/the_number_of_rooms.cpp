#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

pair<int,int> po(int x, int y, int command){
    pair<int,int> xy;
    switch(command){
        case 0 :
            xy = make_pair(x,y+1);
            break;
        case 1 :
            xy = make_pair(x+1,y+1);
            break;
        case 2 :
            xy = make_pair(x+1,y);
            break;
        case 3 :
            xy = make_pair(x+1,y-1);
            break;
        case 4 :
            xy = make_pair(x,y-1);
            break;
        case 5 :
            xy = make_pair(x-1,y-1);
            break;
        case 6 :
            xy = make_pair(x-1,y);
            break;
        case 7 :
            xy = make_pair(x-1,y+1);
            break;
        default :
            break;
    }
    return xy;
}

int solution(vector<int> arrows) {
    int answer = 0;
    map<pair<int,int>, bool> point;
    map<pair<pair<int,int>,pair<int,int>>, bool> edge;
    pair<int,int> t;
    int x =0,y=0;
    point[{x,y}] = true;
    for(int a : arrows){
        for(int b = 0; b < 2; ++b){
            t = po(x,y,a);
            if(point[t] == true){
                if(edge[{{x,y},t}] == false || edge[{t,{x,y}}] == false){
                    ++answer;
                }
            }
            
            edge[{{x,y},t}] = true,edge[{t,{x,y}}] = true;
            point[t] = true;
            x = t.first;
            y = t.second;
        }
    }
    return answer;
}
/* This is a problem that creates a room by moving points according to a given command, and returns the number of rooms after all actions have been completed.
When we first solved this problem, we tried to solve the problem by designing one point at a time of command, but if we were to create four squares and create
a room in an x-shaped shape, we would not include the number of rooms, which would cause incorrect results to be returned.
So when the dots were moving, they were able to perform one command twice to solve the problem of not being able to turn back the number of rooms caused by x. */
