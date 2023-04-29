#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int size = A.size()-1;
    for(int a = 0; a <= size; ++a){
        answer = answer + A[a]*B[size-a];
    }
    

    return answer;
}
