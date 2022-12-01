#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
string S;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	//freopen("Input.txt","r", stdin);

    getline(cin, S);
    for (int a = 0; S[a]; ++a) {
        if (S[a] == '<') {
            ++a;
            while (S[a] != '>')
                ++a;
        }
        else if (S[a] == ' ')
            continue;
        else {
            int left = a;
            while ((S[a + 1] != '<') && (S[a+1] != ' ') && (a+1 < S.length())){
                ++a;
            }
            reverse(S.begin() + left, S.begin() + a+1);
        }
    }
    cout << S;
	return 0;

}
