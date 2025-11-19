#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct node { // to represent vertex and edge
int data;
int status;
struct node * next,*point;
};
struct topsort{ // to represent vertices to topological sort
int n;
struct topsort *next;
};

struct node * q[10]; // to maintain queue
int front=0,rear = 0 ; //queue handling pointers
struct node *g=0; // to store  graph
struct topsort *tsort=0; //to store topological sort order
//funciton to add a vertex
void addvertex(int n){
struct node *t=(struct node*)malloc(sizeof(struct node));
t->data=n;
t->point=0;
t->next=g;
g=t;
}
//function to find the vertex node address of a vertex
struct node *find(int n){
struct node *t=g;
while(t!=0 && t->data !=n)
t=t->next;
return t;
}
//funciton to add and edge
void addedge(int u,int v){
struct node *v1,*v2,*t;
v1=find(u); //vertex address 
v2=find(v); //vertex address
t=(struct node *)malloc(sizeof(struct node));

t->next=v1->point;
v1->point=t;
t->point=v2;
return;
}
//function to print a graph
void printgraph(){
struct node *t1,*t2,*t3;
printf("\n vertex \t edge list \n");
t1=g;
while(t1!=0){
printf("\n %d...\t \t",t1->data);
t2=t1->point;
while(t2!=0){
t3=t2->point;
printf("%d,",t3->data);
t2=t2->next;
}
t1=t1->next;
}
}
//inserting node into topological order list at begining(storing linked list)
void topsorting (int n){
struct topsort *z=(struct topsort *)malloc(sizeof(struct topsort));
z->n=n;
z->next=tsort;
tsort=z;
}
//printing topologicsl order list
void topsortout()
{
while(tsort != 0){
printf("%d ",tsort->n);
tsort=tsort->next;
}
}
//DFS -VISIT
void dfs_visit(struct node *u){
struct node *t,*t1;
u->status=1; //visit vertex
printf("%d ",u->data);
t=u->point;
while(t!=0){
t1=t->point;
if(t1->status==0)// if not visited
dfs_visit(t1);
t=t->next;
}
topsorting(u->data); //store the node topological sort list
return;
}
//dfs search
void dfs(struct node *g1)
{
struct node *t=g;
while(t!=0){
t->status=0;//set as not visited
t=t->next;
}
dfs_visit(g1);
}



//main funciton to  demonstrate graph search and topological sort
 void main()
{
addvertex(1);
addvertex(2);
addvertex(3);
addvertex(4);
addvertex(5);
addedge(1,2);
addedge(1,4);
addedge(2,3);
addedge(2,4);
addedge(4,3);
addedge(4,5);
printf("the graph is:\n");
printgraph();
printf("\n DFS traverse:");
dfs(find(1));


printf("\n topologicalsort order is:");
topsortout();
}
