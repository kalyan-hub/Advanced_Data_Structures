// C Program for AVL tree operations
#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct node *left;
struct node *right;
int height;
};
int height(struct Node *N)
{
if(N==NULL)
return 0;
return N->height;
}
int max(int a,int b)
{
return (a>b)?a:b;
}
struct Node *newnode(int key)
{
struct Node *node=(struct Node*)malloc
(sizeof(struct Node))
node->data=key;
node->right=NULL;
node->left=NULL;
node->height=1;
return(node);
}
struct Node*rightrotate(struct Node*gp)
{
struct Node*par=gp->left;
struct Node*T3=par->right;
par->right=gp;//start of rotation
gp->left=T3;
gp->height=max(height(gp->left),height(gp->right))+1;
par->height=max(height(par->left),height(par->right))+1;
return par;
}
struct Node*leftrotate(struct Node*gp)
{
struct Node*par=gp->right;
struct Node*T2=par->left;
par->left=gp;//start of rotation
gp->right=T2;
gp->height=max(height(gp->left),height(gp->right))+1;
par->height=max(height(par->left),height(par->right))+1;
return par;//returning new root;
}
int getbalance(struct Node*N)//balancing factor
{
if(N==NULL)
return 0;
return height(N->left)-height(N->right)
}
struct Node*insert(struct Node*node,int key)
{
if(node==NULL)
return(newnode(key));
if(key<=node->data)
node->left=insert(node->left,key)
else if(key>node->data)
node->right=insert(node->right,key)
else
return node;
node->height=1+max(height(node->left),height(node->right);
int balance=getbalance(node);
if(balance>1&&key<node->left->data)//ll case
return rightbalance(node);
if(balance>-1&&key>node->right->data)//rr case
return leftrotate(node);
if(balance>1&&key->left->data)//lr case
{
node->left=leftrotate(node->left);
return rightrotate(node);
}
if(balance<-1&&key<node->right->data)//rl case
{
node->right=rightrotate(node->right);
return leftrotate(node);
}
return node;
}
struct Node*minvaluenode(struct Node*node)
{
struct Node*current=node;
while(current->left!=NULL)//loop down to find leaf
current=current->left;
return current;
}
int searchnode(struct Node*node,int key)
{
struct Node*ptr=root;
if(ptr==NULL)
return 0;
if(ptr->data==key)
return 1;
else if(key<ptr->data)
searchnode(ptr->left,key);
else
searchnode(ptr->right,key);
}
void preorder(struct Node*root)
{
if(root!=NULL)
{
printf("%d  ",root->data);
preorder(root->left);
preorder(root->right);
}
}
int main()
{
int op,key;
struct Node*root=NULL;
do
{
printf("\n1.INSERT\n2.SEARCH\n3.PREORDER DISPLAY");
printf("\n4.EXIT");
printf("\n Choose an option:\n");
scanf("%d",&op);
switch(op)
{
case 1:
printf("\nEnter value to insert:");
scanf("%d",&key);
root=insert(root,key);
break;
case 2:
printf("\n Enter key to search:");
scanf("%d",&key);
if(searchnode(root,key))
printf("%d Found\n",key);
else
printf("%d Not Found\n",key);
break;
case 3:
printf("\n Preorder Traversal is:");
preorder(root);
break;
case 4:
exit(0);
}
}while(op!=5);
return 0;
}

