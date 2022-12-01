#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("Input.txt", "r", stdin);

    cin >> T;

    for (int t = 1; t <= T; ++t) {
        string tmp;
        cin >> tmp;
        int num = tmp[2]-'0';
        if (num >= 5) {
            num = tmp[1] - '0' + 1;
            if (num == 10) {
                tmp[1] = '0';
                num = tmp[0] - '0' + 1;
                if (num == 10) {
                    tmp[0] = '0';
                    tmp = "1" + tmp;
                }
                else {
                    tmp[0] = num + '0';
                }
            }
            else
                tmp[1] = num + '0';
        }
        cout << "#" << t << " " <<tmp[0] << "." << tmp[1] << "*10^" << tmp.length() - 1 << "\n";
    }


    return 0;
}
