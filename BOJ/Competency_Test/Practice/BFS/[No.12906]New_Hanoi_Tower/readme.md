문제 사이트 : https://www.acmicpc.net/problem/12906

문제 설명 :

    오늘은 새로운 하노이 탑 게임을 해보려고 한다. 
    
    이 게임의 규칙은 다음과 같다.

    막대는 총 세 가지 종류가 있다. 
    
    막대 A, 막대 B, 막대 C
    
    게임이 시작될 때, 각각의 막대에는 0개 또는 그 이상의 원판이 놓여져 있다.
    
    모든 원판의 크기는 같으며, 원판의 종류도 A, B, C로 세 가지가 있다. 
    
    원판은 원판 A, 원판 B, 원판 C와 같이 표현한다.
    
    한 번 움직이는 것은 한 막대의 가장 위에 있는 원판을 다른 막대의 가장 위로 옮기는 것이다.
    
    게임의 목표는 막대 A에는 원판 A만, 막대 B는 원판 B만, 막대 C는 원판 C만 놓여져 있어야 한다.
    
    되도록 최소로 움직여야 한다.
    
    막대 A, 막대 B, 막대 C에 놓여져 있는 원판의 상태가 주어졌을 때, 
    
    게임의 목표를 달성하는데 필요한 움직임의 최소 횟수를 구하는 프로그램을 작성하시오.

입력

    첫째 줄에 막대 A에 놓여져 있는 원판의 개수와 막대 A의 상태, 
    
    둘째 줄에 막대 B에 놓여져 있는 원판의 개수와 막대 B의 상태, 
    
    셋째 줄에 막대 C에 놓여져 있는 원판의 개수와 막대 C의 상태가 주어진다.
    
    막대의 상태는 밑에 있는 원판부터 주어진다.

    각 막대의 상태는 A, B, C로만 이루어진 문자열이며, 
    
    모든 막대에 놓여져 있는 원판 개수의 합은 1보다 크거나 같고, 10보다 작거나 같다.
    
출력

    게임의 목표를 달성하는데 필요한 움직임의 최소 횟수를 출력한다.
    
풀이 알고리즘

    1. 주어진 조건에 맞추어 세개의 막대에 막다 A에는 A원판만, B에는 B원판만,
    
    C에는 C원판만 만들때 최소횟수를 출력하는 문제였습니다.
    
    2. 문제 해결은 최소횟수를 찾는 문제이기 때문에 BFS방식으로 구현하였고, 타워의 상태를 배열로 구현하면
    
    메모리 초과가 발생할 수 있기떄문에 A, B, C 기둥상태를 string으로 유지하며 하노이탑을 구현하였습니다.
    
    3. 같은 기둥의 상태를 반복해서 만들지 않기위해 기둥의 상태를 Set Container 이용하여 방문 시 
    
    Container에 insert하여 두번 방문시 해당 위치를 방문하지 않도록 구현하였고, 방문한 곳이 아닐 시
    
    queue Container에 Queue(pair<pair<string,string>,string>) 와 같은 방식으로 세 기둥의 상태를
    
    저장 후 BFS탐색을 진행하였습니다.
    
[ 구 현 ]

    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <vector>
    #include <queue>
    #include <utility>
    #include <set>
    using namespace std;
    int n;
    set<pair<pair<string,string>,string>> mp;

    bool check(string st1, string st2, string st3) { // 기둥을 이동시켰을 떄 하노이탑이 완성되는지 확인
      for (int a = 0; a < st1.length(); ++a) {
        if (st1[a] != 'A') // 첫번째 기둥에 'A'가 아닌 원판이 있을경우 check() 탈출
          return 0;
      }
      for (int a = 0; a < st2.length(); ++a) {
        if (st2[a] != 'B')// 두번째 기둥에 'B'가 아닌 원판이 있을경우 check() 탈출
          return 0;

      }
      for (int a = 0; a < st3.length(); ++a) {
        if (st3[a] != 'C')// 세번째 기둥에 'C'가 아닌 원판이 있을경우 check() 탈출
          return 0;
      }

      return 1;
    }
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      //freopen("Input.txt", "r", stdin);
      int n_1,n_2,n_3;
      string ha, no, ee;
      queue <pair<pair<string,string>, string>> que; // BFS탐색에 사용할 queue Container로
      // 세 기둥의 상태를 string값으로 유지하여 탐색 실시


      cin >> n_1;
      if (n_1 > 0)
        cin >> ha;
      cin >> n_2;
      if (n_2 > 0)
        cin >> no;
      cin >> n_3;
      if (n_3 > 0)
        cin >> ee;
       // 기둥의 값이 0이라면 기둥정보를 입력할필요 없으므로 체크하여 필요한 기둥정보 입력
       
      que.push({{ha,no},ee});
      mp.insert({{ha,no},ee });
      // 초기상태 queue에 저장 후 set Container에 방문표시
      
      int answer = 0;
      if (check(ha, no, ee)){
        cout << "0";
        return 0;
        }
        //초기값이 완성된 상태라면 0출력후 탈출
        
      while (!que.empty()) {
        int size = que.size(); // queue에 담긴 기둥의 상태 갯수 확인 후
        for (int a = 0; a < size; ++a) { // 갯수만큼 for문 반복
        
          string st1 = que.front().first.first;
          string st2 = que.front().first.second;
          string st3 = que.front().second;
          // 세가지 기둥상태 저장
          que.pop();

          int size_1 = st1.length();
          int size_2 = st2.length();
          int size_3 = st3.length();
          // 세가지 기둥에 원판들의 갯수 저장
          char wd;
          
          if (size_1 > 0) { // A 기둥의 경우 자신이 가진 원판이 있을경우
          // B 기둥과 C기둥에 전달하는 경우를 만들 수 있으므로 해당 경우 구현
            wd = st1.at(size_1 - 1); // A기둥 맨 위의 원판을 wd에 담은 후
            string temp = st1.substr(0,size_1 - 1); // temp에 맨 위의 원판을 제외한 값을 저장
            if (mp.find({ {temp,st2+wd},st3 }) == mp.end()) { // 원판이 이동된 상태가 이미
            //set Container에 담기지않은 처음 방문한 케이스일경우  if문 동작
              if (check(temp, st2 + wd, st3)) { // 이동했을 경우 하노이탑이 완성되면
                cout << answer + 1; // answer에 1추가후 프로그램 종료
                return 0;
              }
              else { // 아닐경우
                que.push({ {temp,st2 + wd},st3 }); // queue에 이동 후 상태 push후 
                mp.insert({{temp,st2 + wd},st3 }); // set에 방문표시
              }
            }
            // A번기둥 원판을 C기둥으로 이동
            if (mp.find({ {temp,st2 },st3 + wd }) == mp.end()) {
              if (check(temp, st2 , st3+wd)) {
                cout << answer + 1;
                return 0;
              }
              else {
                que.push({ {temp,st2},st3 + wd });
                mp.insert({{temp,st2},st3+wd });
              }
            }
          }

          if (size_2 > 0) {
            wd = st2.at(size_2 - 1);
            string temp = st2.substr(0,size_2 - 1);
            if (mp.find({ {st1+wd,temp},st3 }) == mp.end()) {
            // B번기둥 원판을 A기둥으로 이동
              if (check(st1+wd, temp, st3)) {
                cout << answer + 1;
                return 0;
              }
              else {
                que.push({ {st1+wd,temp},st3 });
                mp.insert({{st1+wd,temp},st3 });
              }
            }
            if (mp.find({ {st1,temp },st3 + wd }) == mp.end()) {
            // B번기둥 원판을 C기둥으로 이동
              if (check(st1, temp, st3 + wd)) {
                cout << answer + 1;
                return 0;
              }
              else {
                que.push({ {st1,temp},st3 + wd });
                mp.insert({{st1,temp},st3 + wd });
              }
            }
          }

          if (size_3 > 0) {
            wd = st3.at(size_3 - 1);
            string temp = st3.substr(0,size_3 - 1);
            if (mp.find({ {st1 + wd,st2},temp }) == mp.end()) {
            // C번기둥 원판을 A기둥으로 이동
              if (check(st1 + wd, st2, temp)) {
                cout << answer + 1;
                return 0;
              }
              else {
                que.push({ {st1 + wd,st2},temp });
                mp.insert({{st1 + wd,st2},temp });
              }
            }
            if (mp.find({ {st1, st2+wd },temp}) == mp.end()) {
            // C번기둥 원판을 B기둥으로 이동
              if (check(st1,st2+wd,temp)) {
                cout << answer + 1;
                return 0;
              }
              else {
                que.push({ {st1,st2+wd},temp });
                mp.insert({{st1,st2+wd},temp });
              }
            }
          }
        }
        ++answer; // 한번의 이동들이 모두 끝나면 answer 1 추가
      }
      return 0;
    }


    
    
