#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool isPrime(int n) {
    if(n<=1) 
        return false;

    for(int i=2; i*i<= n; ++i) {
        if((n%i)==0) {
            return false;
        }
    }
    return true;
}

bool canMake(int target, string b){
    vector<char> array;
    string ta = to_string(target);

    for(int a = 0; a < b.length(); ++a)
        array.push_back(b.at(a));

    for(int c = 0; c < ta.length(); ++c){
        if(find(array.begin(),array.end(),ta[c]) != array.end()){
            if(c == ta.length()-1){
                return true;}
            else
                array.erase(find(array.begin(),array.end(),ta[c]));
        }
        else
             return false;
    }
    }
int solution(string numbers) {
    int answer = 0;
    vector<int> prim;
    vector<char> st;
    string tset = "";
    int sset = 0;
    for(int a = 0; a < numbers.length(); ++a){
        st.push_back(numbers.at(a));}

    sort(st.begin(), st.end(), greater<char>());

    for(char t :st)
        tset = tset + t;


    for(int d = 1; d <= atoi(tset.c_str()); ++d){
        if(isPrime(d))
            prim.push_back(d);}

    for(int p : prim){
        if(canMake(p, numbers))
            ++answer;
    }
    return answer;
}
