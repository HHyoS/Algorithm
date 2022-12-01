#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int size = 0;
int nn = 0;
bool ins_bo(int x, int y, map<pair<int,int>,int>& gi, map<pair<int,int>,int>& bo){ // 보 설치
    if(x < nn && y <= nn ){ // 주어진 사이즈 보다 크거나 설치했을 때 주어진 사이즈를 벗어나면 false
        if(gi[{x,y-1}]==1 ||  gi[{x+1,y-1}] == 1 || (bo[{x-1,y}]==1 && bo[{x+1,y}] == 1)){ // 자신의 밑에 기둥이 있거나, 설치하고자 하는 위치 오른쪽 아래에 기둥이 있거나, 좌우에
        // 보가 설치되어있을경우
            bo[{x,y}]=1; // 설치
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
bool ins_gidoong(int x, int y, map<pair<int,int>,int>& gi, map<pair<int,int>,int>& bo){
    if(x <= nn && y < nn){ // 주어진 사이즈 보다 크거나 설치했을 때 주어진 사이즈를 벗어나면 false
        if(y == 0 || gi[{x,y-1}] ==1 || bo[{x-1,y}] == 1 || bo[{x,y}] ==1){ // 바닦에서 시작하거나 || 설치하고자 하는 위치 아래에 기둥이 있거나, 설치하고자 하는 위치에 보가 설치
        //되 있으면 시작
            gi[{x,y}]=1; // 설치
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
void del(vector<int> command, map<pair<int,int>,int>& gi, map<pair<int,int>,int>& bo){
    int x = command[0];
    int y = command[1]; 
    if(command[2] == 0) // 주어진 커맨드에 따라 무엇을 삭제하는지 확인 0은 기둥
        gi[{x,y}] = 0;
    else if(command[2] == 1) // 1은 보
        bo[{x,y}] = 0;
    for(auto a : gi){ // 여기부터 끝까지의 코드는 삭제한 이후 존재하는 모든 설치물에 대해 그 위치에 재설치 할경우 문제가 없는지 확인, 문제가 발생한 경우 삭제햇던 것을 재 설치 후 
    // del 
        if(a.second == 1){
            int xx = a.first.first;
            int yy = a.first.second;
            if(ins_gidoong(xx, yy, gi,bo))
                continue;
            else{
                if(command[2] == 0){
                    gi[{x,y}] = 1;
                    return;}
                else if(command[2] == 1){
                    bo[{x,y}] = 1;
                    return;
                }
            }
        }
    }
    for(auto a : bo){
        if(a.second==1){
            int xx = a.first.first;
            int yy = a.first.second;
            if(ins_bo(xx, yy , gi,bo))
                continue;
            else{
                if(command[2] == 0){
                    gi[{x,y}] = 1;
                    return;}
                else if(command[2] == 1){
                    bo[{x,y}] = 1;
                    return;
                }
            }
        }
    }
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    map<pair<int,int>,int> gidoong;
    map<pair<int,int>,int> bo;
    int start = 0;
    nn = n;
    for(int a =0; a < build_frame.size(); ++a){ // 주어진 명령어를 차례대로 수행하며 끝까지 수행 실시
        if(build_frame[a][2] == 0 && build_frame[a][3] == 1)
            ins_gidoong(build_frame[a][0],build_frame[a][1], gidoong, bo);
        else if(build_frame[a][2] == 1 && build_frame[a][3] == 1)
            ins_bo(build_frame[a][0],build_frame[a][1], gidoong, bo);
        else if(build_frame[a][3] == 0)
            del(build_frame[a], gidoong, bo);
    }
    vector<int> temp; // 정답을 넣을 임시벡터 생성
    for(int a = 0; a <= n; ++a){ // 주어진 사이즈 n x n 에 대하여 탐색하며 해당 위치의 map pair<int,int> 값이 1인지 확인한 후 1이면 answer에 추가. // map은 int값을 설정할 경우 기본
    // default가 0
        for(int b = 0; b <= n; ++b){
            if(gidoong[{a,b}] == 1){
                temp = {a,b,0};
                answer.push_back(temp);
            }
            if(bo[{a,b}] == 1){
                temp = {a,b,1};
                answer.push_back(temp);
            }
        }
    }
    return answer;
}
