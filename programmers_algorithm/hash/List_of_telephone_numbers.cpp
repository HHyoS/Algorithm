#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    if(a.size()==b.size())
        return a<b;
    else
        return a.size()<b.size();
    }
bool solution(vector<string> phone_book) {
    bool answer = true;
    vector<string> pob = phone_book;
    sort(pob.begin(), pob.end(), compare);
    int a = phone_book.size()-1;
    for(int b = 0; b < a; ++b){
        for(int c = b+1; c < a+1; ++c){
            if(pob[b].length() == pob[c].length())
                if(pob[b] == pob[c])
                    return false;
                else{
                    continue;}
            else
                if(pob[b] == pob[c].substr(0,pob[b].length()))
                    return false;
                else{
                    continue; }
        }
    }
    return answer;
}
