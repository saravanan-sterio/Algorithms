from sys import maxsize 
INT_MAX = maxsize 
def isValidEdge(u, v, inMST): 
    if u == v: 
        return False
    if inMST[u] == False and inMST[v] == False: 
        return False
    elif inMST[u] == True and inMST[v] == True: 
        return False
    return True
  
def primMST(cost): 
    inMST = [False] * V 
    inMST[0] = True
    edge_count = 0
    mincost = 0
    while edge_count < V - 1: 
        minn = INT_MAX 
        a = -1
        b = -1
        for i in range(V): 
            for j in range(V): 
                if cost[i][j] < minn: 
                    if isValidEdge(i, j, inMST): 
                        minn = cost[i][j] 
                        a = i 
                        b = j 
  
        if a != -1 and b != -1: 
            print("Edge %d: (%d, %d) cost: %d" % 
                 (edge_count, a, b, minn)) 
            edge_count += 1
            mincost += minn 
            inMST[b] = inMST[a] = True
  
    print("Minimum cost = %d" % mincost) 
cost = list()
new=list()
V=int(input("Enter the no.of vertices"))
for i in range(0,V):
      for j in range(0,V):
            g=int(input())
            new.append(g)
      cost.append(new)
      new=list()

primMST(cost) 

