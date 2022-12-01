#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    int answer = 0;
    int** body = (int**)malloc(sizeof(int*) * n);
    int* temp = (int*)malloc(sizeof(int) * n);
    vector<int> nums(n);
    for (int a = 0; a < n; ++a) {
        int* temp = (int*)malloc(sizeof(int) * n);
        body[a] = temp;
        cin >> nums[a];
        for (int b = 0; b < n; ++b) {
            if (b >= n - a - 1)
                body[a][b] = 1;
            else
                body[a][b] = 0;
        }
    }
    for (int a = 0; a < n; ++a) {
        do {
            int sum = 0;
            int count = a + 1;
            for (int b = 0; b < n; ++b) {
                if (count != 0) {
                    if (body[a][b] == 1) {
                        --count;
                        sum += nums[b];
                    }
                }
                else
                    break;
            }
            if (sum == target)
                ++answer;
        } while (next_permutation(body[a], body[a] + n));
    }
    printf("%d", answer);
    return 0;
}
