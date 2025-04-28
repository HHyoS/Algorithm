#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 팰린드롬 확인 함수
bool is_palindrome(int n) {
    string s = to_string(n);
    int len = s.length();
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - 1 - i])
            return false;
    }
    return true;
}

// 소수 확인 함수
bool is_prime(int n) {
    if (n < 2)
        return false;
    int sqrt_n = static_cast<int>(sqrt(n));
    for (int i = 2; i <= sqrt_n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    // 8자리 이상의 짝수 길이의 팰린드롬은 소수가 될 수 없으므로 건너뜁니다.
    if (N >= 10000000)
        N = 10000001;

    while (true) {
        if (is_palindrome(N) && is_prime(N)) {
            cout << N << endl;
            break;
        }
        ++N;
    }

    return 0;
}
