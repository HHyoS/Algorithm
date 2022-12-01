문제 사이트 : https://www.acmicpc.net/problem/15661

문제 설명 : 

    오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 축구는 평일 오후에 하고 의무 참석도 아니다. 
    
    축구를 하기 위해 모인 사람은 총 N명이다. 이제 스타트 팀과 링크 팀으로 사람들을 나눠야 한다. 
    
    두 팀의 인원수는 같지 않아도 되지만, 한 명 이상이어야 한다.

    BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. 
    
    능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 
    
    팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를 수도 있으며, i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.

    N=4이고, S가 아래와 같은 경우를 살펴보자.

    i\j	1	2	3	4
    1	 	1	2	3
    2	4	 	5	6
    3	7	1	 	2
    4	3	4	5	 
    
    예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 능력치는 아래와 같다.

    스타트 팀: S12 + S21 = 1 + 4 = 5
    링크 팀: S34 + S43 = 2 + 5 = 7
    
    1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.

    스타트 팀: S13 + S31 = 2 + 7 = 9
    링크 팀: S24 + S42 = 6 + 4 = 10
    
    축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 위의 예제와 같은 경우에는 1, 4번이 스타트 팀, 2, 3번 팀이 링크 팀에 속하면 스타트 팀의 능력치는 6, 링크 팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 최소이다.

입력
첫째 줄에 N(4 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에 S가 주어진다. 각 줄은 N개의 수로 이루어져 있고, i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다.

예제 입력 1 

    4
    0 1 2 3
    4 0 5 6
    7 1 0 2
    3 4 5 0

예제 출력 1 

    0

예제 입력 2 

    6
    0 1 2 3 4 5
    1 0 2 3 4 5
    1 2 0 3 4 5
    1 2 3 0 4 5
    1 2 3 4 0 5
    1 2 3 4 5 0
    
예제 출력 2 

    2

예제 입력 3 

    8
    0 5 4 5 4 5 4 5
    4 0 5 1 2 3 4 5
    9 8 0 1 2 3 1 2
    9 9 9 0 9 9 9 9
    1 1 1 1 0 1 1 1
    8 7 6 5 4 0 3 2
    9 1 9 1 9 1 0 9
    6 5 4 3 2 1 9 0
    
예제 출력 3 

    1

예제 입력 4 

    5
    0 3 1 1 1
    3 0 1 1 1
    1 1 0 1 1
    1 1 1 0 1
    1 1 1 1 0

코드 및 풀이

    #include<iostream>
    #include<vector>
    #include<cmath>

    #define endl "\n"
    #define MAX 20
    using namespace std;

    int N, Answer = 999999;
    int MAP[MAX][MAX];
    bool Select[MAX];

    int Min(int A, int B) { if (A < B) return A; return B; }

    void Input()
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> MAP[i][j];
            }
        }
    }

    int Calculate_Synergy(vector<int> V)
    {
        int Sum = 0;
        for (int i = 0; i < V.size(); i++)
        {
            for (int j = 0; j < V.size(); j++)
            {
                if (i == j) continue;
                Sum = Sum + MAP[V.at(i)][V.at(j)];
            }
        }
        return Sum;
    }

    void Calculate()
    {
        vector<int> Link, Start;

        for (int i = 0; i < N; i++)
        {
            if (Select[i] == true) Link.push_back(i);
            else Start.push_back(i);
        }

        int Synergy_Link = Calculate_Synergy(Link);
        int Synergy_Start = Calculate_Synergy(Start);
        int Diff = abs(Synergy_Link - Synergy_Start);

        Answer = Min(Answer, Diff);
    }

    void Divide_Team(int Index, int Cnt)
    {
        if (Cnt == N / 2)
        {
            Calculate();
            return;
        }

        for (int i = Index; i < N; i++)
        {
            if (Select[i] == true) continue;
            Select[i] = true;
            Divide_Team(i, Cnt + 1);
            Select[i] = false;
        }
    }

    void Solution()
    {
        Divide_Team(0, 0);
        cout << Answer << endl;
    }

    void Solve()
    {
        Input();
        Solution();
    }

    int main(void)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        Solve();

        return 0;
    }


설명 

    1. 이 문제는 가능한 나올 수 있는 모든 팀의 조합을 다 만들어보고 팀의 시너지를 계산해서 최소값을 구하는 문제입니다.

    2. 조합을 만들 때 A팀과 B팀의 순서에 따라서 시너지가 다르지만, 팀의 시너지 = S(a,b) + S(b,a) 이므로 순서는 상관이 없습니다.

    3. 조합을 구현하면서 선택한 사람의 수가 N/2명이 되게하여 선택당한 사람과 선택받지 못한 사람 이렇게 2개의 팀으로 나누고.

    4. 팀을 나눴다면 팀의 시너지를 구하면 됩니다.

       선택당한 사람에 대해서는 Link_Team을 관리하는 Vector에, 반대인 사람에 대해서는 Star_Team을 관리하는 Vector에

       넣어주고, MAP을 이용해서 시너지를 계산하면서, 최소값을 갱신해 주어 .


