from typing import List


h = []
def maximalRectangle(self, matrix: List[List[str]]) -> int:
    n = len(List)
    m = len(List[0])
    h = []
    for i in range (1,n):
        for i in range(1,m):
            h[i] = h[i]*List[i][j]+List[i][j]
    S = [len(List)]
    l = [len(List)]
    S[1]=1
    l[1]=1
    top = 1
    kq = 0 
    for i in range (2,m):
        while top > 0 and h[i] <= h[S[top]]:
            top = top - 1
        if top == 0: 
            l[i]=1
        else: 
            l[i]=S[top]+1
        top = top + 1
        S[top] = i
    
    S[1] = m 
    r = [len(List)]
    r[m] = m 
    for i in range (m-1,1,-1):
        while top > 0 and h[i] <= h[S[top]]:
            top = top - 1
        if top == 0 : 
            r[i] = m 
        else:
            r[i] = S[top]-1
        top= top + 1 
        S[top]=i
    for i in range (1,m):
        kq = max (kq,h[i]*( r[i] - l[i] + 1))
    return kq 

