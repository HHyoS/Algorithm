문제 사이트 : https://swexpertacademy.com/main/code/problem/problemDetail.do
    
def turn_array(t_set):
    leng = len(t_set)
    arr2 = [[0 for _ in range(leng)] for _ in range(leng)]
    for i in range(leng):
        for j in range(leng):
            arr2[i][j] = t_set[leng - 1 - j][i]

    return arr2


T = int(input())

for i in range(1, T + 1):
    N = int(input())
    arr = [[0 for _ in range(N)] for _ in range(N)]
    for a in range(N):
        arr[a] = list(map(int, input().split()))

    arr_90 = turn_array(arr)

    arr_180 = turn_array(arr_90)

    arr_270 = turn_array(arr_180)

    print('#' + str(i))
    for a in range(N):
        for b in range(N):
            print(arr_90[a][b], end='')

        print(end=' ')

        for b in range(N):
            print(arr_180[a][b], end='')

        print(end=' ')

        for b in range(N):
            print(arr_270[a][b], end='')

        print()
