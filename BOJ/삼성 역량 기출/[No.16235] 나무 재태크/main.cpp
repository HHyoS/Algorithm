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
