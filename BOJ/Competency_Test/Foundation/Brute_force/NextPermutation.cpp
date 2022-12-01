#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> before;
    vector<int> temp(n);
    int t;
    for (int a = 0; a < n; ++a) {
        cin >> t;
        before.push_back(t);
        temp.push_back(t);
    }
    int check = 0;
    if (next_permutation(before.begin(), before.end())) {
        for (int a = 0; a < before.size(); ++a) {
            printf("%d ", before[a]);
        }
    }
    else
        printf("-1");
    return 0;
}
