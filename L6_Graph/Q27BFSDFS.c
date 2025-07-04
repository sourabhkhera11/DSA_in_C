#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 100

// Queue implementation
int queue[max];
int f = -1, r = -1;

bool isempty() {
    return (f == -1 || f > r);
}

void enqueue(int value) {
    if (r == max - 1) {
        printf("Memory Full!\n");
        return;
    }
    if (f == -1) f = 0;
    queue[++r] = value;
}

int dequeue() {
    if (isempty()) {
        printf("Underflow\n");
        return -1;
    }
    return queue[f++];
}

struct node {
    int vertex;
    struct node* next;
};

struct graph {
    int numVertex;
    struct node** adjList;
};

struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Malloc failed!");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct graph* createGraph(int num) {
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    if (!g) {
        printf("Malloc failed!");
        exit(1);
    }
    g->numVertex = num;
    g->adjList = (struct node**)malloc(num * sizeof(struct node*));
    for (int i = 0; i < num; i++)
        g->adjList[i] = NULL;
    return g;
}

void insertEdge(struct graph* g, int src, int des) {
    if (src > g->numVertex || des > g->numVertex || src < 1 || des < 1) {
        printf("Invalid vertex number!\n");
        return;
    }

    struct node* temp = createNode(des);
    temp->next = g->adjList[src - 1];
    g->adjList[src - 1] = temp;

    if (src != des) {
        temp = createNode(src);
        temp->next = g->adjList[des - 1];
        g->adjList[des - 1] = temp;
    }
    printf("Edge added between %d and %d\n", src, des);
}

void deleteEdge(struct graph* g, int src, int des) {
    if (src > g->numVertex || des > g->numVertex || src < 1 || des < 1) {
        printf("Invalid vertex number!\n");
        return;
    }

    struct node *current = g->adjList[src - 1], *prev = NULL;
    while (current) {
        if (current->vertex == des) {
            if (prev == NULL)
                g->adjList[src - 1] = current->next;
            else
                prev->next = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }

    current = g->adjList[des - 1];
    prev = NULL;
    while (current) {
        if (current->vertex == src) {
            if (prev == NULL)
                g->adjList[des - 1] = current->next;
            else
                prev->next = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }

    printf("Edge deleted between %d and %d\n", src, des);
}

void printDegree(struct graph* g) {
    for (int i = 0; i < g->numVertex; i++) {
        int count = 0;
        struct node* ptr = g->adjList[i];
        while (ptr) {
            if (ptr->vertex == i + 1) count++; // self loop counts once
            count++;
            ptr = ptr->next;
        }
        printf("Degree of V%d: %d\n", i + 1, count);
    }
}

void addVertex(struct graph* g) {
    int newNum = g->numVertex + 1;
    g->adjList = (struct node**)realloc(g->adjList, newNum * sizeof(struct node*));
    g->adjList[newNum - 1] = NULL;
    g->numVertex = newNum;
    printf("Vertex %d added successfully!\n", newNum);
}

void deleteVertex(struct graph* g, int v) {
    if (v > g->numVertex || v < 1) {
        printf("Invalid vertex!\n");
        return;
    }

    // Remove all edges to/from vertex v
    for (int i = 1; i <= g->numVertex; i++) {
        deleteEdge(g, i, v);
    }

    free(g->adjList[v - 1]);

    // Shift all remaining vertices
    for (int i = v - 1; i < g->numVertex - 1; i++) {
        g->adjList[i] = g->adjList[i + 1];
    }

    g->numVertex--;
    g->adjList = (struct node**)realloc(g->adjList, g->numVertex * sizeof(struct node*));

    printf("Vertex %d deleted successfully!\n", v);
}

void displayGraph(struct graph* g) {
    for (int i = 0; i < g->numVertex; i++) {
        printf("V%d -> ", i + 1);
        struct node* ptr = g->adjList[i];
        while (ptr) {
            printf("%d ", ptr->vertex);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void bfs(struct graph*g,int source){
    if(source <0 || source >= g->numVertex){
        printf("\nInvalid vertex!");
        return;
    }
    int visited[g->numVertex];
    for(int i=0;i<g->numVertex;i++){
        visited[i]=0;
    }
    f=r=-1;
    enqueue(source);
    visited[source]=1;
    printf("\nBFS tarversal : ");
    while (!isempty())
    {
        int current =dequeue();
        printf("%d ",current+1);
        struct node * temp=g->adjList[current];
        while (temp!=NULL)
        {
            if(!visited[temp->vertex-1]){
                enqueue(temp->vertex-1);
                visited[temp->vertex-1]=1;
            }
            temp=temp->next;
        }
        
    }
}
void dfs(struct graph *g, int vertex,int visited[]){
    visited[vertex]=1;
    struct node *temp =g->adjList[vertex];
    while (temp!=NULL)
    {
        int v=temp->vertex-1; 
        if(visited[v]==0){
            dfs(g,v,visited);
        }
        temp=temp->next;
    }
    printf("%d ",vertex+1);
}

int main() {
    int ch, s, d, num;

    printf("Enter number of vertices in the graph: ");
    scanf("%d", &num);
    struct graph* g = createGraph(num);
    int visited[num];
    while (1) {
        printf("\n----------- Graph Menu -----------\n");
        printf("1) Add Edge\n2) Display Graph\n3) Delete Edge\n");
        printf("4) Print Degree\n5) Add Vertex\n6) Delete Vertex\n7) BFS \n8)DFS\n0) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter source vertex: ");
            scanf("%d", &s);
            printf("Enter destination vertex: ");
            scanf("%d", &d);
            insertEdge(g, s, d);
            break;
        case 2:
            displayGraph(g);
            break;
        case 3:
            printf("Enter source vertex: ");
            scanf("%d", &s);
            printf("Enter destination vertex: ");
            scanf("%d", &d);
            deleteEdge(g, s, d);
            break;
        case 4:
            printDegree(g);
            break;
        case 5:
            addVertex(g);
            break;
        case 6:
            printf("Enter vertex to delete: ");
            scanf("%d", &s);
            deleteVertex(g, s);
            break;
        case 7:
            printf("Enter BFS source vertex: ");
            scanf("%d", &s);
            bfs(g, s - 1);
            break;
        case 8:
            for(int i=0;i<num;i++){
                visited[i]=0;
            }
            printf("Enter source =");
            scanf("%d",&s);
            dfs(g,s-1,visited);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
