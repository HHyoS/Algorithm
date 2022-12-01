#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> test;
    for(auto vt : commands){
        test.assign(array.begin() + vt[0] -1, array.begin() + vt[1]);
        sort(test.begin(), test.end());
        answer.push_back(test[vt[2]-1]);
    }
    return answer;
}
