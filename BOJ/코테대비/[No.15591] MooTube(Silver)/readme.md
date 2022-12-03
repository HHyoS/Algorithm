문제 사이트 : https://www.acmicpc.net/problem/15591

풀이 환경 : Visaul Studio 2019 / 언어 : C++

문제 설명 :

    농부 존은 남는 시간에 MooTube라 불리는 동영상 공유 서비스를 만들었다.
    
    MooTube에서 농부 존의 소들은 재밌는 동영상들을 서로 공유할 수 있다. 
    
    소들은 MooTube에 1부터 N까지 번호가 붙여진 N (1 ≤ N ≤ 5,000)개의 동영상을 이미 올려 놓았다. 
    
    하지만, 존은 아직 어떻게 하면 소들이 그들이 좋아할 만한 새 동영상을 찾을 수 있을지 괜찮은 방법을 떠올리지 못했다.

    농부 존은 모든 MooTube 동영상에 대해 “연관 동영상” 리스트를 만들기로 했다. 
    
    이렇게 하면 소들은 지금 보고 있는 동영상과 연관성이 높은 동영상을 추천 받을 수 있을 것이다.

    존은 두 동영상이 서로 얼마나 가까운 지를 측정하는 단위인 “USADO”를 만들었다. 
    
    존은 N-1개의 동영상 쌍을 골라서 직접 두 쌍의 USADO를 계산했다. 
    
    그 다음에 존은 이 동영상들을 네트워크 구조로 바꿔서, 각 동영상을 정점으로 나타내기로 했다. 
    
    또 존은 동영상들의 연결 구조를 서로 연결되어 있는 N-1개의 동영상 쌍으로 나타내었다. 
    
    좀 더 쉽게 말해서, 존은 N-1개의 동영상 쌍을 골라서 어떤 동영상에서 다른 동영상으로 가는 경로가 반드시 하나 존재하도록 했다.
    
    존은 임의의 두 쌍 사이의 동영상의 USADO를 그 경로의 모든 연결들의 USADO 중 최솟값으로 하기로 했다.

    존은 어떤 주어진 MooTube 동영상에 대해, 값 K를 정해서 그 동영상과 USADO가 K 이상인 모든 동영상이 추천되도록 할 것이다. 
    
    하지만 존은 너무 많은 동영상이 추천되면 소들이 일하는 것이 방해될까 봐 걱정하고 있다! 그래서 그는 K를 적절한 값으로 결정하려고 한다.
    
    농부 존은 어떤 K 값에 대한 추천 동영상의 개수를 묻는 질문 여러 개에 당신이 대답해주기를 바란다.

입력

    입력의 첫 번째 줄에는 N과 Q가 주어진다. (1 ≤ Q ≤ 5,000)

    다음 N-1개의 줄에는 농부 존이 직접 잰 두 동영상 쌍의 USADO가 한 줄에 하나씩 주어진다. 
    
    각 줄은 세 정수 pi, qi, ri (1 ≤ pi, qi ≤ N, 1 ≤ ri ≤ 1,000,000,000)를 포함하는데, 
    
    이는 동영상 pi와 qi가 USADO ri로 서로 연결되어 있음을 뜻한다.

    다음 Q개의 줄에는 농부 존의 Q개의 질문이 주어진다. 
    
    각 줄은 두 정수 ki와 vi(1 ≤ ki ≤ 1,000,000,000, 1 ≤ vi ≤ N)을 포함하는데, 
    
    이는 존의 i번째 질문이 만약 K = ki라면 동영상 vi를 보고 있는 소들에게 몇 개의 동영상이 추천될 지 묻는 것이라는 것을 뜻한다.

출력

    Q개의 줄을 출력한다. i번째 줄에는 농부 존의 i번째 질문에 대한 답변이 출력되어야 한다.

예제 입력 1 

    4 3
    1 2 3
    2 3 2
    2 4 4
    1 2
    4 1
    3 1
    
예제 출력 1 

    3
    0
    2
    
풀이 방법 

    어렵게 생각했다가 하루종일 고생한 문제였습니다. 문제를 풀며 '혹시 사이클이 생기면 어떻게 처리하지?' 라는 생각으로 하루종일 고민했는데, 
    
    그런건 없다고 가정하고 풀었더니 풀려버린 문제였습니다.
    
    문제의 지문은 매우 길지만 요약하면 다음과 같습니다. 
    
    그래프로 연결된 노드와 간선의 가중치가 주어지고, 시작지점 A와 가중치 K를 주었을 떄, 
    
    A와 연결된 노드 중 K값 이상의 가중치를 갖는 간선으로 연결 된 노드의 갯수 찾기 입니다.
    
    위의 요약대로 구현을 하는 방법으로는 DFS와 BFS가 있는데, 
    
    DFS로 할 경우 각 각의 가중치값을 저장하는 배열을 따로 만들어야하는 메모리 사용이 있어서
    
    Q와 N의 값이 5000으로 작은값인만큼 그냥 매번 BFS를 돌려주기로 했습니다.
    
    BFS탐색의 조건은 다음과 같습니다. 1) 이미 방문한 노드면 Pass 2) 연결된 노드의 간선의 가중치가 K보다 작으면 Pass
    
    이 두가지 조건을 제외하고는 연결된 모든 노드를 방문하면서 갯수를 
    
    더해주고 가능한 모든 노드를 탐색했다면 갯수를 return하여 문제를 해결하였습니다..
    
 구 현
 
     #define _CRT_SECURE_NO_WARNINGS
    #include<iostream>
    #include <memory.h>
    #include <algorithm>
    #include <vector>
    #include <queue>
    using namespace std;

    struct Infomation {
        int index;
        int k;
    };

    vector<Infomation> tmp[5001];
    int ans = 0;

    int bfs(int start,int maxi) {
        bool visited[5001] = { 0 };

        visited[start] = 1;
        queue<int> que;
        que.push(start);
        int answerCnt = 0;
        while (!que.empty()) {
            int index = que.front();
            que.pop();
            for (int a = 0; a < tmp[index].size(); ++a) {
                Infomation next = tmp[index][a];
                if (visited[next.index]) continue;
                if (next.k < maxi) continue;
                ++answerCnt;
                visited[next.index] = 1;
                que.push(next.index);

            }
        }
        return answerCnt;
    }
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

       // freopen("input.txt", "r", stdin);
        int N, Q;
        cin >> N >> Q;
        for (int a = 0; a < N-1; ++a) {
            int p, q, r;
            cin >> p >> q >> r;
            tmp[p].push_back({ q,r });
            tmp[q].push_back({ p,r });
        }

        for (int a = 0; a < Q; ++a) {
            int start, maxi;
            cin >> maxi >> start;
            cout << bfs(start, maxi) << "\n";;
        }
        return 0;

    }
   
   
   
풀이 인증

![image](https://user-images.githubusercontent.com/57944215/205439015-dfc4bf1d-afda-4545-b82f-41abd783e42b.png)
