#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int mov[2];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    int answer = 0;
    cin >> mov[0] >> mov[1];
    mov[0] -= 1;
    while (1) {
        if (mov[1] != 0) {
            ++answer;
            mov[1] -= 1;
        }
        else
            break;

        if (mov[0] != 0) {
            ++answer;
            mov[0] -= 1;
        }
        else
            break;
    } 
    cout << answer-1;
    return 0;
}
