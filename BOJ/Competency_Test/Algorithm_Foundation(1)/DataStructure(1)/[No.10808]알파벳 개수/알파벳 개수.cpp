#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int N,X;
char S[101];
int alpha[26];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("Input.txt", "r", stdin);
    
    cin >> S;
    for (int a = 0; S[a]; ++a) {
        ++alpha[S[a] - 97];
    }
    for (int a = 0; a < 26; ++a) {
        cout << alpha[a] << " ";
    }
    return 0;
}
