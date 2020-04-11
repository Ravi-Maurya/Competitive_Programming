import math
from sys import stdin
mod=(10**9)+7
def calculate(path,a):
    dic={}
    for i in range(len(path)):
        dic=primeFactors(a[path[i]-1],dic)
    value=list(dic.values())
    ans=1
    for i in range(len(value)):
        ans*=(value[i]+1)
        ans=ans%mod
    print(ans)

def primeFactors(n,dic):
    while n % 2 == 0:
        if 2 not in dic:
            dic[2]=1
        else:
            dic[2]+=1
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            if i not in dic:
                dic[i]=1
            else:
                dic[i]+=1 
            n = n / i
    if n > 2: 
        if n not in dic:
            dic[n]=1
        else:
            dic[n]+=1 
    return dic
def addEdge(x, y,v):
    v[x].append(y) 
    v[y].append(x)  
def dfs(vis, x, y, stack,v,ansflag,a):
    stack.append(x) 
    if (x == y):
        ansflag=1
        calculate(stack,a)
        return 
    vis[x] = True
    flag = 0
    if (len(v[x]) > 0): 
        for j in v[x]: 
            if (vis[j] == False): 
                dfs(vis, j, y, stack,v,ansflag,a) 
                if(ansflag==1):
                    flag = 1  
                    break
    if (flag == 0): 
        del stack[-1] 
    return 
def dfsUtil(x, y, n, stack,v,a):
    ansflag=0
    vis = [0 for i in range(n + 1)] 
    if(x!=y):
        dfs(vis, x, y, stack,v,ansflag,a)
    else:
        x1=[x]
        calculate(x1,a)
    return
for _ in range(int(input())):
    n = int(input())
    v = [[] for i in range(n+1)]
    for i in range(n-1):
        a1,b=map(int,stdin.readline().split())
        addEdge(a1,b,v) 
    a=list(map(int,stdin.readline().split()))
    q=int(input())
    for i in range(q):
        x,y=map(int,stdin.readline().split())
        stack = []
        dfsUtil(x,y,n,stack,v,a)