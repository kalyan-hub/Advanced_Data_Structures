#include<stdio.h>
int adjacency[10][10],visit[10],nodes,sources;
void dfs(int);
int main()
{
int i,j,s;
printf("Enter the no.of nodes:");
scanf("%d",&nodes);
printf("\n Enter the adjacency matrix of graph\n");
for(i=1;i<=nodes;i++)
  for(j=1;j<=nodes;j++)
     scanf("%d",&adjacency[i][j]);
/* printing adjacency nodes of the graph*/
printf("\n The adjacency matrix is:\n");
for(i=1;i<=nodes;i++)
{
printf(" \n ");
for(j=1;j<=nodes;j++)
printf(" %d ",adjacency[i][j]);
}
printf("\n enter start vertex:");
scanf("%d",&s);
printf("\n D.F.S is:");
dfs(s);
}
void dfs(int i)
{
  int j;
  printf("\t %d",i);
  visit[i]=1;
  for(j=1;j<=nodes;j++)
  {
    if((!visit[j])&&adjacency[i][j]==1)
       dfs(j);
  }
}

