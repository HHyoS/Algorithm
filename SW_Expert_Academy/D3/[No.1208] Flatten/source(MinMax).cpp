#define _CRT_SECURE_NO_WARNINGS
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
 
using namespace std;
 
  
int N;
priority_queue<int> que;
vector<int>info;
//void solve(string num, int Q, int caseNum) {
//}
 
int minIdx;
int maxIdx;
 
void FindMinMax() {
    for (int a = 0; a < 100; ++a) {
        if (info[minIdx] > info[a])
            minIdx = a;
        if (info[maxIdx] < info[a])
            maxIdx = a;
    }
}
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
        minIdx = 0;
        maxIdx = 99;
        for (int a = 0; a < D; ++a) {
            info[minIdx]++;
            info[maxIdx]--;
            FindMinMax();
        }
        cout << "#" << t << " " << info[maxIdx]- info[minIdx] << "\n";
        info.clear();
    }
 }
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt", "r", stdin);
 
    input();
    return 0;
}
