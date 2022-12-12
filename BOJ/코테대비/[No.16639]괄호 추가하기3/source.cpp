#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;


string susic;
int N;

void getCal(stack<char>& giho, stack<long long>& sootja, int flag) {

    long long num = sootja.top();
    sootja.pop();
    while (!giho.empty() && giho.top() != '(') {
        if (giho.top() == '+') {
            num = sootja.top() + num;
        }
        else if (giho.top() == '-') {
            num = sootja.top() - num;

        }
        else {
            num = sootja.top() * num;
        }
        giho.pop();
        sootja.pop();
    }
    if (flag) {
        giho.pop();
    }
        
    sootja.push(num);
}
long long getAnswer(string nowSusic,int start, int end) {
    stack<char> giho;
    stack<long long> sootja;
    cout << nowSusic << "\n";
    for (int a = 0; a < nowSusic.size(); ++a) {
        cout << "[" << a << "]\n";
        if (nowSusic[a] >= '0' && nowSusic[a] <= '9') {
            sootja.push(nowSusic[a]-'0');
        }
        else if (nowSusic[a] == '(') {
            giho.push(nowSusic[a]);
        }
        else if (nowSusic[a] == ')') {
            getCal(giho, sootja, 1);
        }
        else {
            if (nowSusic[a] == '+' || nowSusic[a] == '-') {
                if (giho.empty() || giho.top() == '+' || giho.top() == '-' || giho.top() == '(') {
                    giho.push(nowSusic[a]);
                }
                else {
                    getCal(giho, sootja, 0);
                    giho.push(nowSusic[a]);
                }
            }
            else {
                giho.push(nowSusic[a]);
            }
        }
    }
    if (!giho.empty()) {
        getCal(giho, sootja, 0);
    }
    long long ans = sootja.top();
    sootja.pop();
    cout << sootja.size() << " ans ->" <<ans << "\n";
    return ans;
}

string getSusic(int start, int end) {
    string newSusic = susic.substr(0, start) + "(" + susic.substr(start,end-start)+")"+susic.substr(end);
    return newSusic;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);

    long long ans = -pow(2, 31);
    cin >> N >> susic;
    for (int a = 0; a < N; a+=2) {
        for (int b = a + 3; b <= N; b += 2) {
            string temp = getSusic(a, b);
            ans = max(ans, getAnswer(temp,a, b));
        }
    }
    cout << ans;
    return 0;

}
