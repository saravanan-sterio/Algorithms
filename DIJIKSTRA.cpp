#include<bits/stdc++.h>
using namespace std;
int n,adj[100][100];

void printsolution(int d[])
{
	for(int i=0;i<n;i++)
		cout<<i<<" "<<d[i]<<endl;
}

int mindis(int d[],int set[])
{
	int m=INT_MAX,mi;
	for(int i=0;i<n;i++)
		if(set[i]==0 && d[i]<m)
		{
			m=d[i];
			mi=i;
		}
	return mi;
}

void dijikstras(int source)
{
	int dist[n],set[n];
	for(int i=0;i<n;i++)
		dist[i]=INT_MAX,set[i]=0;
	dist[source]=0;
	for(int i=0;i<n-1;i++)
	{
		int u=mindis(dist,set);
		set[u]=1;
		for(int j=0;j<n;j++)
		{
			if(!set[j] && adj[u][j] && dist[u]!=INT_MAX && dist[u]+adj[u][j]<dist[j])
				dist[j]=dist[u]+adj[u][j];
		}
	}
	printsolution(dist);
}

int main()
{
	cout<<"DIJIKSTRA'S ALGORITHM "<<endl;
	cout<<"Enter Number Of Vertices : ";
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>adj[i][j];
	cout<<"Enter Source : ";
	int source;
	cin>>source;
	dijikstras(source);
}
