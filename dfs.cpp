#include<stdio.h>
int adj[100][100];
int vis[100];
int n;

void dfs(int v)
{
	vis[v]=1;
	printf("%d ",v);
	for(int i=0;i<n;i++)
	{
		if(adj[v][i]==1 && vis[i]==0)
			dfs(i);
	}
}

int main()
{
	printf("DEPTH FIRST TRAVERSAL\n");
	printf("Enter Number Of Vertices : ");
	scanf("%d",&n);
	int ch=1,v1,v2;
	while(ch)
	{
		printf("Enter vertex 1 and vertex 2 : ");
		scanf("%d %d",&v1,&v2);
		adj[v1][v2]=1;
		printf("Enter 1 to continue : ");
		scanf("%d",&ch);
	}
	for(int i=0;i<n;i++)
		if(vis[i]==0)
			dfs(i);
}
