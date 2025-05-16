#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

// 숫자를 문자열로 뒤집고 선행 '0' 제거
string reverse_and_trim(const string& num_str) {
    string reversed_str = num_str;
    reverse(reversed_str.begin(), reversed_str.end());
    // 선행 '0' 제거
    size_t first_non_zero = reversed_str.find_first_not_of('0');
    if (first_non_zero != string::npos) {
        return reversed_str.substr(first_non_zero);
    } else {
        return "0";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(); // 첫 줄의 개행 문자 제거

    vector<string> numbers;
    string line;
    int count = 0;

    while (count < n && getline(cin, line)) {
        istringstream iss(line);
        string num_str;
        while (iss >> num_str) {
            string processed = reverse_and_trim(num_str);
            numbers.push_back(processed);
            count++;
            if (count == n) break;
        }
    }

    sort(numbers.begin(), numbers.end(), [](const string& a, const string& b) {
        if (a.length() != b.length())
            return a.length() < b.length();
        return a < b;
    });

    for (const auto& num : numbers) {
        cout << num << '\n';
    }

    return 0;
}
