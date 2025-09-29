#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int que[SIZE],front=0,rear=0;//empty queue
void main()
{
void enque(int);
int opt,item,ans;
int deque();
void display();
int search();
while(1)
{
printf("\n1.Insert \n2.Delete \n3.Display \n4.Search \n5.Exit \n");
printf("Your option:");
scanf("%d",&opt);
switch(opt)
{
 case 1:printf("item to insert:");
        scanf("%d",&item);
        enque(item);
        break;
 case 2:item=deque();
        printf("deleted item=%d",item);
        break;
 case 3:display();
        break;
 case 4:printf("item to search:");
        scanf("%d",&item);
        ans=search(item);
        if(ans==1)
          printf("founded...");
        else
          printf("not founded...");
        break;
 case 5:exit(0);
 }
}//enf of while
}
//function to insert an item to circular queue
void enque(int data)
{
 int r1;
 r1=(rear+1)%SIZE;
 if(r1==front)
 printf("queue is full");
 else
 {
 rear=r1;
 que[rear]=data;
 }
 return;
}
//function to delete an item from queue
int deque()
{
 if(front==rear)
 {
  printf("empty queue");
  exit(1);
  }
  else
  {
  front=(front+1)%SIZE;
  return que[front];
  }
}
//function to display queue contents
void display()
{
 int f=front,r=rear;
 while(f!=r)
 {
 f=(f+1)%SIZE;
  printf("%d\n",que[f]);
 }
 return;
}
//function to search am item in queue
int search(int item)
{
int f=front,r=rear;
while(f!=r)
{
f=(f+1)%SIZE;
 if(que[f]==item)
     return 1;
 }
 return 0;
}
  

