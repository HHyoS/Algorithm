#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int max = brown + yellow;
    int col = 0;
    for(int row = 3; row < max/2; ++row){
        col = max / row;
        if(max % row ==0){
            if((row-2)*(col-2)==yellow){
                answer.push_back(col);
                answer.push_back(row);
            break;}
        }
    }
    return answer;
}
