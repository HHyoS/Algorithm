#include <cstdio>
#include <cstring>
#define MOD 1000000007
using namespace std;
long long d[101][101];
int n,m,p;
long long go(int idx,int x){
    int y = n-x;
    if (idx ==p){
        // 길이가 p인 리스트를 만들었을  때,
        // 추가하지 않은 곡이 0개라면 OK (모든 곡을  1번 이상 들어야함)
        if (y==0) return 1;
        else return 0;
    }
    long long &ret = d[idx][x];
    if (ret != -1) return ret;
    ret = 0;
    if (y>0) {
        // 아직 한 번도 추가 안한 곡이 y개 있다면
        ret+=go(idx+1,x+1)*y;
    }
    if (x > m) {
        // 추가된 곡의 수가 중복된 곡을 추가할 수 있는 최소 간격 이상일 때
        ret+=go(idx+1,x)*(x-m);
    }
    ret%=MOD;
    return ret;
}
int main(){
    scanf("%d %d %d", &n, &m, &p);
    memset(d,-1,sizeof(d));
    printf("%lld\n", go(0,0));
    return 0;
}
