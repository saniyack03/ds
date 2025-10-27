#include<stdio.h>
#include<stdlib.h>
//structure to represent an objectof a set in linked representation
struct node
{
  int value;
  struct rep * repptr;   //pointer to header node of the list
  struct node * next;
 };
 //structure to represent heaer node of linked representation of set
 struct rep
 {
  struct node * head;
  struct node * tail;
 };
 
//structure to store key & object nodr pointer
struct nodaddr
{
 int key;
 struct node * obj_node_ptr;
 struct nodaddr * next;
};
struct nodaddr * ndr=0;   //list to store keys & object node pointer

//function to create a set for a object
void makeset(int a)
{                       //create a object node pointer
  struct nodaddr * t=(struct nodaddr *)malloc(sizeof(struct nodaddr));
  //create a new set
  struct rep * newset=(struct rep *)malloc(sizeof(struct rep));
  struct node * n=(struct node *)malloc(sizeof(struct node));
  //find values
  n->value=a;
  n->repptr=newset;
  n->next=0;
  //initialize head and tail
  newset->head=newset->tail=n;
  //to store object node pointer & key
  t->obj_node_ptr=n;
  t->key=a;
  t->next=ndr;
  ndr=t;
}

//function to return pointer of the representative(header node)of the set
//containing x
 struct rep * find(int X)
 {
   struct nodaddr * t=ndr;
   while(t!=0&&t->key!=X)
   t=t->next;
   return t->obj_node_ptr->repptr;
 }
 
//to find union of two sets corresponding to objects given
void unionset(int key1,int key2)
{
 struct rep *set1,*set2;
 struct node * t1;
 set1=find(key1);
 set2=find(key2);
 if(set1==set2)
 printf("\n%d and %d belongs to same set\n",key1,key2);
 else
 {
 //changing the header pointers of objects of set2 to that of set1
 t1=set2->head;
 while(t1 !=0)
 {
  t1->repptr=set1;
  t1=t1->next;
 }
 set1->tail->next=set2->head;
 set1->tail=set2->tail;  //set the tail of set1 to tail of set2
 free(set2);
 }
}

//function to display a set
void display_set(int a)
{ 
 struct rep * r;
 struct node * t;
 r=find(a);
 t=r->head;
 printf("\nset numbers containing %d:",a);
 while(t !=0)
 {
 printf("%d,",t->value);
 t=t->next;
 }
}

void main()
{
 makeset(10);
 makeset(20);
 makeset(30);
 makeset(40);
 makeset(50);
 printf("find(10)=%X",find(10));
 printf("\nfind(20)=%X",find(20));
 printf("\nfind(30)=%X",find(30));
 printf("\nfind(40)=%X",find(40));
 unionset(10,20);
 printf("\n after union of 10 and 20 find(20)=%X",find(20));
 unionset(30,40);
 printf("\n after union of 30 and 40 find(40)=%X",find(40));
 unionset(20,40);
 printf("\n after union of set containing 20 and set containing 40 find(40)=%X\n\n",find(40));
 display_set(40);
}
 
