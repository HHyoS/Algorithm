문제 사이트 : https://www.acmicpc.net/problem/11656

문제 설명 :

    접미사 배열은 문자열 S의 모든 접미사를 사전순으로 정렬해 놓은 배열이다.

    baekjoon의 접미사는 baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n 으로 총 8가지가 있고,
    
    이를 사전순으로 정렬하면, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon이 된다.

    문자열 S가 주어졌을 때, 모든 접미사를 사전순으로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력

    첫째 줄에 문자열 S가 주어진다. 
    
    S는 알파벳 소문자로만 이루어져 있고,
    
    길이는 1,000보다 작거나 같다.

출력

    첫째 줄부터 S의 접미사를 사전순으로 한 줄에 하나씩 출력한다.

예제 입력 1 

    baekjoon

예제 출력 1 

    aekjoon
    baekjoon
    ekjoon
    joon
    kjoon
    n
    on
    oon
    
[ 풀이 알고리즘 ]

    첫번쨰 줄에 단어 S가 주어질 때, S의 접미사를 사전순으로 출력하는 문제였습니다.
    
    단어 S의 길이를 L(S)라고 했을 떄, S의 접미사의 갯수와 L(S)의 값은 같고, 
    
     S의 길이는 1 ~ 1000 이므로 1 <= L(S) <= 1000이 값이 되게됩니다,
     
     그래서 저는 string 타입의 배열 temp를 선언하여 길이가 1000인 배열로 만들었고
     
     해당 배열에 S의 접미사를 모두 저장한 뒤 sort함수를 이용하여 정렬하고 그 순서대로 출력하도록
     
     하여 문제를 해결하였습니다.
     
 [ 구 현 ]
 
    #include<iostream>
    #include<algorithm>
    using namespace std;

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string str;
        string temp[1000];
        cin >> str;
        int l = str.length();
        for(int a=0; a<l; ++a){
            temp[a] = str.substr(a, l); 
        }
        sort(temp, temp+l); //오름차순 
        for(int a=0; a<l; ++a){
            cout << temp[a] << endl;
        }

        return 0;
    }
