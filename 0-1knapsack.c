#include<stdio.h>

int max(int a,int b)
{
	return a>b?a:b;
}

int knapsack(int n,int wei[],int val[],int weight)
{
	int dp[n+1][weight+1],i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=weight;j++)
		{
			printf("%d ",i,j);
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(wei[i-1]<=j)
				dp[i][j]=max(val[i-1]+dp[i-1][j-wei[i-1]],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}

	return dp[n][weight];
}


int main()
{
	int n,weight;
	printf("Enter n value : ");
	scanf("%d",&n);
	int val[n],wei[n],i;
	printf("Enter values from 1 to n : ");
	for(i=0;i<n;i++)
		scanf("%d",&val[i]);
	printf("Enter weights from 1 to n : ");
	for(i=0;i<n;i++)
		scanf("%d",&wei[i]);
	printf("Enter weight : ");
	scanf("%d",&weight);
	printf("%d",knapsack(n,wei,val,weight));
}