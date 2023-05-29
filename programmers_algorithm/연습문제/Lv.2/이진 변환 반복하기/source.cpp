#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    int count = 0;  
    int sum = 0;    
    
    while(s != "1"){
        int tempCount = 0;
      
        for(int i = 0; i < s.length(); i++)
            if (s[i] == '1')
                tempCount++;
        
        sum += s.length() - tempCount;
        
        s = "";
        while(tempCount > 0){
            if (tempCount % 2 == 0) s += "0";
            else s += "1";
            tempCount /= 2;
        }
        
        count++;

    }
    
    answer[0] = count;
    answer[1] = sum;
    return answer;
}
