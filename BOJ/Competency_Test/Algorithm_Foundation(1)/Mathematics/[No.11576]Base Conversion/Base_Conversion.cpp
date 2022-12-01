#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
 
int A, B;
int N;
 
int main(void)
{
//    freopen("input.txt", "r", stdin);
    
    cin >> A >> B;
    cin >> N;
    
    int digit[30];
    long long num10 = 0;
    vector<int> ans;
    
    for(int i = 0; i < N; i++)
    {
        cin >> digit[i];
    }
        
    // A진수 -> 10진수
    for(int i = N-1; i >= 0; i--)
    {
        int temp = digit[i];
        
        num10 += temp * pow(A, N-1-i);
    }
        
    // 10진수 -> B진수
    while(num10 != 0)
    {
        int temp = num10 % B;
        num10 /= B;
        
        // B진수의 뒤에서부터 저장 
        ans.push_back(temp);
    } 
    
    // 뒤에서부터 저장했으므로, 반대로 출력 
    for(int i = ans.size()-1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}
