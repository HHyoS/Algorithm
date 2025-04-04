문제 사이트 : https://www.acmicpc.net/problem/17140

문제 설명 :

![image](https://github.com/user-attachments/assets/4bfff5cd-d55a-4d6e-803c-f665ad83e2f0)
![image](https://github.com/user-attachments/assets/b716c2dc-ea0c-4828-a620-4b2b68f32838)
![image](https://github.com/user-attachments/assets/38e909dc-de32-4bbf-85b8-f1393e624c59)

풀이 알고리즘

 TBD 

 
풀이 코드

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <map>
    using namespace std;
    
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int r, c, k;
        cin >> r >> c >> k;
        r--; c--; // 0-index로 변환
        vector<vector<int>> A(3, vector<int>(3));
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cin >> A[i][j];
            }
        }
        
        auto opR = [&]() -> vector<vector<int>> {
            int rows = A.size();
            int cols = A[0].size();
            vector<vector<int>> newA;
            int newCols = 0;
            for (int i = 0; i < rows; i++){
                map<int, int> freq;
                for (int j = 0; j < cols; j++){
                    if(A[i][j] != 0)
                        freq[A[i][j]]++;
                }
                // (숫자, 등장횟수) 쌍을 등장횟수, 숫자 순으로 정렬
                vector<pair<int, int>> vec(freq.begin(), freq.end());
                sort(vec.begin(), vec.end(), [](pair<int,int> a, pair<int,int> b){
                    if(a.second == b.second)
                        return a.first < b.first;
                    return a.second < b.second;
                });
                vector<int> row;
                for(auto &p : vec){
                    row.push_back(p.first);
                    row.push_back(p.second);
                }
                newCols = max(newCols, (int)row.size());
                newA.push_back(row);
            }
            // 모든 행의 길이를 newCols로 맞춤 (최대 100까지)
            newCols = min(newCols, 100);
            for(auto &row : newA){
                if(row.size() < newCols)
                    row.resize(newCols, 0);
                else if(row.size() > newCols)
                    row.resize(newCols);
            }
            return newA;
        };
        
        auto opC = [&]() -> vector<vector<int>> {
            int rows = A.size();
            int cols = A[0].size();
            vector<vector<int>> newMat;
            int newRows = 0;
            // 각 열에 대해 연산을 수행 후 결과를 벡터로 저장
            vector<vector<int>> colVec;
            for (int j = 0; j < cols; j++){
                map<int, int> freq;
                for (int i = 0; i < rows; i++){
                    if(A[i][j] != 0)
                        freq[A[i][j]]++;
                }
                vector<pair<int,int>> vec(freq.begin(), freq.end());
                sort(vec.begin(), vec.end(), [](pair<int,int> a, pair<int,int> b){
                    if(a.second == b.second)
                        return a.first < b.first;
                    return a.second < b.second;
                });
                vector<int> col;
                for(auto &p : vec){
                    col.push_back(p.first);
                    col.push_back(p.second);
                }
                newRows = max(newRows, (int)col.size());
                colVec.push_back(col);
            }
            newRows = min(newRows, 100);
            // 각 열을 newRows 길이로 맞추기
            for(auto &col : colVec){
                if(col.size() < newRows)
                    col.resize(newRows, 0);
                else if(col.size() > newRows)
                    col.resize(newRows);
            }
            // 전치: 각 열 벡터를 행렬로 변환
            newMat.assign(newRows, vector<int>(colVec.size(), 0));
            for (int j = 0; j < colVec.size(); j++){
                for (int i = 0; i < newRows; i++){
                    newMat[i][j] = colVec[j][i];
                }
            }
            return newMat;
        };
        
        int time = 0;
        while (time <= 100) {
            if(r < A.size() && c < A[0].size() && A[r][c] == k){
                cout << time << "\n";
                return 0;
            }
            if(A.size() >= A[0].size()){
                A = opR();
            } else {
                A = opC();
            }
            time++;
        }
        cout << -1 << "\n";
        return 0;
    }


풀이 후기

![image](https://github.com/user-attachments/assets/c158df42-07e9-4833-83d5-df991ab1e43f)
