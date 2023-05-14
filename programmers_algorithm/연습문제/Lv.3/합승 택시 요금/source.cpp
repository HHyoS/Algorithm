#include <string>
#include <vector>
#include <memory.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int total[201][201];
int solution(int n, int s, int A, int B, vector<vector<int>> fares) {
    for(int a = 0; a<=n; ++a){
        for(int b =0; b <=n; ++b){
            if(a==b)
                total[a][b] =0;
            else{
                total[a][b] = 21e8;
            }
        }
    }
    for(int a = 0; a <fares.size(); ++a){
        total[fares[a][0]][fares[a][1]] = fares[a][2];
        total[fares[a][1]][fares[a][0]] = fares[a][2];
    }
    for(int a=1; a<= n; ++a){
        for(int b=1; b<=n; ++b){
            for(int c=1; c<=n; ++c){
                if(total[b][a] == 21e8 || total[a][c] == 21e8) continue;
                int sum = total[b][a] + total[a][c];
                if(total[b][c] > sum){
                    total[b][c] = sum;
                }
            }
        }
    }
    int answer = total[s][A] + total[s][B];
    for(int a = 1; a<=n; ++a){
        int temp = total[s][a] + total[a][A] + total[a][B];
        if(answer > temp)
            answer = temp;
    }
    
    return answer;
}
