#include <iostream>
using namespace std;


int solution(int n)
{
    int ans = 0;
    int temp = n;
    while(temp > 0){
        if(temp %2 == 0){
            temp /= 2;
        }
        else{
            temp -= 1;
            ans +=1;
        }
    }

    return ans;
}
