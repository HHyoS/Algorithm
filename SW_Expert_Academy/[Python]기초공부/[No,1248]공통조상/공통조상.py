# 광주_6반_0810051_황효상
# 문제번호 1248 공통조상
from collections import deque

T = int(input())

for i in range(1, T + 1):

    child = [[] for _ in range(10001)]
    parent = [0 for _ in range(10001)]
    V, E, n1, n2 = map(int, input().split())

    temp = list(map(int, input().split()))
    for a in range(0, len(temp), 2):
        child[temp[a]].append(temp[a + 1])
        parent[temp[a + 1]] = temp[a]

    n1_parent = []
    n2_parent = []
    c = n1
    while (1):
        n1_parent.append(parent[c])
        c = parent[c]
        if c == 1:
            n1_parent.append(1)
            break

    c = n2
    while (1):
        n2_parent.append(parent[c])
        c = parent[c]
        if c == 1:
            n2_parent.append(1)
            break

    idx_1 = len(n1_parent) - 1
    idx_2 = len(n2_parent) - 1
    common_node = 1
    while (idx_1 >= 0 and idx_2 >= 0):
        if n1_parent[idx_1] != n2_parent[idx_2]:
            common_node = n1_parent[idx_1 + 1]
            break
        idx_1 -= 1
        idx_2 -= 1
    queue = deque()
    queue.append(common_node)

    answer = 1
    while (len(queue) != 0):
        size = len(queue)
        for a in range(size):
            num = queue.popleft()
            for b in child[num]:
                queue.append(b)
                answer += 1
    print('#' + str(i) + ' ' + str(common_node) + ' ' + str(answer))
