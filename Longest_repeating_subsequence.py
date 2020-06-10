st="aabb"
n=len(st)
ans=""
dp = [[0 for k in range(n+1)] for l in range(n+1)] 
for i in range(1,n+1):
    for j in range(1,n+1):
        if st[i-1]==st[j-1] and i!=j:
            ans+=st[i-1]
            dp[i][j]=1+dp[i-1][j-1]
        else:
            #ans+=st[i-1]
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])
i=n
j=n
res=""
while(i>0 and j>0):
    if dp[i][j]==dp[i-1][j-1]+1:
        res+=st[i-1]
        i-=1
        j-=1
    elif dp[i][j]==dp[i-1][j]:
        i-=1
    elif dp[i][j]==dp[i][j-1]:
        j-=1
res="".join(reversed(res))
print(res)
