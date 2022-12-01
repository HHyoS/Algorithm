#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int a =0;
    int b = 0;
    
    for(b = people.size()-1; b > a; --b){
        if(people[a]+people[b] <= limit){
                ++a;
                ++answer;
            }
        else
            ++answer;
        }
    
	if (a == b)
		answer++;
    return answer;
}
