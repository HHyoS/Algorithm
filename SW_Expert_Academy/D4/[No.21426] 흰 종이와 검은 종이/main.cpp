/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rect {
    long long x1, y1, x2, y2;
};

bool positiveArea(const Rect &r) {
    return r.x1 < r.x2 && r.y1 < r.y2;
}

// 흰 종이 R에서 검은 종이 B의 교집합 영역을 제거한 후 남는 영역(최대 4개의 직사각형)을 반환
vector<Rect> subtractRect(const Rect &R, const Rect &B) {
    vector<Rect> rem;
    // R과 B의 교집합 계산
    long long ix1 = max(R.x1, B.x1);
    long long iy1 = max(R.y1, B.y1);
    long long ix2 = min(R.x2, B.x2);
    long long iy2 = min(R.y2, B.y2);
    
    // 교집합이 없으면 R 그대로 반환
    if (ix1 >= ix2 || iy1 >= iy2) {
        rem.push_back(R);
        return rem;
    }
    
    // R의 아래쪽 부분
    if (R.y1 < iy1) {
        rem.push_back({R.x1, R.y1, R.x2, iy1});
    }
    // R의 위쪽 부분
    if (iy2 < R.y2) {
        rem.push_back({R.x1, iy2, R.x2, R.y2});
    }
    // R의 좌측 부분 (교집합의 수직 범위 내)
    if (R.x1 < ix1) {
        rem.push_back({R.x1, iy1, ix1, iy2});
    }
    // R의 우측 부분 (교집합의 수직 범위 내)
    if (ix2 < R.x2) {
        rem.push_back({ix2, iy1, R.x2, iy2});
    }
    
    return rem;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        Rect white, black1, black2;
        cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
        cin >> black1.x1 >> black1.y1 >> black1.x2 >> black1.y2;
        cin >> black2.x1 >> black2.y1 >> black2.x2 >> black2.y2;
        
        // 초기 흰 종이 영역 (여러 개의 직사각형으로 분리될 수 있음)
        vector<Rect> pieces;
        pieces.push_back(white);
        
        // 첫 번째 검은 종이에 대해 영역 빼기
        vector<Rect> newPieces;
        for(auto &r : pieces) {
            vector<Rect> sub = subtractRect(r, black1);
            for(auto &s : sub) {
                if(positiveArea(s))
                    newPieces.push_back(s);
            }
        }
        pieces = newPieces;
        
        // 두 번째 검은 종이에 대해 영역 빼기
        newPieces.clear();
        for(auto &r : pieces) {
            vector<Rect> sub = subtractRect(r, black2);
            for(auto &s : sub) {
                if(positiveArea(s))
                    newPieces.push_back(s);
            }
        }
        pieces = newPieces;
        
        // 남아있는 영역이 있다면 흰 종이가 보임.
        if(pieces.empty()) cout << "NO\n";
        else cout << "YES\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
