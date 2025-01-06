#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;




bool judge_aeiou(char input_char) {
    if (input_char == 'a' || input_char == 'e' || input_char == 'i' || input_char == 'o' || input_char == 'u') {
        return 1;
    }
    return 0;
}
bool Solve(string temp) {
    
    int size = temp.size();
    int char_cnt = 1;
    bool aeiou_used = false;
    bool before_aeiou = false;
    if (judge_aeiou(temp[0])) {
        aeiou_used = true;;
        before_aeiou = true;
    }
    for (int a = 1; a < size; ++a) {
        if (judge_aeiou(temp[a])) // 모음 사용 체크
            aeiou_used = true;

        if (temp[a-1] == temp[a]) { // 같은 모음 / 자음 체크
            ++char_cnt;
            if (char_cnt == 2) { // 두번 반복일 때 
                if (temp[a] == 'e' || temp[a] == 'o') { // e와 o는 ok
                    continue;
                }
                else { // 아니면 불가능
                    return 0;
                }
            }
            else if (char_cnt == 3) { // 세번은 모두 불가능
                return 0;
            }
        }
        else {
            bool now_aeiou = judge_aeiou(temp[a]);
            if (now_aeiou == before_aeiou) {
                ++char_cnt;
                if (char_cnt == 3) // 모음 또는 자음이 세번 나옴
                    return 0;
            }
            else {
                char_cnt = 1;
                before_aeiou = now_aeiou;
            }
        }
    }
    if (aeiou_used)
        return 1;
    else
        return 0;
}
void Input() {
    string temp;
    while (1) {
        cin >> temp;
        if (temp == "end")
            break;

        if (Solve(temp)) {
            cout << "<" << temp << "> is acceptable.\n";
        }
        else {
            cout << "<" << temp << "> is not acceptable.\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();


    return 0;
}
