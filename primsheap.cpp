#include<bits/stdc++.h>
using namespace std;
int parent[1000],n;
int find(int i)
{
	if(parent[i])
		i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
int main()
{
	cout<<"PRIMS ALGORITHM USING MIN HEAP "<<endl;
	cout<<"Enter number of vertices   : ";
	cin>>n;
	int i,j,cost[n][n];
	priority_queue<int , vector<int> , greater<int> >pq;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=9999;
			else
				pq.push(cost[i][j]);
		}
		int ne=1,min,total_cost=0,a,b;
	while(ne<n)
	{
		int ele=pq.top();
		pq.pop();
		pq.pop();
		cout<<ele<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(cost[i][j]==ele)
				{
					a=i;
					b=j;
				}
			}
		}
		int u=find(a);
		int v=find(b);
		if(uni(u,v))
		{
			printf("%d to %d is %d\n",a,b,ele);
			total_cost+=ele;
			ne++;
		}
		cost[a][b]=cost[b][a]=9999;
		
		
	}
	printf("Total cost : %d\n",total_cost);
		
}
