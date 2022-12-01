#include <string>
#include <vector>

using namespace std;
typedef struct tree{
    int value;
    tree* left;
    tree* right;
}Node;
int targ = 0;
int as = 0;
void dfs(Node* num, vector<int> array, int index){
    if(index == array.size()){
        if(num->value == targ)
            ++as;}
    else{
        Node* left = new Node();
        Node* right = new Node();
        num-> left = left;
        num-> right = right;
        left->value = num-> value + array[index];
        right->value = num-> value - array[index];
        
        dfs(left, array, index+1);
        dfs(right, array, index+1);
    }
}

int solution(vector<int> numbers, int target) {
    targ = target;
    Node* t = new Node();
    t->value = 0;
    dfs(t, numbers, 0);
    return as;
}
