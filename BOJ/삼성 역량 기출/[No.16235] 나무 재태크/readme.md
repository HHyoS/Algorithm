# 문제 사이트
https://www.acmicpc.net/problem/16235

# 문제 설명
![image](https://github.com/user-attachments/assets/8547579f-0ab2-46b9-aa43-1233b91342e3)
![image](https://github.com/user-attachments/assets/4a78e4c3-4953-4e62-918f-d250d824ee1c)
![image](https://github.com/user-attachments/assets/e84e10c4-1009-41ce-a49c-51101cd41df6)

# 풀이 알고리즘

## 문제 정리

### 입력 및 초기화
- 격자 크기 N, 나무 수 M, 년수 K
- A[r][c] : 겨울에 추가되는 영양분 배열
- food[r][c] : 현재 칸에 있는 양분 양, 초기에는 모두 5로 세팅
- trees : 살아 있는 모든 나무를 담는 자료구조(벡터 등), 각 원소는 (x,y,age)

### 초기 나무 정렬
- 봄에 "나이 어린 순서대로 양분 먹기”를 보장하기 위해, 매년 봄 직전에 각 칸 내 나무를 나이 순으로 처리해야 함.
-  여러 구현 방식이 있지만, 코드에서는 trees 벡터 전체를 “나이 오름차순”으로 유지하여 봄에 순차적으로 처리하면서 자연스럽게 같은 칸 내 나이 어린 나무부터 방문되도록 함.
-  초기에 입력받은 나무들을 나이 기준으로 정렬해 둠.

### 연도 별 반복 (year = 1...K)
1) 봄 + 여름 처리 ( spring_summer() )
- 같은 칸에 여러 나무가 있을 때, 나이 어린 순서대로 양분 먹고, 먹지 못하면 죽는 과정을 구현.
- 또한 죽은 나무들이 여름에 칸에 양분으로 환원되는 처리를 함께 묶어 효율적으로 수행.

2) 가을 처리 ( autumn() )
- 살아남은 나무들 중 번식 자격(나이 % 5 == 0)인 나무를 찾아, 주변 8칸에 나이=1인 나무를 새로 추가.
- 추가된 나무를 trees 자료구조에 합쳐야 하는데, “나이 어린 순서”를 유지해야 하므로 삽입 위치에 주의.

3) 겨울 처리 ( winter() )
- food[r][c] += A[r][c]

4) 결과 출력
- trees.size() 출력


# 풀이 코드

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Tree { int x, y, age; };

int N, M, K;
int A[11][11], food[11][11];
vector<Tree> trees;
int dx[8]={-1,-1,-1,0,0,1,1,1}, dy[8]={-1,0,1,-1,1,-1,0,1};

void spring_summer(){
    int add[11][11] = {0};
    vector<Tree> alive;
    for(auto &t : trees){
        if(food[t.x][t.y] >= t.age){
            food[t.x][t.y] -= t.age;
            t.age++;
            alive.push_back(t);
        } else {
            add[t.x][t.y] += t.age / 2;
        }
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            food[i][j] += add[i][j];
    trees.swap(alive);
}

void autumn(){
    vector<Tree> newborn;
    for(auto &t : trees){
        if(t.age % 5 == 0){
            for(int d=0; d<8; d++){
                int nx = t.x + dx[d], ny = t.y + dy[d];
                if(nx>=1 && nx<=N && ny>=1 && ny<=N)
                    newborn.push_back({nx, ny, 1});
            }
        }
    }
    // 새로 태어난 나무를 앞쪽에 넣어서 나이순(젊은 순)이 유지됨
    trees.insert(trees.begin(), newborn.begin(), newborn.end());
}

void winter(){
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            food[i][j] += A[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M>>K;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            cin>>A[i][j];
            food[i][j] = 5;
        }
    for(int i=0;i<M;i++){
        int x,y,z;
        cin>>x>>y>>z;
        trees.push_back({x,y,z});
    }

    // 처음에는 나이순 정렬
    sort(trees.begin(), trees.end(), [](auto &a, auto &b){
        return a.age < b.age;
    });

    while(K--){
        spring_summer();
        autumn();
        winter();
    }
    cout << trees.size() << "\n";
    return 0;
}
```

# 풀이 후기
![image](https://github.com/user-attachments/assets/ce9c93dc-7f68-4500-849b-78348418a101)
