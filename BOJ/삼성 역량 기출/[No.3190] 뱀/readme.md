문제 사이트 : https://www.acmicpc.net/problem/3190

문제 설명

![image](https://github.com/user-attachments/assets/366b8442-aea4-44c0-8c3f-736a19edb691)
![image](https://github.com/user-attachments/assets/fb824aff-3e3f-41f2-8cde-b54d20276d83)
![image](https://github.com/user-attachments/assets/6be0a20d-ed91-42b7-95d1-48a196fa82f3)
![image](https://github.com/user-attachments/assets/43ccb45f-29e2-4dbd-82a3-be3a8b17e16e)

풀이 알고리즘

    주어진 조건에 맞게 뱀을 이동시키고, 게임이 종료되는 시점을 출력하는 문제 '뱀' 입니다.

    문제의 설명을 정확하게 이해 후 구현하는 역량이 필요한 문제로 문제 풀이 과정에서 고려해야 하는 사항은 아래와 같습니다.

    1) 게임이 끝나는 시점은 이동 후 1초
    -> 3초에 특정 방향으로 이동했을 때, 게임이 종료된다면 종료되는 시점은 4초

    2) 늘어난 뱀의 길이는 줄어들지 않음

    3) 뱀이 이동할 때 머리가 먼저 움직인 이후, 꼬리가 사라지거나 유지 된다.

    4) 변환 정보가 모두 주어지더라도 게임이 안 끝날 수 있다. 따라서 변환 정보가 모두 수행되었다면

    추가로 게임이 끝날 때 까지 뱀을 이동시켜야 한다.

    위 내용을 바탕으로 구현한 코드는 아래와 같습니다.

풀이 코드

    #include<iostream>
    #include <vector>
    #include <unordered_map>
    #include <queue>
    #include <memory.h>
    #include <string>
    using namespace std;
    
    
    
    
    struct Node {
    	int x;
    	int y;
    };
    int N, K, L;
    int mov[4][2] = { {-1,0},{0,1},{1,0}, {0,-1} };
    bool apple[110][110];
    // empty == 0, body == 1, apple = 2  
    int mp[110][110];
    vector<Node> body; // 앞은 꼬리, 뒤는 머리
    int tIDX = 0; // tail IDX, 꼬리 위치 관리용
    Node head;
    int snakeHead = 1;
    
    bool Go() { // 그냥 직진
    	int nx = head.x + mov[snakeHead][0];
    	int ny = head.y + mov[snakeHead][1];
    
    
    	if (nx > N || nx <= 0 || ny > N || ny <= 0) { // 벽
    		return 0;
    	}
    
    	if (mp[nx][ny] == 1){ // 몸
    		return 0;
    	}
    
    	if (mp[nx][ny] == 0) { // 사과가 없다면 꼬리 지우기.
    		mp[body[tIDX].x][body[tIDX].y] = 0;
    		tIDX++;
    	}		

     // 머리 움직이기
    	body.push_back({ nx,ny });
    	head = { nx,ny };

     // 뱀 위치 기록하기
    	mp[nx][ny] = 1;
    
    	return true;
    
    }
    int Solve() {
    	int nTime = 0;
    	body.push_back({1,1}); // 좌표 1,1에 머리는 오른쪽(위 = 0, 오른쪽 = 1, 아래 = 2, 왼쪽은 = 3)
    	mp[1][1] = 1;
    	head = { 1,1 };
    	for (int a = 0; a < L; ++a) {
    		int time;
    		char command;
    
    		cin >> time >> command;

    // 입력받은 특정 시간이 될 때까지 직진
    		while (nTime < time) {
    			++nTime;
    			bool checker = Go();

       // 게임이 끝났다면 시간 return
    			if (checker == 0) {
    				return nTime;
    			}
    		}

    // 특정 시간까지 게임이 무사히 진행되었다면 머리 돌리기
    		if (command == 'L') {
    			snakeHead = (snakeHead + 3) % 4;
    		}
    		else {
    			snakeHead = (snakeHead + 1) % 4;
    		}
    	}

     // 변환 정보가 모두 끝난 이후에도 게임이 진행 중 이라면 끝날 때까지 진행해보자
    	while (1) {
    		++nTime;
    		bool checker = Go();
    		if (checker == 0)
    			return nTime;
    
    	}
    
    }
    
    
    void Input() {
    	cin >> N >> K;
    	for (int a = 0; a < K; ++a) {
    		int x, y;
    		cin >> x >> y;
    		mp[x][y] = 2;
    	}
    	cin >> L;
    }
    int main(int argc, char** argv)
    {
    	ios::sync_with_stdio(false);
    
    	cin.tie(NULL);
    	cout.tie(NULL);
    	
    
    	Input();
    	cout << Solve();
    	return 0;//정상종료시 반드시 0을 리턴해야합니다.
    }
