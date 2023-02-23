#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

string target;
string num;
int solve() {
    if (target == num)
        return 0;
    string temp = target;
    int cnt = 1;
    while (1) {
        if (temp.length() < num.length()) {
                return -1;
        }
        else{ 
            int lastNum = temp[temp.length() - 1]-'0';
            if (lastNum == 1) {
                temp = temp.substr(0, temp.length() - 1);
                ++cnt;
            }
            else if (lastNum % 2 == 1 && lastNum > 1) {
                return -1;
            }
            else {
                ++cnt;
                temp = to_string(stoi(temp) / 2);
            }
        }
        if (temp == num)
            return cnt;
        cout << temp << "\n";

    }
}
void input() {
    cin >> num >> target;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    clock_t start, finish;
    double duration;
    freopen("input.txt", "r", stdin);
    start = clock();
    input();
    cout << solve()<<"\n";
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
    return 0;
}
