from itertools import permutations as p
from itertools import combinations_with_replacement as c
def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

n=int(input())
l=[]
for i in range(1,n+1):
    l.append(i)
com2=[]
com=c(l,2)
com1=p(l,2)
count=0
for i in com:
    com2.append(i)
for i in com1:
    if i not in com:
        com2.append(i)
for i in com2:
    if i[0]==i[1] or gcd(i[0],i[1])==i[1]:
        count+=1
print(count)
