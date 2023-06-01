#include <string>
#include <vector>
 
using namespace std;
 
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer;
    int Row = arr1.size();
    int Col = arr1[0].size();
    int Row2 = arr2.size();
    int Col2 = arr2[0].size();
    
    for(int a = 0 ; a < Row ; ++a)
    {
        vector<int> V;
        for(int b = 0 ; b < Col2 ; ++b)
        {
            int Sum = 0;
            for(int c = 0 ; c < Row2; ++c)
            {
                Sum += arr1[a][c] * arr2[c][b];
            }
            V.push_back(Sum);
        }
        answer.push_back(V);
    }
    return answer;
}
