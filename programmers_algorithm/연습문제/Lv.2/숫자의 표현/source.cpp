#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int total = 0;
    int left = 1;
    int right = 1;
    while(left <=right){
        if(total < n){
            if(right > n)
                break;
            total += right;
            ++right;
        }
        else{
            if(total == n)
                ++answer;
            total -= left;
            ++left;
        }
    }
    return answer;
}
