/* C Program to implement hashing using division */
#include<stdio.h>
int ht[10],i,found=0,key;
void insert_val();
void search_val();
void delete_val();
void display();
int main()
{
int option;
for(i=0;i<10;i++)
ht[i]=-1;
do
{
printf("\nMENU \n1.INSERT 2.SEARCH 3.DELETE 4.DISPLAY 5.EXIT");
scanf("%d",&option);
switch(option)
{
case 1:insert_val();
break;
case 2:search_val();
break;
case 3:delete_val();
break;
case 4:display();
break;
case 5:option=5;
break;
default:printf("\nINVALID CHOICE");
}
}while(option!=5);
return 0;
}
void insert_val()
{
int val;
printf("Enter the element to be inserted:");
scanf("%d",&val);
key=val%10;
if(ht[key]==-1)
{
ht[key]=val;
}
else
{
printf("\nList is full");
}
}
void search_val()
{
int val;
printf("Enter the element to be searched:");
scanf("%d",&val);
key=val%10;
if(ht[key]==val)
{
printf("\nThe item is found at:%d",key);
}
else
{
printf("\nThe item is not found in hash table");
}
}
void delete_val()
{
int ele;
printf("Enter the element to delete:");
scanf("%d",&ele);
key=ele%10;
if(ht[key]==ele)
{
printf("The deleted element is:%d",ht[key]);
ht[key]=-1;
}
else
printf("\nThe element is not found");
}
void display()
{
for(i=0;i<10;i++)
printf("\t %d",i);
printf("\n");
for(i=0;i<10;i++)
printf("\t %d",ht[i]);
}

