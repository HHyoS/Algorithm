#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int size = A.size();
    int point = 0;
    int idx = 0;
    for(int a = 0; a < size; ++a){
        if(idx >= size)
            break;
        if(A[a] < B[idx]){
            ++idx;
            ++answer;
        }
        else{
            ++idx;
            while(idx < size){
                if(A[a] >= B[idx]){
                    ++idx;
                }
                else{
                    ++answer;
                    ++idx;
                    break;
                }
            }
        }
    }
    return answer;
}
