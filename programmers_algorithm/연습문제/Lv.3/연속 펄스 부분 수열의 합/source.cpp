#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;

int seq1[500001];
int seq2[500001];
long long seqSum1[500001];
long long seqSum2[500001];
long long solution(vector<int> sequence) {
    memset(seqSum1,0,sizeof(seqSum1));
    memset(seqSum2,0,sizeof(seqSum2));
    int one = 1;
    int two = -1;
    for(int a = 0; a < sequence.size(); ++a){
        seq1[a+1] = sequence[a]*one;
        seq2[a+1] = sequence[a]*two;
        one *= -1;
        two *= -1;
    }
    int maxiIdx1 = -1;
    int maxiIdx2 = -1;
    long long maxi1 = -50000000001;
    long long maxi2 = -50000000001;
    for(int a = 1; a <= sequence.size(); ++a){
        seqSum1[a] = seqSum1[a-1] + seq1[a];
        seqSum2[a] = seqSum2[a-1] + seq2[a];
        if(seqSum1[a] > maxi1){
            maxi1 = seqSum1[a];
            maxiIdx1 = a;
        }
        if(seqSum2[a] > maxi2){
            maxi2 = seqSum2[a];
            maxiIdx2 = a;
        }
    }
    long long mini1 = 50000000001;
    long long mini2 = 50000000001;
    int miniIdx1 = -1;
    int miniIdx2 = -1;
    for(int a = 1; a < maxiIdx1; ++a){
        if(seqSum1[a] < mini1){
            mini1 = seqSum1[a];
            miniIdx1= a;
        }
    }
    for(int a = 1; a< maxiIdx2; ++a){
        if(seqSum2[a] < mini2){
            mini2 = seqSum2[a];
            miniIdx2 = a;
        }
    }
    
    long long answer1 = maxi1;
    long long answer2 =  maxi2;
    if(mini1 < 0){
        answer1 = maxi1-mini1;
    }
    if(mini2 < 0){
        answer2 = maxi2 - mini2;
    }
        
    return max(answer1,answer2);
}
