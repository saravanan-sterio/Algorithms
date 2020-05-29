  
#include<stdio.h>
int parent[20]={0};
int n;
int cost[20][20]={0};
int find(int k){
	while(parent[k])
		k=parent[k];
	return k;
}
int unions(int k,int l){
	if(k!=l){
		parent[l]=k;
		return 1;
	}
	return 0;
}
void kruskals(){
	int mincost=0,edges=1,i,j,a,b,u,v;
	printf("Enter the cost as matrix:\n");
	int cost[n+1][n+1];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if((cost[i][j]==0)||(i==j)){//if self loop or no edge it is given as 999
				cost[i][j]=999;
			}
		}
	}
	while(edges<n){
		int min=999;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(cost[i][j]<min){
					min=cost[i][j];
					a=i;
					b=j;
				}
			}
		}
		u=find(a);
		v=find(b);
		if(unions(u,v)){
			printf("Edge %d=(%d,%d)\tcost=%d\n",edges++,a,b,min);
			mincost+=min;
		}
		cost[a][b]=999;
		cost[b][a]=999;
	}
	printf("%d\n",mincost);
}
int main(){
	int ver,i,j;
	printf("Enter no of Vertices: ");
	scanf("%d",&ver);
	n=ver;
	kruskals();
}
