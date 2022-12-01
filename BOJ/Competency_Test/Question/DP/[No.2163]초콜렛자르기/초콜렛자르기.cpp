#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("Input.txt", "r", stdin);
    cin >> N >> M;
    cout << N * M - 1;
    return 0;
}

