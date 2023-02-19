#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

string ipv6;
string ans = "";
string temp[4] = { ":",":0",":00",":000" };
void input() {
    cin >> ipv6;
    int cnt = 4;
    ipv6 = ":" + ipv6;
    for (int a = ipv6.length()-1; a >= 0; --a) {
        if (ipv6[a] == ':') {
            if (cnt == 4) {
                ans = ":" + ans;
            }
            else {
                ans = temp[cnt] + ans;
                cnt = 4;
            }
        }
        else {
            ans = ipv6[a] + ans;
            --cnt;
        }
    }
    ans = ans.substr(1);
    if(ans.length() == 39)
        cout << ans;
    else {
        if (ans[0] == ':') {
            ans = "0000" + ans;
        }
        if (ans[ans.length() - 1] == ':') {
            ans = ans + "0000";
        }
        if (ans.length() == 40) {
            int idx = ans.find("::");
            cout << ans.substr(0, idx) + ans.substr(idx + 1);
        }
        else {
            int idx = ans.find("::", 0);
            idx += 1;
            int cnt = (39 - ans.length()) / 5;
            for (int a = 0; a < cnt; ++a) {
                ans = ans.substr(0, idx) + "0000:" + ans.substr(idx);
                idx += 5;
            }
            ans = ans.substr(0, idx) + "0000" + ans.substr(idx);
            cout << ans;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    return 0;
}
