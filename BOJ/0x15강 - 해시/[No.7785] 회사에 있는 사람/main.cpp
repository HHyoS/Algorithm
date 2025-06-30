#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<string> company;

    for (int i = 0; i < n; i++) {
        string name, status;
        cin >> name >> status;
        if (status == "enter") {
            company.insert(name);
        } else {
            company.erase(name);
        }
    }

    // 집합을 vector로 복사
    vector<string> result(company.begin(), company.end());
    sort(result.rbegin(), result.rend());  // 내림차순 정렬

    for (const string &name : result) {
        cout << name << '\n';
    }

    return 0;
}
