import math
n,k=map(int,input().split())
factor=[]
while n%2==0:
    factor.append(2)
    n=n//2

for i in range(3,int(math.sqrt(n))+1,2):
    while n%i==0:
        factor.append(i)
        n=n//i
if len(factor)<k:
    print(-1)
else:
    print(factor[k-1])
