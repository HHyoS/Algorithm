#include <iostream>
#include <string>
using namespace std;

string input;
bool find(int index,int leng){
    int nanugi = leng/2;
    int end = index+leng-1;
    for(int a =0; a< nanugi; ++a){
        if(input[index+a] != input[end-a]){
            return 0;
        }
    }
    return 1;
}
int solution(string s)
{
    
    input = s;
    
    
    for(int a = s.length(); a >= 2; --a){
        int end = s.length()-a;
        for(int b = 0; b <= end; ++b){
            if(find(b,a)){
                return a;
            }
        }
    }

    return 1;
}
