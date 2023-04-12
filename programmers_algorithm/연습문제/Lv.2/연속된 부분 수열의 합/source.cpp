#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int left = 0;
    int right = 0;
    int mini = 21e8;
    int nowNum = sequence[0];
    int startIDX = 0;
    int endIDX = 0;
    while(left <= right && right < sequence.size()){
        if(nowNum > k){
            if(left < right){
                nowNum -= sequence[left++];
            }
            else{
                if(right == sequence.size())
                    break;
                nowNum += sequence[++right];
            }
        }
        else{
            if(nowNum == k){
                if(mini > right - left+1){
                    mini = right - left+1;
                    startIDX = left;
                    endIDX = right;
                }
            }
            nowNum += sequence[++right];
            if(right == sequence.size())
                break;
        }
    }
    answer.push_back(startIDX);
    answer.push_back(endIDX);
    return answer;
}
