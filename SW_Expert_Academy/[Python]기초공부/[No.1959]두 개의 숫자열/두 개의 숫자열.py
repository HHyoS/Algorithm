T = int(input())

for i in range(1, T + 1):
    N, M = map(int, input().split())
    arr1 = []
    arr2 = []
    if (M > N):
        temp = N
        N = M
        M = temp
        arr2 = list(map(int, input().split()))
        arr1 = list(map(int, input().split()))
    else:
        arr1 = list(map(int, input().split()))
        arr2 = list(map(int, input().split()))

    answer = 0
    for a in range(M):
        answer += (arr1[a] * arr2[a])

    for a in range(1, N - M + 1):
        temp = 0
        for b in range(M):
            temp += (arr1[a + b] * arr2[b])
        if (answer < temp):
            answer = temp
    print('#' + str(i) + ' ' + str(answer))
