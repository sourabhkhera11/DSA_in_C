//Here we work on vertex index not vertex number

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int vertex;
    struct node * next;
};

struct graph{
    int numVertices;
    struct node ** adjList;
};

struct node * createNode(int v){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Malloc failed!");
        exit(0);
    }
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
}
struct graph * createGraph(int num){
    struct graph * g=(struct graph *)malloc(sizeof(struct graph));
    g->numVertices=num;
    g->adjList=(struct node **)malloc(num * sizeof(struct node*));
    
    for(int i=0;i<num;i++){
        g->adjList[i]=NULL;
    }
    return g;
}

void addEdge(struct graph *g,int src,int dest){
    if( src >= g->numVertices  || dest >= g->numVertices || src < 0 || dest < 0){
        printf("Invalid index of src or dest!");
        return;
    }
    //Undirected graph
    //src - dest
    struct node * temp=createNode(dest);
    temp->next=g->adjList[src];
    g->adjList[src]=temp;

    //dest - src
    temp=createNode(src);
    temp->next=g->adjList[dest];
    g->adjList[dest]=temp;

    printf("\nEdge add between %d & %d ",src, dest);
}

void deletEdge(struct graph *g ,int src ,int dest){
    if( src >= g->numVertices  || dest >= g->numVertices || src < 0 || dest < 0){
        printf("Invalid index of src or dest!");
        return;
    }
    //Undirected graph
    //src - dest
    struct node * current =g->adjList[src];
    struct node * prev =NULL;

    while (current!=NULL)
    {
        if(current->vertex==dest){
            if(prev==NULL){
                //Head element 
                g->adjList[src]=current->next;
            }
            else{
                prev->next=current->next;
            }
            free(current);
            break;
        }
        prev=current;
        current=current->next;
    }
    
    //dest - src
    current=g->adjList[dest];
    prev=NULL;
    while (current!= NULL)
    {
        if(current->vertex==src){
            if(prev==NULL){
                g->adjList[dest]=current->next;
            }
            else{
                prev->next=current->next;
            }
            free(current);
            break;
        }
        prev=current;
        current=current->next;
    }
}
void displayGraph(struct graph *g){
    for(int i=0;i<g->numVertices;i++){
        struct node * ptr=g->adjList[i];
        printf("\n%d :",i);
        while (ptr!=NULL)
        {
            printf("%d ",ptr->vertex);
            ptr=ptr->next;
        }
    }
}
void printDegree(struct graph * g){
    int degree;
    for(int i=0;i<g->numVertices;i++){
        degree=0;
        printf("\nDegree of vertex %d is :",i);
        struct node *ptr=g->adjList[i];
        while (ptr!=NULL)
        {
            degree++;
            ptr=ptr->next;
        }
        printf("%d",degree);
    }
}
void addVertex(struct graph *g){
    int num=g->numVertices+1;
    g->adjList=(struct node **)realloc(g->adjList,num * sizeof(struct node *));
    g->adjList[num-1]=NULL;
    g->numVertices=num;
    printf("Vertex %d added.\n", num - 1);
}
void deleteVertex(struct graph *g,int v){
    if(v >= g->numVertices || v<0){
        printf("\nInvalid vertex !");
        return;
    }
    for(int i=0;i<g->numVertices;i++){
        if(i !=v){
            deletEdge(g,i,v);
        }
    }
    struct node *ptr=g->adjList[v];
    while (ptr!=NULL)
    {
        struct node *temp=ptr;
        ptr=ptr->next;
        free(temp);
    }
    g->adjList[v]=NULL;
    printf("Vertex %d deleted (note: index reserved, graph size not reduced).\n", v);
    
}
int main() {
    int choice, src, dest, v;
    int initialVertices;

    printf("Enter initial number of vertices: ");
    scanf("%d", &initialVertices);

    struct graph* g = createGraph(initialVertices);

    do {
        printf("\n--- Graph Menu ---\n");
        printf("1. Add Vertex\n");
        printf("2. Add Edge\n");
        printf("3. Delete Vertex\n");
        printf("4. Delete Edge\n");
        printf("5. Print Degree of each Vertex\n");
        printf("6. Display Graph\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVertex(g);
                break;
            case 2:
                printf("Enter source and destination: ");
                scanf("%d %d", &src, &dest);
                addEdge(g, src, dest);
                break;
            case 3:
                printf("Enter vertex to delete: ");
                scanf("%d", &v);
                deleteVertex(g, v);
                break;
            case 4:
                printf("Enter source and destination: ");
                scanf("%d %d", &src, &dest);
                deletEdge(g, src, dest);
                break;
            case 5:
                printDegree(g);
                break;
            case 6:
                displayGraph(g);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    // Cleanup memory
    for (int i = 0; i < g->numVertices; i++) {
        struct node* temp = g->adjList[i];
        while (temp) {
            struct node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(g->adjList);
    free(g);

    return 0;
}