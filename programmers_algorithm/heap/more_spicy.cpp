#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
    
int solution(vector<int> scoville, int K) {
    priority_queue< int, vector<int>, greater<int>> a(scoville.begin(), scoville.end());
    int first;
    int second;
    int mix = 0;
    while(a.top() <= K && a.size() >1){
        first = a.top();  a.pop();
        mix = first + (a.top()*2); a.pop();
        a.push(mix);
    }
    if(a.top() < K)
        return -1;
    else
        return scoville.size()-a.size();
}
