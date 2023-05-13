#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int gcdd(int a , int b)
{
    int A = max(a, b);
    int B = min(a, b);
    
    while(A % B != 0)
    {
        int R = A % B;
        A = B;
        B = R;
    }
    return B;
}
 
// 최소공배수 = 두 수의 곱 / 최대공약수
int solution(vector<int> arr) 
{
    int answer = arr[0];
    for(int a = 1; a < arr.size(); ++a)
    {
        int gcd = gcdd(answer, arr[a]);
        int lcm = answer * arr[a] / gcd;
        answer =lcm;
    }
    return answer;
}
