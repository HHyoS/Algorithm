#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


// 기본적인 데이터 타입(int, string, char, bool .. etc)를 index로 쓸 수 있게하는 구조체
// 내부적인 동작으로 데이터 타입을 index로 넣으면 hash값으로 변환하여 hash값을 index로 씀
// 그렇기 때문에 값을 찾아갈 때 ( 인덱스 값 -> hash값 변환 -> 데이터 찾아가기 ) 순서가 되므로
// 시간이 더 소요될 수 있음.
unordered_map<string, int> NameToNum;
string NumToName[100001];;
int N, M;

void InputData() {

    int idx = 1;
    for (int a = 1; a <= N; ++a) {
        string temp;
        cin >> temp;

        // unordered_map 구조체에 temp에 해당하는 string이 있는지 확인
        if (NameToNum.count(temp) == 0) {

            // temp에 해당하는 문자가 없다면 구조체에 값을 입력하고, index를 할당시킴
            NameToNum[temp] = idx;

            // index를 바탕으로 이름도 찾아가야 하므로 별도의 값 저장해두기
            NumToName[idx++] = temp;
        }
    }

}

void OutputData() {
    for (int a = 0; a < M; ++a) {
        string temp;
        cin >> temp;

        // 값이 숫자인지 확인 -> 숫자가 아니라면 0이 나오고, 숫자라면 숫자가 num변수에 저장
        int num = atoi(temp.c_str());
        if (num == 0) {
            // 숫자가 아니므로 unordered_map 구조체에서 temp에 해당하는 index를 출력
            cout << NameToNum[temp] << "\n";
        }
        else {
            // 숫자이므로 해당 숫자에 해당하는 string 값 출력
            cout << NumToName[num] << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    InputData();
    OutputData();
    return 0;
}
