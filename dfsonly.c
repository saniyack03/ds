#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
// Node structure for vertex and edges
struct node {
int data;
int status; // 0 = unvisited, 1 = visited
struct node *next, *point;
};
struct node *g = NULL; // Graph head pointer
// Function to add a vertex
void addvertex(int n) {
struct node *t = (struct node *)malloc(sizeof(struct node));
t->data = n;
t->status = 0;
t->point = NULL;
t->next = g;
g = t;
}
// Function to find a vertex
struct node *find(int n) {
struct node *t = g;
while (t != NULL && t->data != n)
t = t->next;
return t;
}
// Function to add a directed edge u -> v
void addedge(int u, int v) {
struct node *v1, *v2, *t;
v1 = find(u);
v2 = find(v);
if (v1 == NULL || v2 == NULL) return;
t = (struct node *)malloc(sizeof(struct node));
t->next = v1->point;
t->point = v2;
v1->point = t;
}
// Function to print the graph
void printgraph() {
struct node *t1, *t2, *t3;
printf("\nVertex\tEdges List\n");
t1 = g;
while (t1 != NULL) {
printf("%d\t", t1->data);
t2 = t1->point;
while (t2 != NULL) {
t3 = t2->point;
printf("%d ", t3->data);
t2 = t2->next;
}
printf("\n");
t1 = t1->next;
}
}
// Recursive DFS visit
void dfs_visit(struct node *u) {
struct node *t, *adj;
u->status = 1; // Mark as visited
printf("%d ", u->data);
t = u->point;
while (t != NULL) {
adj = t->point;
if (adj->status == 0)
dfs_visit(adj);
t = t->next;
}
}
// DFS traversal from a given start node
void dfs(struct node *start) {
struct node *t = g;
while (t != NULL) {
t->status = 0; // Mark all as unvisited
t = t->next;
}
dfs_visit(start);
}
// Main function
int main() {
addvertex(1);
addvertex(2);
addvertex(3);
addvertex(4);
addvertex(5);
addedge(1, 2);
addedge(1, 4);
addedge(2, 3);
addedge(2, 4);
addedge(4, 3);
addedge(4, 5);
printf("The graph is:\n");
printgraph();
printf("\nDFS Traversal starting from vertex 1: ");
dfs(find(1));
printf("\n");
return 0;
}
