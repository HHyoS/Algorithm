#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> cit;
    int check = 0;
    cit.assign(citations.begin(), citations.end());
    sort(cit.begin(), cit.end(), greater<int>());
    while (check < cit.size()){
        if(cit[check] <= check )
            break;
        check++;
    }
    return check;
}
