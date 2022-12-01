#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int as = -1;

int compare(string a, string b, int size){
    int check = 0;
    for(int q = 0; q < size; ++q){
        if(a.at(q)== b.at(q))
            ++check;}
    return check;
}
void dfs(string begin, string target, vector<string> wd, int size){
    if(begin == target){
        int sz;
        if(wd.empty())
            sz = 0;
        else
            sz = wd.size();
        
        if(as < sz){
            as = sz;
            }
    }
    vector<string> temp;
    for(int a = 0;  a < wd.size(); ++a){
        if(compare(begin, wd[a], size) == size-1){
            temp.assign(wd.begin(), wd.end());
            temp.erase(find(temp.begin(), temp.end(), wd[a]));
            dfs(wd[a], target, temp, size);
            temp.clear();
        }
    }
            
               
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int size = begin.length();
    vector<string> temp;
    
    for(int a = 0; a < words.size(); ++a){
        if(compare(begin, words[a], size)==size-1){
            dfs(begin, target, words, size);
        }
            
    }
    if(as == -1)
        return 0;
    else
        return words.size() - as;
}
