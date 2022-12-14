문제 사이트 : https://www.acmicpc.net/problem/2529

설명

    두 종류의 부등호 기호 ‘<’와 ‘>’가 k개 나열된 순서열  A가 있다. 
    
    우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다. 
    
    예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자. 

    A =>  < < < > < < > < >

    부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 
    
    아래는 부등호 순서열 A를 만족시키는 한 예이다. 

    3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

    이 상황에서 부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 
    
    이 수를 주어진 부등호 관계를 만족시키는 정수라고 한다. 
    
    그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 
    
    예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다. 

    5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

    여러분은 제시된 k개의 부등호 순서를 만족하는 (k+1)자리의 정수 중에서 최댓값과 최솟값을 찾아야 한다. 
    
    앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }중에서 선택해야 하며 선택된 숫자는 모두 달라야 한다. 



풀이

     주어진 부등호 순서에 맞는 숫자들중 최대값과 최소값을 구하는 문제입니다.

     위 문제를 해결하기 위해 사용한 풀이 순서는 

        1. 조건에 맞는 숫자 순서 찾기

        2. 조건에 맞는 숫자 발견 시 현재까지 발견한 최대값과 최소값과 비교하여 최대,최소값 갱신하기

        3. 정답 출력 입니다.


    첫번째로 (1)을 수행하기 위해 입력받은 부등호를 저장하는 배열 arr, dfs방식을 통해 사용한 숫자를 체크하는

    배열 check, 사용한 숫자들을 저장한 배열 ar을 선언하고 dfs 탐색을 통해 조건에 맞는 숫자 조합을 완성시킵니다.

    두번째로 (2)를 수행하기 위해 완성된 ar배열을 atoll 함수를 이용하여 최대,최소값과 비교하고 갱신 가능한 대상일 경우

    해당값들을 저장합니다.

    세번째로 (3)를 수행하기 위해 출력을 하면되는데, 위 문제에서 앞자리에 0이 들어간 경우 해당 숫자도 출력하도록

    되어있습니다.

    그러므로 주어진 값에서 앞자리가 0이 아닐때 나와야 할 자리수를 계산하고, 해당 자리수보다 최대,최소값이 자리수가 적을경우

    부족한만큼 ' 0  ' 을 미리 출력하여 준비하고 값을 출력하여 답을 출력시켰습니다.



코드

    #include <cstdio>
    #include <cmath>
    #include <cstring>
    #include <string>
    using namespace std;


    int k;
    char ar[10] = "         "; // 사용한 숫자 나열하는 배열
    char arr[10] = { "", }; // 입력받은 부등호 저장 배열
    bool check[10] = { 0, }; // 사용한 숫자 체크
    long long big = -1; // 최대값
    long long sm = -1; // 최소값

    void ch(long long n) { //  big과 sm 에서 자리수가 부족할 경우 앞에 0을 채워주는 함수
        long long temp = n; 
        int count = 0; // 자리수를 저장하는 변수
        while (temp > 0) {
            count++;
            temp /= 10; 
        }
        if (count == k + 1) //  입력받은 부등호의 갯수 k보다 자리수는 1이 많아야함.
            printf("%lld", n); // if문을 만족할 경우 그냥 출력
        else { // 자리수가 부족할 경우 
            int c = k + 1 - count; // 앞에 출력해야 할 0 갯수 
            for (int a = 0; a < c; ++a) {
                printf("0"); // 0 출력
            }
            printf("%lld", n);
        }
    }
    void dfs(int index) {
        if (k == index) {
            long long t = atoll(ar);
            if (big == -1 || big < t)
                big = t;
            if (sm == -1 || sm > t)
                sm = t;

            return;
        }
        for (int a = 0; a < 10; ++a) {
            if (!check[a]) {
                if ((arr[index] == '>') && (ar[index] > a + '0')) {
                    check[a] = 1;
                    ar[index+1] = a + '0';
                    dfs(index + 1);
                    check[a] = 0;
                }
                else if((arr[index] == '<') && (ar[index] < a + '0')) {
                    check[a] = 1;
                    ar[index+1] = a + '0';
                    dfs(index + 1);
                    check[a] = 0;
                }
            }
        }
    }
    int main() {
        scanf("%d", &k);
        for (int a = 0; a < k; ++a) {
            scanf(" %c", &arr[a]);
        }
        for (int a = 0; a < 10; ++a) {
            ar[0] = a + '0'; // int를 char로 입력
            check[a] = 1;
            dfs(0);
            check[a] = 0;
        }
        ch(big);
        printf("\n");
        ch(sm);
        return 0;
    }

