#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int check;
    for(int a = 0; a < prices.size(); ++a){
        check = 0;
        for(int b = a+1; b < prices.size(); ++b){
            ++check;
            if(prices[a] <= prices[b])
                continue;
            else
                break;
        }
        
        answer.push_back(check);
    }
    return answer;
}
 
