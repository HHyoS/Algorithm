#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;


queue<int> que;

void find() {

    while (1) {
        for (int a = 1; a <= 5; ++a) {
            int temp = que.front()-a;
            que.pop();
            if(temp<= 0) {
                que.push(0);
                return;
            }
            que.push(temp);
        }
    }
}
void input() {
    for (int t = 1; t <= 10; ++t) {
        int q;
        cin >> q;
        cout << "#" << q << " ";
        for (int a = 0; a < 8; ++a) {
            int temp;
            cin >> temp;
            que.push(temp);
        }
        find();
        while (!que.empty()) {
            cout << que.front()<< " ";
            que.pop();
        }
        cout << "\n";

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  //  freopen("input.txt", "r", stdin);

    input();
    return 0;
}
