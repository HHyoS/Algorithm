#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count(vector<int> ar){
    int check = 0;
    for(int b = 1; b < ar.size(); ++b)
            if(ar[b] == 1 || ar[b] == -1)
                  ++check;
    return check;
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> ar(n+1, vector<int>(n+1, 0));
    vector<int> temp;
    for(int a = 0; a < results.size(); ++a){
        ar[results[a][0]][results[a][1]] = 1;
        ar[results[a][1]][results[a][0]] = -1;
        }
    for(int a = 1; a < ar.size(); ++a){
        int check = count(ar[a]);
        if(check == n-1)
            temp.push_back(a);
        }
    for(int a = 1; a < ar.size(); ++a){
        for(int b = 1; b < ar[a].size(); ++b){
            if(ar[a][b] == 1){
                for(int c = 1; c < ar[b].size(); ++c){
                    if(ar[a][c] == -1)
                        ar[b][c] = -1;
                }
            }
            else if(ar[a][b] == -1){
                for(int c = 1; c< ar[b].size(); ++c){
                    if(ar[a][c] == 1)
                        ar[b][c] = 1;
                }
            }
        if((find(temp.begin(), temp.end(), b) == temp.end()) && count(ar[b]) == n-1)
            temp.push_back(b);
        }
    }
            
    return temp.size();
} 
/* This problem was to use the data given to complete the ranking table.

To solve this problem, we created a two-dimensional array of n x n and entered data '1', '-1', '0' for winning, losing, and uninformed. Using triple for statement, we entered the losing record of 'A' to 'B' if 'B' is lost to 'A'.
And to 'D' who won 'C', 'C' victory record was entered to 'D'.
As the foreword progressed, all records were added to the temp array, and the size of the temp array was returned to the answer after the foreword was terminated so that the code would work.
*/
