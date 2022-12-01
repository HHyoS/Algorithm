#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int T;
string chase[8];
bool row[8];
bool col[8];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("Input.txt", "r", stdin);
    cin >> T;
    for (register unsigned int t = 1; t <= T; ++t) {
        for(register unsigned int a = 0; a < 2; ++a){
            row[a*4+0] = 0;
            row[a*4+1] = 0;
            row[a*4+2] = 0;
            row[a*4+3] = 0;
            col[a*4+0] = 0;
            col[a*4+1] = 0;
            col[a*4+2] = 0;
            col[a*4+3] = 0;
        }
             
        unsigned int cnt = 0;
        bool flag = 0;
        for (register unsigned int a = 0; a < 8; ++a) {
            cin >> chase[a];
        }
        
        
        for (register unsigned int a = 0; a < 8; ++a) {
            for (register unsigned int b = 0; b < 8; ++b) {
                if(flag){
                    break;
                }
                if (chase[a][b] == 'O') {
                    ++cnt;
                    if (row[a] == 1 || col[b] == 1)
                        flag =1;
                    else {
                        row[a] = 1;
                        col[b] =1;
                    }
                }
            }
        }
        if (flag || cnt != 8)
            cout << "#" << t << " no\n";
        else
            cout << "#" << t <<" yes\n";
    }
}
