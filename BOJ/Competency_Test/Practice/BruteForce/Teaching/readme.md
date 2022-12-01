문제 사이트 : https://www.acmicpc.net/workbook/view/3940

문제 설명 :

    남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를 읽을 수 있도록 하려고 한다.
    
    그러나 지구온난화로 인해 얼음이 녹아서 곧 학교가 무너지기 때문에, 김지민은 K개의 글자를 가르칠 시간 밖에 없다. 
    
    김지민이 가르치고 난 후에는, 학생들은 그 K개의 글자로만 이루어진 단어만을 읽을 수 있다. 
    
    김지민은 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.

    남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다. 남극언어에 단어는 N개 밖에 없다고 가정한다. 
    
    학생들이 읽을 수 있는 단어의 최댓값을 구하는 프로그램을 작성하시오.

입력

    첫째 줄에 단어의 개수 N과 K가 주어진다. N은 50보다 작거나 같은 자연수이고, K는 26보다 작거나 같은 자연수 또는 0이다. 
    
    둘째 줄부터 N개의 줄에 남극 언어의 단어가 주어진다. 
    
    단어는 영어 소문자로만 이루어져 있고, 길이가 8보다 크거나 같고, 15보다 작거나 같다. 모든 단어는 중복되지 않는다.

출력

    첫째 줄에 김지민이 K개의 글자를 가르칠 때, 학생들이 읽을 수 있는 단어 개수의 최댓값을 출력한다.

예제 입력 1 

    3 6
    antarctica
    antahellotica
    antacartica

예제 출력 1 

    2

예제 입력 2 

    2 3
    antaxxxxxxxtica
    antarctica

예제 출력 2 

    0

예제 입력 3 

    9 8
    antabtica
    antaxtica
    antadtica
    antaetica
    antaftica
    antagtica
    antahtica
    antajtica
    antaktica

예제 출력 3 

    3

코드 및 설명 :

    #include<iostream>
    #include<string>
    #include<vector>
    #include<cstring>

    #define endl "\n"
    using namespace std;

    int N, K, Answer;
    bool Alphabet[26];
    vector<string> V;

    int Bigger(int A, int B) { if (A > B) return A; return B; }

    void Input()
    {
        // a n t i c 가 무조건 들어가
        cin >> N >> K;
        for (int i = 0; i < N; i++)
        {
            string Inp; cin >> Inp;
            V.push_back(Inp);
        }

        if (K < 5)
        {
            cout << 0 << endl;
            exit(0);
        }
    }

    int CanReadNum()
    {
        bool Read;
        int Cnt = 0;
        for (int i = 0; i < V.size(); i++)
        {
            Read = true;
            string str = V[i];
            for (int j = 0; j < str.length(); j++)
            {
                if (Alphabet[str[j] - 'a'] == false)
                {
                    Read = false;
                    break;
                }
            }

            if (Read == true)
            {
                Cnt++;
            }
        }
        return Cnt;
    }

    void DFS(int Idx, int Cnt)
    {
        if (Cnt == K)
        {
            Answer = Bigger(Answer, CanReadNum());
            return;
        }

        for (int i = Idx; i < 26; i++)
        {
            if (Alphabet[i] == true) continue;
            Alphabet[i] = true;
            DFS(i, Cnt + 1);
            Alphabet[i] = false;
        }
    }

    void Solution()
    {
        Alphabet['a' - 'a'] = true;
        Alphabet['n' - 'a'] = true;
        Alphabet['t' - 'a'] = true;
        Alphabet['i' - 'a'] = true;
        Alphabet['c' - 'a'] = true;
        K = K - 5;

        DFS(0, 0);
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

        //freopen("Input.txt", "r", stdin);
        Solve();

        return 0;
    }


