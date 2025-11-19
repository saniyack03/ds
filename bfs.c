#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Node structure for vertex
struct node {
    int data;
    int status; // 0 = unvisited, 1 = visited
    struct edge *point; // adjacency list
    struct node *next;  // next vertex
};

// Edge structure for adjacency list
struct edge {
    struct node *point;   // vertex it points to
    struct edge *next;    // next edge in list
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

// Function to add directed edge u → v
void addedge(int u, int v) {
    struct node *v1 = find(u);
    struct node *v2 = find(v);

    if (v1 == NULL || v2 == NULL) return;

    struct edge *t = (struct edge *)malloc(sizeof(struct edge));
    t->point = v2;
    t->next = v1->point;
    v1->point = t;
}

// BFS traversal
void bfs(struct node *start) {
    if (start == NULL) return;

    // queue for BFS
    struct node *queue[SIZE];
    int front = 0, rear = 0;

    start->status = 1;
    queue[rear++] = start;

    while (front < rear) {
        struct node *current = queue[front++];
        printf("%d ", current->data);

        struct edge *e = current->point;
        while (e != NULL) {
            if (e->point->status == 0) {
                e->point->status = 1;
                queue[rear++] = e->point;
            }
            e = e->next;
        }
    }
}

// Function to print the graph
void printgraph() {
    struct node *t1 = g;

    printf("\nVertex\tEdges List\n");
    while (t1 != NULL) {
        printf("%d\t", t1->data);
        struct edge *e = t1->point;
        while (e != NULL) {
            printf("%d ", e->point->data);
            e = e->next;
        }
        printf("\n");
        t1 = t1->next;
    }
}

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

    printf("The graph is : \n");
    printgraph();

    printf("\nBFS traversal: ");
    bfs(find(1));

    return 0;
}

