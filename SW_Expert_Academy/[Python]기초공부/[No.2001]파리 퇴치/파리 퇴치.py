# 문제 사이트 : https://swexpertacademy.com/main/code/problem/problemDetail.do

T = int(input())

for i in range(1, T + 1):
    N, M = map(int, input().split())
    arr = [[0 for a in range(N)] for b in range(N)]

    for j in range(N):
        arr[j] = list(map(int, input().split()))

    answer = 0
    for a in range(N - M + 1):
        for b in range(N - M + 1):
            temp = 0
            for c in range(M):
                for d in range(M):
                    temp += arr[c + a][d + b]

            if answer < temp:
                answer = temp

    print('#' + str(i) + ' ' + str(answer))
