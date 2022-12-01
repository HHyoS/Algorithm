#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int mx = 0;
    char max ='0';
    int x = 0;
    int leng = number.length() - k;
    while(leng!=0){
        for(int a = mx; a < number.length()-leng+1; ++a){
            if(max < number.at(a)){
                max = number.at(a);
                x = a;
            }
        }
        answer = answer+max;
        mx = x+1;
        max = '0';
        --leng;
        --k;
    }
    return answer;
} 
// The behavior of the above code is achieved by pulling the largest number from the front of a given number and creating the required number of digits.
So, as you go through the action, the required length except the maximum value is not navigated, but you extract the maximum value one by one to complete the aneur.
