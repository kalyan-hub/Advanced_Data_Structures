#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
char ch;
int freq;
struct node *left;
struct node *right;
}node;
node * heap[100];
int heapsize=0;
void insert(node*element)
{
heapsize++;
int Loc=heapsize,par;
while(Loc>1)
{
par=Loc/2;
if(heap[par]->freq<element->freq)
{
heap[loc]=element;
return;
}
heap[Loc]=heap[par];
Loc=par;
}
heap[1]=element;
}
node *DeleteMin()
{
node*Minelement,*lastElement;
int child,now;
minElement=heap[1];
lastElement=heap[heapsize--];
for(now=1;now*2<=heapsize;now=child)
{
child=now*2;
if(child!=heapsize&&heap[child+1]->freq<heap[child]->freq)
{
child++;
}
if(lastElemet->freq>heap[child]->freq)
{
heap[now]=heap[child];
}
else
{
break;
}
}
heap[now]=lastElement;
return minElement;
}
void print(node *temp,char*code)
{
if(temp->left==NULL&&temp->right==NULL)
{
printf("Char %c code %s\n",temp->ch,code);
return;
}
strcpy(leftcode,code);
strcpy(ightcode,code);
leftcoode[length]='0';
leftcode[length+1]='\0';
rightcode[length]='1';
rightcode[length+1]='\0';
print(temp->left,leftcode);
print(temp->right,rightcode);
}

