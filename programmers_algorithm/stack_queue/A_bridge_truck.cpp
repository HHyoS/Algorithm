#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int a = 0;
    queue<pair<int,int>> bridge;
    int max_w = 0;
    int time = 1; // The beginning of crossing the bridge begins at one second.
    
    while(true){        
        if(!bridge.empty() && bridge.front().second == time){
            max_w -= bridge.front().first;
            bridge.pop();
        } // When the time starts, the truck passing the bridge at that time is 
        //queued to subtract the weight of the car on the bridge.
        if(a == truck_weights.size() && bridge.empty()){
            break;}
        // If all the truck bridge to get through the atmosphere to the present time 
        //does not exist while the escape.
        
            if(a != truck_weights.size() && max_w + truck_weights[a] <= weight){
                    max_w += truck_weights[a];
                    bridge.push(make_pair(truck_weights[a], time+bridge_length));
                    ++a;}   
        ++time;
    }
    
    return time;
}
