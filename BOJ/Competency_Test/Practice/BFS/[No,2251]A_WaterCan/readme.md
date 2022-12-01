문제 사이트 : https://www.acmicpc.net/problem/2251

문제 설명

    각각 부피가 A, B, C(1≤A, B, C≤200) 리터인 세 개의 물통이 있다.
    
    처음에는 앞의 두 물통은 비어 있고, 세 번째 물통은 가득(C 리터) 차 있다.
    
    이제 어떤 물통에 들어있는 물을 다른 물통으로 쏟아 부을 수 있는데, 이때에는 한 물통이 비거나, 
    
    다른 한 물통이 가득 찰 때까지 물을 부을 수 있다. 이 과정에서 손실되는 물은 없다고 가정한다.

    이와 같은 과정을 거치다보면 세 번째 물통(용량이 C인)에 담겨있는 물의 양이 변할 수도 있다. 
    
    첫 번째 물통(용량이 A인)이 비어 있을 때, 세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양을 모두 구해내는 프로그램을 작성하시오.

입력

    첫째 줄에 세 정수 A, B, C가 주어진다.

출력

    첫째 줄에 공백으로 구분하여 답을 출력한다. 각 용량은 오름차순으로 정렬한다.

예제 입력 1 

    8 9 10

예제 출력

    1 
    1 2 8 9 10

코드

    #include <iostream>
    #include <vector>
    #include <queue>
    #include <algorithm>
    using namespace std;

    const int MAX = 200 + 1;

    int A, B, C;
    bool cache[MAX][MAX][MAX];

    vector<int> BFS(void){
            queue < pair<pair<int, int>, int>> q; //A, B, C
            q.push(make_pair(make_pair(0, 0), C));
            vector<int> result;

            while (!q.empty()){

                     int a = q.front().first.first;
                     int b = q.front().first.second;
                     int c = q.front().second;
                     q.pop();

                     if (cache[a][b][c])
                             continue;

                     cache[a][b][c] = true;

                     if (a == 0)
                             result.push_back(c);


                     if (a + b > B) 
                             q.push(make_pair(make_pair(a + b - B, B), c));
                     else
                             q.push(make_pair(make_pair(0, a + b), c));


                     if (a + c > C)
                             q.push(make_pair(make_pair(a + b - C, b), C));
                     else
                             q.push(make_pair(make_pair(0, b), a + c));

                     if (b + a > A)
                             q.push(make_pair(make_pair(A, b + a - A), c));
                     else
                             q.push(make_pair(make_pair(b + a, 0), c));

                     if (b + c > C)
                             q.push(make_pair(make_pair(a, b + c - C), C));
                     else
                             q.push(make_pair(make_pair(a, 0), b + c));

                     if (c + a > A)
                             q.push(make_pair(make_pair(A, b), c + a - A));
                     else
                             q.push(make_pair(make_pair(c + a, b), 0));

                     if (c + b > B)
                             q.push(make_pair(make_pair(a, B), c + b - B));
                     else
                             q.push(make_pair(make_pair(a, c + b), 0));

            }

            return result;

    }



    int main(void){
            cin >> A >> B >> C;
            vector<int> result = BFS();
            sort(result.begin(), result.end());

            for (int i = 0; i < result.size(); i++)
                     cout << result[i] << endl;

            return 0;

    }


