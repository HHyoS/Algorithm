#include <string>
#include <vector>

using namespace std;

void turn(vector<vector<int>>& key){
    vector<vector<int>> temp;
    temp.assign(key.begin(), key.end());
    for(int a = 0; a < key.size(); ++a){
        for(int b = 0; b < key.size(); ++b){
            key[b][key.size()-1-a] = temp[a][b];
        }
    }
}
    
bool mov(vector<vector<int>> bg, vector<vector<int>> key,int ls, int x, int y){
    
    for(int a = 0; a < key.size(); ++a){
        for(int b = 0; b < key.size(); ++b){
            bg[a+y][b+x] += key[a][b]; // 주어진 x,y 바탕으로 key 행렬 위치 조정
        }
    }
    for(int a = 0; a < ls; ++a){
        for(int b = 0; b < ls; ++b){
            if(bg[key.size()-1+a][key.size()-1+b] == 2 || bg[key.size()-1+a][key.size()-1+b] == 0)
                return false;
        }
        if(a == ls-1)
            return true; // 끝까지 돌앗는데 false가 안나왓으면 모두 1로 true
    }
    
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int ks = key.size();
    int ls = lock.size();
    vector<vector<int>> bg(ks+(ls-1)*2 , vector<int>(ks+(ls-1)*2, 0));
    for(int a = 0; a < ls; ++a){
        for(int b = 0; b < ls; ++b){
            bg[ks-1+a][ks-1+b] = lock[a][b];
        }
    } // 배경이 되는 벡터 생성 후 정 가운데에 lock 넣어주기
    for(int a = 0; a < 4; ++a){ / 90도씩 4번 회전하면 360도 회전
        turn(key); // 90도 회전
        for(int y = 0; y < ks+ls-1;  ++y){
            for(int x = 0; x < ks+ls-1; ++x){
                if(mov(bg,key,ls,x,y)==true)
                    return true; // true 가 하나라도 나오면 바로 true 리턴
            }
        }
    }
    return answer;
}
