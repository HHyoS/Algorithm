from collections import deque


for a in range(1,11) :
    N,node = map(int,input().split())

    grp = [[] for _ in range(101)]
    temp = list(map(int, input().split()))
    for b in range(0,N,2):
        grp[temp[b]].append(temp[b+1])

    queue = deque()
    check = [0 for _ in range(101)]
    queue.append(node)
    check[node] = 1
    answer = 0

    while len(queue) != 0 :
        ans = -1
        size = len(queue)
        for _ in range(size) :
            num = queue.popleft()
            for b in grp[num] :
                if check[b] == 0 :
                    queue.append(b)
                    check[b] = 1
                    if  b > ans :
                        ans = b
            if ans != -1 :
                answer = ans

    print('#'+str(a)+' '+ str(answer))





