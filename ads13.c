#include<stdio.h>
int a,b,u,v,w,n,i,j,ne=1;
int distance[10],cost[10][10],visited[10];
int choose_vertex(int diatance[10],int n,int visited[10])
{
	int i,min,x;
	min=999;
	x=-1;
	for(i=2;i<=n;i++);
	 if(distance[i]<min && visited[i]==0)
	 {
	 	min=distance[i];
	 	x=i;
	 }
	return x;
}
int main()
{
	int l;
	printf("Enter the no. of nodes:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:");
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	 {
	 	printf("Enter edge(%d,%d)cost:",i,j);
	 	scanf("%d",&cost[i][j]);
	 	if(cost[i][j]==0)
	 	 cost[i][j]=999;
	 }
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
		distance[i]=cost[l][i];
	}
	visited[l]=1;
	visited[l]=0;
	for(i=2;i<=n;i++)
	{
		v=choose_vertex(distance,n,visited);
		visited[v]=1;
		for(w=1;w<=n;w++)
		 if(visited[w]==0)
		 {
		 	if(distance[v]+cost[v][w]<distance[w])
		 	distance[w]=distance[v]+cost[v][w];
		 }
		 printf("Visited-->");
		 for(l=1;l<=n;l++)
		 {
		 	printf("%6d",visited[l]);
		 }
		 printf("\n Distance->");
		 for(l=1;l<=n;l++)
		 {
		 	printf("%6d",distance[l]);
		 }
		 printf("\n");
	}
	for(i=2;i<=n;i++)
	   printf("\n Shortest path from 1 to %d : %d",i,distance[i]);
}

