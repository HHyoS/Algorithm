문제 사이트 : https://www.acmicpc.net/problem/15558

문제 설명

    상근이는 오른쪽 그림과 같은 지도에서 진행하는 게임을 만들었다.

    지도는 총 2개의 줄로 나누어져 있으며, 각 줄은 N개의 칸으로 나누어져 있다.
    
    칸은 위험한 칸과 안전한 칸으로 나누어져 있고, 안전한 칸은 유저가 이동할 수 있는 칸, 위험한 칸은 이동할 수 없는 칸이다.

    가장 처음에 유저는 왼쪽 줄의 1번 칸 위에 서 있으며, 매 초마다 아래 세 가지 행동중 하나를 해야 한다.

    한 칸 앞으로 이동한다. 예를 들어, 현재 있는 칸이 i번 칸이면, i+1번 칸으로 이동한다.
    
    한 칸 뒤로 이동한다. 예를 들어, 현재 있는 칸이 i번 칸이면, i-1번 칸으로 이동한다.
    
    반대편 줄로 점프한다. 이때, 원래 있던 칸보다 k칸 앞의 칸으로 이동해야 한다.
    
    예를 들어, 현재 있는 칸이 왼쪽 줄의 i번 칸이면, 오른쪽 줄의 i+k번 칸으로 이동해야 한다.
    
    N번 칸보다 더 큰 칸으로 이동하는 경우에는 게임을 클리어한 것이다.

    게임을 재밌게 하기 위해서, 상근이는 1초에 한 칸씩 각 줄의 첫 칸이 사라지는 기능을 만들었다.
    
    즉, 게임을 시작한지 1초가 지나면 1번 칸이 사라지고, 2초가 지나면 2번 칸이 사라진다. 
    
    편의상 유저가 먼저 움직이고, 칸이 사라진다고 가정한다. 
    
    즉, 이번에 없어질 칸이 3번 칸인데, 상근이가 3번 칸에 있다면, 3번 칸에서 다른 칸으로 이동하고 나서 3번 칸이 없어지는 것이다.

    각 칸의 정보가 주어졌을 때, 게임을 클리어 할 수 있는지, 없는지 구하는 프로그램을 작성하시오.

입력

    첫째 줄에 N과 k가 주어진다. (1 ≤ N, k ≤ 100,000)

    둘째 줄에는 왼쪽 줄의 정보가 주어진다. i번째 문자가 0인 경우에는 위험한 칸이고, 1인 경우에는 안전한 칸이다. 
    
    셋째 줄에는 오른쪽 줄의 정보가 주어지고, 각 문자의 의미는 왼쪽 줄의 의미와 동일하다.

    왼쪽 줄의 1번 칸은 항상 안전한 칸이다.

출력

    게임을 클리어할 수 있으면 1을, 없으면 0을 출력한다.

예제 입력 1 

    7 3
    1110110
    1011001

예제 출력 1 

    1

예제 입력 2 

    6 2
    110101
    011001

예제 출력 2 

    0
    
코드

    #include <iostream>
    #include <vector>
    #include <queue>
    using namespace std;

    struct str{
        int line;
        int current_idx;
        int start_idx;
        str(int line,int current_idx,int start_idx):line(line),current_idx(current_idx),start_idx(start_idx){};
    };

    int main(){

        int N,K;
        cin>>N>>K;

        char c;
        vector<vector<int>> vec(2,vector<int>(N+1,0));
        vector<vector<int>> visit(2,vector<int>(N+1,0));

        for(int i=0;i<2;i++){
            for(int j=1;j<=N;j++){
                cin>>c;
                vec[i][j]=(int)c-48;
            }
        }

        int ans=0;
        queue<str> q;
        q.push(str(0,1,1));

        while(!q.empty()){
            int line=q.front().line;  //0:왼쪽 열, 1:오른쪽 열
            int current_idx=q.front().current_idx;  //현재 index
            int start_idx=q.front().start_idx; //시작지점 index
            q.pop();

            if(current_idx>N){
                ans=1;
                break;
            }

            //이미 확인했는지 체크
            if(visit[line][current_idx])
                continue;

            visit[line][current_idx]=1;

            //1.한칸 앞으로 이동
            if(current_idx+1>N || vec[line][current_idx+1]==1){
                q.push(str(line,current_idx+1,start_idx+1));
            }

            //2.한칸 뒤로 이동
            if(current_idx-1>=start_idx+1 && vec[line][current_idx-1]==1){
                q.push(str(line,current_idx-1,start_idx+1));
            }

            //3.반대편 줄로 점프
            line=(line==0)? 1:0;
            if(current_idx+K>N || vec[line][current_idx+K]==1){
                q.push(str(line,current_idx+K,start_idx+1));
            }
        }

        cout<<ans<<endl;
        return 0;
    }
