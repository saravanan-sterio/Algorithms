a=list(map(int,input().split()))
k=int(input())
count=0
for i in a:
    ele=i
    count1=0
    count2=0
    while ele%k!=0 and ele!=0:
        count1+=1
        ele-=1
    ele=i
    while ele%k!=0:
        count2+=1
        ele+=1
    count+=min(count1,count2)
print(count)
