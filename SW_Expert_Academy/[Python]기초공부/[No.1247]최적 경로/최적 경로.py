
def dfs(count,idx,tot) :
    global ans
    if count == N :
        to_home = tot+abs(home[0]-arr[idx][0])+abs(home[1]-arr[idx][1])
        if to_home < ans :
            ans = to_home
        return
    else :
        for a in range(N) :
            if check[a] == 0 :
                tt = tot + abs(arr[a][0]-arr[idx][0])+abs(arr[a][1]-arr[idx][1])
                if tt < ans :
                    check[a] = 1
                    dfs(count+1,a,tt)
                    check[a] = 0


T = int(input())

for i in range(1,T+1) :

    arr = []

    N = int(input())
    temp = list(map(int,input().split()))

    leng = len(temp)
    office = (temp[0],temp[1])
    home = (temp[2],temp[3])
    ans = 20000000
    check = [0 for _ in range(N)]

    for j in range(4,len(temp),2) :
        arr.append((temp[j],temp[j+1]))

    for j in range(N) :
        check[j] = 1
        dfs(1,j,abs(office[0]-arr[j][0])+abs(office[1]-arr[j][1]))
        check[j] = 0

    print('#'+str(i)+' '+str(ans))
