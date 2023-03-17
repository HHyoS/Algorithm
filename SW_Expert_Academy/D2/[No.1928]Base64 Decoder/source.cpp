#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

 
int T;
int gop[8] = {128,64,32,16,8,4,2,1 };
bool ans[24];
string target;
string answer = "";
void input() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> target;
        int idx = 0;
        for (int a = 0; a < target.length(); ++a) {
            if (a > 0 && a%4==0) {
                for (int c = 0; c < 3; ++c) {
                    int value = 0;
                    int jump = c * 8;
                    for (int b = 0; b < 8; ++b) {
                        if (ans[jump+b] == 1) {
                            value += gop[b];
                        }
                        ans[jump + b] = 0;
                    }
                    answer = answer + char(value);
                }
                idx = 0;
            }
            int num = 0;
            if (target[a] >= 'A' && target[a] <= 'Z')
                num = target[a] - 65;
            else if (target[a] >= 'a' && target[a] <= 'z')
                num = target[a] - 71;
            else if (target[a] >= '0' && target[a] <= '9')
                num = target[a] + 4;
            else if (target[a] == '+')
                num = target[a] + 19;
            else if (target[a] == '/')
                num = target[a] + 16;

            for (int b = 2; b < 8; ++b) {
                int q = num / gop[b];
                num = num % gop[b];
                ans[idx++] = q;
            }
        }
        for (int c = 0; c < 3; ++c) {
            int value = 0;
            int jump = c * 8;
            for (int b = 0; b < 8; ++b) {
                if (ans[jump + b] == 1) {
                    value += gop[b];
                }
                ans[jump + b] = 0;
            }
            answer = answer + char(value);
        }
        cout << "#"<<t<<" "<<answer << "\n";
        answer = "";

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
