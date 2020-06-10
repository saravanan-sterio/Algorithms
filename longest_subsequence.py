l=["abc","abg","bdf","aeg","acefg"]
temp=[]
for i in l:
    for j in i:
        if j not in temp:
            temp.append(j)
s=""
temp.sort()
for i in temp:
    s+=i
print(s)
