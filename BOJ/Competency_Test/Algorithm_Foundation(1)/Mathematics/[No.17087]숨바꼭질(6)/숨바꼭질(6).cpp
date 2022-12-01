#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int N, S;
int brother[100000];
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("Input.txt", "r", stdin);
    cin >> N >> S;
    for (int a = 0; a < N; ++a) {
        cin >> brother[a];
        brother[a] = abs(brother[a] - S);
    }
    int answer = 0;
    if (N == 1)
        answer = brother[0];
    else {
        answer = gcd(brother[0], brother[1]);
        
        for (int a = 2; a < N; ++a) {
            answer = gcd(answer, brother[a]);
        }
    }

    cout << answer;
    return 0;
}

