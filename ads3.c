/*program for breath first search of a graph non recursively*/
#include<stdio.h>
#include<stdlib.h>
int nodes,start,v,adj[10][10];
int state[20],queue[20],front=-1,rear=-1;
void insert_queue(int);
int delete_queue();
int isempty_queue();
int main()
{
int i,j;
printf("Enter the no. of nodes:");
scanf("%d",&nodes);
printf("\n Enter the adjacency matrix of graph\n");
for(i=1;i<=nodes;i++)
{
 for(j=1;j<=nodes;j++)
  {
   scanf("%d",&adj[i][j]);
  }
}
for(i=1;i<=nodes;i++)
   state[i]=1;
printf("Enter starting vertex for BFS:\n");
scanf("%d",&start);
insert_queue(start);
state[start]=2;
while(!isempty_queue())
{
v=delete_queue();
printf("%d",v);
state[v]=3;
for(i=1;i<=nodes;i++)
{
if(adj[v][i]==1&&state[i]==1)
{
insert_queue(i);
state[i]=2;
}
}
}
}
void insert_queue(int vertex)
{
if(rear==19)
printf("Queue Overflow\n");
else
{
if(front==-1)
front=0;
rear=rear+1;
queue[rear]=vertex;
}
}
int delete_queue()
{
if(front==-1||front>rear)
{
printf("Queue underflow");
exit(1);
}
return queue[front++];
}
int isempty_queue()
{
if(front==-1||front>rear)
return 1;
else
return 0;
}

