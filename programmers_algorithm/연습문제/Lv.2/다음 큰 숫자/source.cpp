#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int ans = 0;
    
    int temp = 1;
    int cnt = 0;
    while(temp <= n){
        int ando = n&temp;
        if(ando)
            ++cnt;
        temp <<=1;
    }
    temp = 1;
    while(1){
        int ando = temp&n;
        if(ando ==0){
            temp<<=1;
        }
        else{
            n += temp;
            temp <<= 1;
            while(temp <= n){
                int aando = temp&n;
                if(aando){
                    --cnt;
                }
                temp <<=1;
            }
            break;
        }
    }
    int need = 1;
    for(int a = 0; a < cnt; ++a){
        n += need;
        need <<=1;
    }
    return ans = n;
}
