#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int command  = 0;
    int num = 1;
    vector<vector<int>> arr;
    int x=0, y = 0;
    for(int a = 1; a <= n; ++a){
        vector<int> temp;
        temp.assign(a,0);
        arr.push_back(temp);
    }
        
    while(true){
        switch(command){
            case 0 :
                arr[y][x] = num++;
                if(y+1 >= n ){
                    command = 1;
                    x++;
                }
                else if(!(arr[y+1][x] == 0)){
                    command = 1;
                    x++;
                }
                else{
                    y++;
                }
                break;
            case 1 :
                arr[y][x] = num++;
                if(x+1 >= n){
                    command = 2;
                    --y; 
                    --x;
                }
                else if(!(arr[y][x+1] == 0)){
                    command = 2;
                    --y; 
                    --x;
                }
                else{
                    x++;
                }
                break;
            case 2 :
                arr[y][x] = num++;
                if(arr[y-1][x-1] != 0){
                    command = 0;
                    y++;
                }
                else{
                    --x;
                    --y;
                }
                break; 
        }
        if(arr[y][x] != 0)
            break;
    }
    for(int a = 0; a < n; ++a){
        for(int b = 0; b < arr[a].size(); ++b){
            answer.push_back(arr[a][b]);
        }
    }
    return answer;
}
