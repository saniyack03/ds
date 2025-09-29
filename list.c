#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left , *right;
};
void main()
{
struct node * start= (struct node*)0;
struct node * insert(struct node *,int);
struct node * search(struct node *,int);
struct node * delete(struct node *,int);
void display(struct node *);
int item,op;
while(1)
{
printf("\n1.Insert \n2.Delete \n3.Search \n4.Display \n5.Exit \n");
printf("Your option:");
scanf("%d",&op);
switch(op)
{
case 1:printf("Item to insert:");
       scanf("%d",&item);
       start=insert(start,item);
       break;
case 2:printf("Item to delete:");
       scanf("%d",&item);
       start=delete(start,item);
       break;
case 3:printf("Item to search:");
       scanf("%d",&item);
       if(search(start,item)==(struct node *)0)
         printf("not founded....");
       else
         printf("founded....");
       break;
case 4:display(start);
       break;
case 5:exit(0);
}
}
}
//end of main
//function to insert 
struct node * insert(struct node *s,int data)
{
 struct node *t;
 t=(struct node *)malloc(sizeof(struct node)); //create a node
 t->data=data; //fill data        
 t->left=(struct node *)0; 
 t->right=s;
 if(s!=0)
 s->left=t;
 return t;
 }

 //function to display list contents
 void display(struct node  *s)
 {
  while(s!=0)
  {
  printf("%d\n",s->data);
  s=s->right;
  }
  return;
  }

//function to search an item
struct node * search(struct node * s, int data)
{
while(s !=0 && data != s->data)
s=s->right;
return s;
}  



//function to delete
struct node * delete(struct node *s, int data)
{
struct node  *t;
t=search(s,data);
if(t==0)
printf("not founded");
else 
if(t->left==0)
{
s=s->right;
if(t->right !=0)
s->left=0;
free(t);
}
else
{
t->left->right=t->right;
if(t->right != 0)
t->right->left=t->left;
free(t);
}
return s;
}

