//program to implement huffman series
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
node *heap[100];
int heapsize=0;
void Insert(node * element)
{
heapsize++;
int loc=heapsize,par;
while(loc>1)
{
par=loc/2;
if(heap[par]->freq<element->freq)
{
heap[loc]=heap[par];
loc=par;
}
heap[1]=element;
}
node * DeleteMin();
{
node * minelement, * lastelement;
int child,now;
minelement=heap[1];
lastelement=heap[heapsize--];
for(now=1;now*2<=heapsize;now=child)
{
child=now*2;
if(child!=heapsize && heap[child+1]->freq<heap[child]->freq)
{
child++;
}
if(lastelement->freq>heap[child]->freq)
{
heap[now]=heap[child];
}
else
{
break;
}
}
heap[now]=lastelement;
return minelement;
}
}
void print(node * temp,char * code)
{
int length=strlen(code);
char leftcode[10],rightcode[10];
if(temp->left==NULL&&temp->right==NULL)
{
printf("char %c code %s\n",temp->ch,code);
return;
}
strcpy(leftcode,code);
strcpy(rightcode,code);
leftcode[length]='0';
rightcode[length+1]='\0';
rightcode[length]='1';
rightcode[length+1]='\0';
printf(temp->left,leftcode);
printf(temp->right,rightcode);
}
int main()
{
heap[0]=(node *)malloc(sizeof(node));
heap[0]->freq=0;
int n,freq,i;
printf("Enter the no.of characters");
scanf("%d",&n);
printf("Enter the characters and their frequencies:");
char ch;
for(i=0;i<n;i++)
{
scanf("%c",&ch);
scanf("%d",&freq);
node * temp=(node *)malloc(sizeof(node));
temp->ch=ch;
temp->freq=freq;
temp->left=temp->right=NULL;
Insert(temp);
}
if(n==1)
{
printf("char %c code 0\n",ch);
return 0;
}
for(i=0;i<n-1;i++)
{
node *left=DeleteMin();
node *right=DeleteMin();
node *temp=(node *)malloc(sizeof(node));
temp->ch=0;
temp->left=left;
temp->right=right;
temp->freq=left->freq+right->freq;
Insert(temp);
}
node *tree=DeleteMin();
char code[10];
code[0]='\0';
print(tree,code);
}

