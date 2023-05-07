#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 합의 종류가 저장될 unorderd_map 변수
unordered_map<int,bool> mp;
int solution(vector<int> elements) {
    
    int size = elements.size();
    for(int a = 0; a < size; ++a){
        int now = 0;
        for(int b =0; b < size; ++b){
            int idx = (a+b)%size;
            now += elements[idx];
            
            // 만약 mp에 저장되지 않은 새로운 값이라면
            if(mp.count(now)==0){
                // mp에 등록
                mp[now] = 1;
            }
        }
    }
    // mp에 등록된 값의 갯수가 서로다른 합의 개수이므로 size를 answer에 저장
    int answer = mp.size();;
    return answer;
}
