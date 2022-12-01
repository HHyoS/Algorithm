#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    int maxx = distance;
    int minn = 1;
    int mid = 0;
    int answer = 0;
    int count = 0;
    while(minn <= maxx){
        count = 0;
        mid = (maxx + minn)/ 2;
        int last= -1;
        int dis = 0;
        for(int a = 0; a < rocks.size(); ++a){
            if(last == -1)
                dis = rocks[a];
            else
                dis = rocks[a] - rocks[last];
            if(dis < mid)
                ++count;
            else
                last = a;
        }
        if(count > n)
            maxx = mid -1;
        else{
            minn = mid +1;
            answer = max(answer, mid);
        }
    }
    return answer;
}
