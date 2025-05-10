#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// 숫자 합을 계산하는 함수
int sumDigits(const string& s) {
    int sum = 0;
    for (char ch : s) {
        if (isdigit(ch)) {
            sum += ch - '0';
        }
    }
    return sum;
}

// 사용자 정의 비교 함수
bool compare(const string& a, const string& b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    int sumA = sumDigits(a);
    int sumB = sumDigits(b);
    if (sumA != sumB)
        return sumA < sumB;
    return a < b;
}

int main() {
    int N;
    cin >> N;
    vector<string> serials(N);
    for (int i = 0; i < N; ++i) {
        cin >> serials[i];
    }

    sort(serials.begin(), serials.end(), compare);

    for (const string& s : serials) {
        cout << s << '\n';
    }

    return 0;
}
