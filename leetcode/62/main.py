a = [[n,n*1,n*2] for n in range(1,4)]
b = list("Kteam")

a = [1,2,'a','b','c',[3,4]]
b = a[2:len(a)]

a = [[1,2,3],[4,5,6]]
n , m = 3, 4
a = [[1 for i in range(n) ] for j in range(m)]
print(a)

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        ans = [[0 for i in range(m)] for j in range(n)]
        
        for i in range(1,n):
            for j in range(1,m):
                ans[i][j]= ans[i-1][j]+ans[i][j-1]
        return ans[n-1][m-1]


 