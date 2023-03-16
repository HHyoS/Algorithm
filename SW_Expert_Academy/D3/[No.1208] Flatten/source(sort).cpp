#define _CRT_SECURE_NO_WARNINGS
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
 
using namespace std;
 
  
int N;
vector<int>info;
//void solve(string num, int Q, int caseNum) {
//}
void input() {
    for (int t = 1; t <= 10; ++t) {
        int D;
        cin >> D;
        for (int a = 0; a < 100; ++a) {
            int temp;
            cin >> temp;
            info.push_back(temp);
        }
        sort(info.begin(), info.end());
        for (int a = 0; a < D; ++a) {
            info[0] += 1;
            info[99] -= 1;
            sort(info.begin(), info.end());
        }
        cout << "#" << t << " " << abs(info[0] - info[99]) << "\n";
        info.clear();
    }
 }
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   // freopen("input.txt", "r", stdin);
 
    input();
    return 0;
}
