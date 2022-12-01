#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
  //  freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    unsigned int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    unsigned int ar[20] = { 0 };
    for (int a = 0; a < n; ++a) {
        string command = "";
        int num=19;
        cin >> command;
        if (command != "all" && command != "empty") {
            cin >> num;
            if (command == "add") {
                if (ar[num - 1] == 0)
                    ar[num - 1] = num;
            }
            else if (command == "remove") {
                if (ar[num - 1] != 0)
                    ar[num - 1] = 0;
            }
            else if (command == "check") {
                if (ar[num - 1] != 0)
                    cout << "1\n";
                else
                    cout << "0\n";
            }
            else if (command == "toggle") {
                if (ar[num - 1] == 0)
                    ar[num - 1] = num;
                else
                    ar[num - 1] = 0;
            }
        }
        else {
            if (command == "all") {
                for (int b = 0; b < 20; ++b) {
                    ar[b] = b + 1;
                }
            }
            else if (command == "empty") {
                for (int b = 0; b < 20; ++b) {
                    ar[b] = 0;
                }
            }
        }
    }
    return 0;
}
