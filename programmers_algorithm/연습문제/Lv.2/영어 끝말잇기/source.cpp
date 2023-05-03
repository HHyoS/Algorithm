#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int turn = 1, count = 1;
    vector<string> check;
    
    answer.push_back(0);
    answer.push_back(0);
    check.push_back(words[0]);
    
    for(int i = 1; i < words.size(); i++)
    {
        turn++;
        
        if(words[i].front() == words[i - 1].back())
        {
            if(find(check.begin(), check.end(), words[i]) == check.end())
            {
                if(i == words.size() - 1)
                    return answer;
                check.push_back(words[i]);
            }
            else
                break;
        }
        else
            break;
        
        if(turn == n)
        {
            count++;
            turn = 0;
        }
    }
    
    answer[0] = turn;
    answer[1] = count;
    return answer;
}
