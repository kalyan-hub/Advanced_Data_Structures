#include<stdio.h>
#define  HeapSize 100
int HEAP[HeapSize],n;
int main()
{
int choice=1,num;
n=0;   //No.of nodes in the heap
while(choice!=0)
{
printf("\n Operations on Max Heap");
printf("\n 1.Insert Element.");
printf("\n 2.Delete Element.");
printf("\n 3.View Element.");
printf("\n 4.Sort.");
printf("\n 5.Exit.");
printf("\n Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("\n Enter the element to insert");
scanf("%d",&num);
n=n+1;
InsertKey(num,n);
break;
case 2:
printf("\n Enter the element to Delete");
scanf("%d",&num);
DeleteKey(num);
break;
case 3:
Display();
break;
case 4:
sort();
break;
case 5:
choice=0;
break;
default:
printf("\nInvalid Choice");
} //End of Switch
} //End of While
} //
InsertKey(int num,int location)
{
int parentnode;
while(location>1)
{
parentnode=location/2;
if(num<=HEAP[parentnode])
{
HEAP[location]=num;
return;
}
HEAP[location]=HEAP[parentnode];
location=parentnode;
} //End of While
HEAP[1]=num;
} //End of InserKey function
DeleteKey(int num)
{
int left,right,i,temp,parentnode;
if(n==0)
{
printf("\n Empty Heap.");
return;
}
for(i=1;i<=n;i++)
if(num==HEAP[i])
break;
if(i>n)
{
printf("%d not found in heap \n",num);
return;
}
HEAP[i]=HEAP[n];
n=n-1;
parentnode=i/2;
if(HEAP[i]>HEAP[parentnode]&&parentnode!=0)
{
InsertKey(HEAP[i],i);
return;
}
left=2*i; //Left child of i
right=2*i+1; //Right child of i
while(left<=n)
{
if(HEAP[i]>=HEAP[left]&&HEAP[i]>=HEAP[right])
return;
if(HEAP[right]<=HEAP[left])
{
temp=HEAP[i];
HEAP[i]=HEAP[left];
HEAP[left]=temp;
i=left;
}
else
{
temp=HEAP[i];
HEAP[i]=HEAP[right];
HEAP[right]=temp;
i=right;
}
left=2*i;
right=2*i+1;
}
}
Display()
{
int i;
if(n==0)
{
printf("\n Empty Heap.");
return;
}
for(i=1;i<n;i++)
printf("4%d",HEAP[i]);
printf("\n");
}
sort()
{
int i=1;
while(n!=0)
{
printf("%4d",HEAP[i]);
DeleteKey(HEAP[i]);
}
}
   
