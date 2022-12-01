문제 사이트 : https://swexpertacademy.com/main/code/problem/problemDetail.do
    

def col(arr) :
    for a in range(9):
        check = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        for b in range(9):
            if check[arr[b][a]] == 0:
                check[arr[b][a]] = 1
            else:
                return 0

    return 1

def three_three(arr) :
    for a in range(0, 9, 3):
        for b in range(0, 9, 3):
            check = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
            for c in range(3):
                for d in range(3):
                    if check[arr[a + c][b + d]] == 0:
                        check[arr[a + c][b + d]] = 1
                    else:
                        return 0
    return 1


T = int(input())

for i in range(1 , T +1) :
    arr = [[0 for _ in range(9)] for _ in range(9)]

    answer = 1
    for j in range(9) :
        arr[j] = list(map(int ,input().split()))
        check = [0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0]
        for k in range(9) :
            if check[arr[j][k]] == 0 :
                check[arr[j][k]] = 1
            else :
                answer = 0
    if answer == 1 :
        answer = col(arr)
    if answer == 1:
        answer = three_three(arr)

    print('#' +str(i) +' '+str(answer))
