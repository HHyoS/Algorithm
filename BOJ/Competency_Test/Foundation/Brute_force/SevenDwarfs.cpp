#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int main() {
    vector<int> ar;
    int t = 0;
    for (int a = 0; a < 9; ++a) {
        cin >> t;
        ar.push_back(t);
    }
    vector<int> arr;
    int left = 0;
    int right = 8;
    int k = 7;
    for (int a = 0; a < k; ++a) 
        arr.push_back(1);
    for (int a = 0; a < 2; ++a)
        arr.push_back(0);

    sort(ar.begin(), ar.end());
    sort(arr.begin(), arr.end());
    do{
        int sum = 0;
        for (int a = 0; a < 9; ++a) {
            if (arr[a] == 1) 
                sum += ar[a];
        }
        if (sum == 100)
            break;
    } while (next_permutation(arr.begin(), arr.end()));
    for (int a = 0; a < 9; ++a) {
        if (arr[a] == 1)
            printf("%d\n", ar[a]);
    }
    return 0;
}
