#include <iostream>
#include <string>

using namespace std;


int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int cnt = 0;
        string temp;
        cin >> temp;
        if (temp[0] == '1')
            cnt++;
        for (int a = 0; a < temp.length()-1; ++a) {
            if (temp[a] != temp[a + 1]) cnt++;
        }
        cout << "#" << t << " " << cnt << "\n";
    }
}
