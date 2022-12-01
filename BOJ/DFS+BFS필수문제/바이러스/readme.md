문제 사이트 : https://www.acmicpc.net/problem/2606

문제 설명 :

    신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 
    
    한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 
    
    있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

    예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 
    
    1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 
    
    컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 
    
    하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에
    
    영향을 받지 않는다.

![zmMEZZ8ioN6rhCdHmcIT4a7](https://user-images.githubusercontent.com/57944215/184539348-c01978d7-301b-4c8d-a97d-734f1bea899a.png)


    어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

입력

    첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

출력

    1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

예제 입력 1 

    7
    6
    1 2
    2 3
    1 5
    5 2
    5 6
    4 7

예제 출력 1 

    4
    
풀이 알고리즘

    네트워크로 연결된 컴퓨터들 중 1번 컴퓨터가 감염되었을 때, 감염되는 컴퓨터의 수를 출력하는 문제였습니다.
    
    문제 해결을 위해 입력값으로 들어오는 컴퓨터들의 연결정보를 양방향 인접리스트로 구현하였고,
    
    방문한 컴퓨터를 관리하는 bool 배열을 선언하여 방문했던 컴퓨터를 관리하여 
    
    연결된 모든 컴퓨터를 방문하고 그 갯수를 출력하도록 구현하였습니다.
    
    양방향 인접리스트는 2차원 vector로 구현하여 입력받았고, 연결된 컴퓨터의 모든 방문은
    
    queue를 사용한 bfs탐색을 통해 모든 컴퓨터를 방문할 수 있도록 하였습니다.
    
구 현

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
bool checker[101];
vector<vector<int>> virus(101);
int solve() {

	queue<int> que;
	checker[1] = 1;
	que.push(1);
	int cnt = 0;
	while (!que.empty()) {
		int idx = que.front();
		que.pop();

		for (int a = 0; a < virus[idx].size(); ++a) {
			if (!checker[virus[idx][a]]) {
				que.push(virus[idx][a]);
				checker[virus[idx][a]] = 1;
				++cnt;
			}
		}
	}
	return cnt;
}
void input() {
	cin >> N >> M;

	for (int a = 0; a < M; ++a) {
		int from,to;
		cin >> from >> to;
		virus[from].push_back(to);
		virus[to].push_back(from);
	}
}

void output(int cnt) {
	cout << cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();

	output(solve());
	return 0;
}
