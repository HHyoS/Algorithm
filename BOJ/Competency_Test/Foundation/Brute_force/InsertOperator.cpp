#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* num = (int*)malloc(sizeof(int) * n);
    for (int a = 0; a < n; ++a)
        cin >> num[a];
    vector<int> temp;
    char* un = (char*)malloc(sizeof(char) * 4);
    for (int a = 0; a < 4; ++a) {
        int t;
        cin >> t;
        for (int b = 0; b < t; ++b) {
            if (a == 0)
                temp.push_back(1);
            else if (a == 1)
                temp.push_back(2);
            else if (a == 2)
                temp.push_back(3);
            else if (a == 3)
                temp.push_back(4);
        }
    }
    sort(temp.begin(), temp.end());
    long long mx = -1000000000;
    long long mn = 10000000000;
    do {
        int start = 0;
        long long sum = num[0];
        for (int a = 1; a < n; ++a) {
            if (temp[start] == 1)
                sum = sum + num[a];
            else if (temp[start] == 2)
                sum = sum - num[a];
            else if (temp[start] == 3)
                sum = sum * num[a];
            else 
                sum = sum / num[a];
            ++start;
        }
        if (sum > mx) {
            mx = sum;
        }

        if (sum < mn) {
            mn = sum;
        }

    } while(next_permutation(temp.begin(), temp.end()));
    printf("%lld\n%lld", mx, mn);
    return 0;
}
