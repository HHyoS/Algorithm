#include <string>
#include <vector>
#include <iostream>

int mini = 99;
using namespace std;
void dfs(bool arr[],int index,int count,int size,int lest){
    bool ar[size];
    if(index == -1)
        index = size-1;
    else if(index == size)
        index = 0;

    for(int a = 0; a < size; ++a){
        ar[a] = arr[a];
    }

    ar[index] = false;
    ++count;
    if(count > size)
        return;
    for(int a = 0; a < size; ++a){
        if(ar[a] ==true)
            break;
        else{
            if(a == size-1){
                if(mini > count){
                    mini = count;
                    return;
            }
        }
    }
    }
    dfs(ar, index-1, count, size, lest);
    dfs(ar, index+1, count, size, lest);
}
int solution(string name) {
    int answer = 0;
    string al = "A";
    vector<int> ar;
    vector<int> array;
    int sum = 0;
    bool arrr[name.length()];
    int ttrue = 0;
    for(int a = 0; a < name.length()-1; ++a)
        al +="A";

    for(int a = 0; a < name.length(); ++a){
        if(al.at(a) == name.at(a)){
            ar.push_back(0);
            arrr[a] = false;
        }
        else{
            if(a > 0)
                ++ttrue;
            arrr[a]= true;
            int count = 0;
            int temp = 90 - int(name.at(a));
            char comp = al.at(a);
            if(temp < 12){
                while(comp != name.at(a)){
                    comp -= 1;
                    if(comp < 'A')
                        comp = 'Z';
                    ++count;                    
                }
                ar.push_back(count);
                sum += count;
            }
            else{
                while(comp != name.at(a)){
                    comp+= 1;
                    if(comp > 'Z')
                        comp = 'A';
                    ++count;
                }
                ar.push_back(count);
                sum += count;
            }
        }
    }
    dfs(arrr, 0,-1, name.length(), ttrue);
    return mini+sum ;


}
