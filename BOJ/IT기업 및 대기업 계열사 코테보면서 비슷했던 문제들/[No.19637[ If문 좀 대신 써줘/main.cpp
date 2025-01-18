#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <string>
using namespace std;


struct Node {
    string title;
    int upper_limit;
};

int N, M;
Node info[100001];
int  bs(int power) {
    int s = 0;
    int e = N-1;
    int ans_idx = 0;
    while (s <= e) {
        int mid = (s + e) / 2;

        if (info[mid].upper_limit >= power) { 
            ans_idx = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans_idx;
}
string Solve(int target) {
    return info[bs(target)].title;
}

void Input() {
    cin >> N >> M;
    int before_power = -1;
    int max_idx = 0;
    for (int a = 0; a < N; ++a) {
        string temp_title;
        int temp_upper_limit;
        cin >> temp_title >> temp_upper_limit;
        if (temp_upper_limit == before_power) {
            continue;
        }
        else {
            before_power = temp_upper_limit;
            info[max_idx++] = { temp_title,temp_upper_limit };
        }
    }
    N = max_idx;
    for (int a = 0; a < M; ++a) {
        int target;
        cin >> target;
        cout << Solve(target) << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    return 0;
}
