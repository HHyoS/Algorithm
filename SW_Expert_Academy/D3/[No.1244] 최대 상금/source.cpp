#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

 
int N;
string number;
int q;
int cnt = 21e8;
int maxi[11];
string target;
void dfs(string now,int count) {

    if (count >= cnt)
        return;
    if (now == target) {
        cnt = count;
        return;
    }

    if (count >= q)
        return;
    for (int a = 0; a < now.length()-1; ++a) {
        char first = now[a];
        for (int b = a+1; b < now.length(); ++b) {
            char second = now[b];
            if (first > second) continue;
            string temp = now;
            temp[b] = first;
            temp[a] = second;
            int nowNum = stoi(temp);
            if (maxi[count + 1] < nowNum)
                maxi[count + 1] = nowNum;
            dfs(temp, count+1);
        }
    }
}

void solve(string num, int Q, int caseNum) {
    sort(num.begin(), num.end(), greater<char>());
    target = num;
    dfs(number, 0);
    if (Q < cnt) {
        cout <<"#"<<caseNum<<" "<<maxi[Q]<<"\n";
    }
    else {
        Q -= cnt;
        if (Q % 2 == 1) {
            int lastAns = -1;
            for (int a = 0; a < target.length() - 1; ++a) {
                char first = target[a];
                for (int b = a + 1; b < target.length(); ++b) {
                    char second = target[b];
                    string temp = target;
                    temp[b] = first;
                    temp[a] = second;
                    int nowNum = stoi(temp);
                    lastAns = max(lastAns, nowNum);
                }
            }
            cout << "#" << caseNum << " " << lastAns << "\n";
        }
        else
            cout << "#" << caseNum << " " << target << "\n";
    }
}
void input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        cin >> number >> q;
        solve(number, q,a+1);
        memset(maxi, 0, sizeof(maxi));
        cnt = 21e8;
    }

 }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    return 0;
}
