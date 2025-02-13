#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/7490
    문제 설명 : 


      */

int T, N;
vector<char> temp;
void dfs(int nowNum,int result,int before_num,char last_cal) {


    if (nowNum == N+1) {
        if (before_num != 0) {
            if (last_cal == '+') {
                result = result + before_num;
            }
            else {
                result = result - before_num;
            }
        }
        if (result == 0) {
            int num = 1;
            cout << num++;
            for (int a = 0; a < temp.size(); ++a) {
                cout << temp[a] << num++;
            }
            cout << "\n";
        }
        return;
    }


    if (last_cal == '+') {
        temp.push_back('+');
        dfs(nowNum + 1, result + before_num, nowNum, '+'); // 3 , 3 
        temp.pop_back();

        temp.push_back('-');
        dfs(nowNum + 1, result + before_num, nowNum, '-');
        temp.pop_back();
    }
    else {
        temp.push_back('+');
        dfs(nowNum + 1, result - before_num, nowNum, '+'); // 3 , 3 
        temp.pop_back();

        temp.push_back('-');
        dfs(nowNum + 1, result - before_num, nowNum, '-');
        temp.pop_back();
    }

    temp.push_back(' ');
    dfs(nowNum + 1, result, before_num*10+nowNum,last_cal);
    temp.pop_back();

}
void Solve() {

    dfs(2, 0, 1,'+');

}
void Input() {
    cin >> T;
    for (int a = 0; a < T; ++a) {
        cin >> N;
        Solve();
        cout << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    return 0;
}
