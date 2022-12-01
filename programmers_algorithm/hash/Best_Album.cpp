#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <map>
bool compare(std::pair<int, int> a, std::pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second > b.second;
	}
}
bool compare2(std::pair<std::string, int> a, std::pair<std::string, int> b) {
		return a.second > b.second;
}
using namespace std;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> ge_pl;
    map<string, int> mp;
    int sz = 0;
    int count = 0;
    for(int a = 0; a < genres.size(); a++){
        ge_pl[genres[a]].push_back(make_pair(a, plays[a]));
        mp[genres[a]] = mp[genres[a]] + plays[a];
    }
    
    for(auto &pair : ge_pl)
        sort(pair.second.begin(), pair.second.end(), compare);
    
    sz = mp.size();
    vector<pair<string,int>> pr(sz);
    
    for(auto pa : mp){
        pr[--sz] = {pa.first, pa.second};
    }
    sort(pr.begin(), pr.end(), compare2);
    for(auto pa : pr){
        count = 2;
        for(auto a : ge_pl[pa.first]){
            if(count==0)
                break;
            else{
                answer.push_back(int(a.first));
                --count;
            }
        }
    }
    return answer;
}
