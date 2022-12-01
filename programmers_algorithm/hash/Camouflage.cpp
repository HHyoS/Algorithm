#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> mp;
    for(int a = 0; a < clothes.size();a++)
            ++mp[clothes[a][1]];
    for(auto pair : mp)
        answer = answer * (pair.second +1);
    return answer-1;
}
