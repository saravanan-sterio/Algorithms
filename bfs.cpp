#include<stdio.h>
int adj[100][100],vis[100],queue[100],front=-1,rear=-1,n;

void enque(int v)
{
	if(front==rear)
		front=rear=0;
	else
		rear++;
	queue[rear]=v;
}

int deque()
{
	int k=queue[front];
	if(front==0)
		front=-1;
	else
		front++;
	return k;
}

void bfs(int v)
{
	vis[v]=1;
	printf("%d ",v);
	enque(v);
	while(front!=-1)
	{
		int k=deque();
		for(int i=0;i<n;i++)
		{
			if(adj[k][i]==1 && vis[i]==0)
			{
				enque(i);
				printf("%d ",i);
				vis[i]=1;
			}
		}
	}
}

int main()
{
	printf("BREADTH FIRST TRAVERSAL\n");
	printf("Enter Number Of Vertices : ");
	scanf("%d",&n);
	int ch=1,v1,v2;
	while(ch)
	{
		printf("Enter Vertex 1 and Vertex 2 : ");
		scanf("%d%d",&v1,&v2);
		adj[v1][v2]=1;
		printf("Enter 1 to continue : ");
		scanf("%d",&ch);
	}
	for(int i=0;i<n;i++)
		if(vis[i]==0)
			bfs(i);
}
