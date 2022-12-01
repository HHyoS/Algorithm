문제 사이트 : https://www.acmicpc.net/problem/12872

문제 설명 :

    수빈이는 BOJ 알고리즘 캠프에서 음악을 들으면서 문제를 풀고 있다.
    
    지금 수빈이의 스마트폰에는 N개의 노래가 저장되어 있다. 오늘 수빈이는 P개의 노래를 들으려고 한다.
    
    수빈이는 다음과 같은 조건을 만족하는 플레이리스트를 만들려고 한다. 플레이리스트에는 같은 노래를 여러 번 추가해도 된다.

    모든 노래를 플레이리스트에 추가해야 한다.
    
    같은 노래를 추가하려면, 플레이리스트에서 두 노래 사이에 적어도 M개의 곡이 있어야 한다.
    
    수빈이는 플레이리스트를 만들 수 있는 경우의 수가 궁금해졌다. N, M, P가 주어졌을 때, 수빈이가 만들 수 있는 플레이리스트의 경우의 수를 구하는 프로그램을 작성하시오.

입력

    첫째 줄에 N, M, P가 주어진다. (1 ≤ N ≤ 100, 0 ≤ M ≤ N, N ≤ P ≤ 100)

출력

    첫째 줄에 수빈이가 만들 수 있는 플레이리스트의 경우의 수를 출력한다. 경우의 수가 매우 커질 수 있기 때문에, 1,000,000,007로 나눈 나머지를 출력한다.

예제 입력 1 

    1 0 3

예제 출력 1 

    1

예제 입력 2 

    1 1 3

예제 출력 2 

    0

예제 입력 3 

    2 0 3

예제 출력 3 

    6

예제 입력 4 

    2 1 4

예제 출력 4 

    2



코드

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
