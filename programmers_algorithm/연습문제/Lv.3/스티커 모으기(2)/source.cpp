#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
// 2차원 배열의 1번 인덱스는 사용한거, 0번 인덱스는 사용 안한거
int nonZeroDp[100001][2];
// nonZeroDp 는 0번 인덱스를 사용하지 않음, zeroDp는 0번인덱스를 사용(고로 마지막 인덱스는 사용 X)
int zeroDp[100001][2];
int solution(vector<int> sticker)
{
    memset(nonZeroDp,0,sizeof(nonZeroDp));
    memset(zeroDp,0,sizeof(zeroDp));
    int size = sticker.size();
    zeroDp[0][1] = sticker[0];
    for(int a = 1; a < size; ++a){
        zeroDp[a][0] = max(zeroDp[a-1][0],zeroDp[a-1][1]);
        zeroDp[a][1] = zeroDp[a-1][0]+sticker[a];
        
        nonZeroDp[a][0] = max(nonZeroDp[a-1][0],nonZeroDp[a-1][1]);
        nonZeroDp[a][1] = nonZeroDp[a-1][0]+sticker[a];
    }
    int end = size-1;
    int answer =max(zeroDp[end][0],max(nonZeroDp[end][0],nonZeroDp[end][1]));
    
    
    return answer = max(sticker[0],answer);
}
