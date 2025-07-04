//Here we work on vertex number not vertex index

#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node* next;
};

struct graph{
    //Number of vertex in the graph
    int numVertex;
    //Pointer to a adjlist 
    struct node **adjList;
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

struct graph *createGraph(int num){
    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    if(g==NULL){
        printf("Malloc failed!");
        exit(0);
    }
    g->numVertex=num;
    g->adjList=(struct node **)malloc(num *sizeof(struct node *));
    for(int i=0;i<num;i++){
        g->adjList[i]=NULL;
    }
    return g;
}
//Here src and des is the vertex number not index 
void insertEdge(struct graph *g,int src ,int des){
    if(src > g->numVertex || des > g->numVertex || src <1 || des <1 ){
        printf("\nInvalid vertex number!");
        return;
    }

    //src - des
    struct node * temp=createNode(des);
    temp->next=g->adjList[src-1];
    g->adjList[src-1]=temp;

    //des - src
    if(src!=des){
        temp=createNode(src);
        temp->next=g->adjList[des-1];
        g->adjList[des-1]=temp;
    }
    printf("\nEdge add between %d & %d ",src, des);
}

void deleteEdge(struct graph *g,int src,int des){
    if(src > g->numVertex || des > g->numVertex || src <1 || des <1 ){
        printf("\nInvalid vertex number!");
        return;
    }
    //src - des 
    struct node *current =g->adjList[src-1];
    struct node *prev=NULL;
    while (current!=NULL)
    {
        if(current->vertex==des){
            if(prev==NULL){
                g->adjList[src-1]=current->next;
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
    //dec - src 
    current =g->adjList[des-1];
    prev=NULL;
    while (current!=NULL)
    {
        if(current->vertex==src){
            if(prev==NULL){
                g->adjList[des-1]=current->next;
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
    printf("\nEdge delete between %d & %d ",src, des);
}
void printDegree(struct graph *g){
    for(int i=0;i<g->numVertex;i++){
        printf("\nDegree of V%d :",i+1);
        int count=0;
        struct node *ptr=g->adjList[i];
        while (ptr!=NULL)
        {
            if(ptr->vertex==i+1){
                count++;
            }
            count++;
            ptr=ptr->next;
        }

        printf("%d",count);
    }
}
void addVertex(struct graph *g){
    int num=g->numVertex+1;
    g->adjList=(struct node **)realloc(g->adjList,num * sizeof(struct node *));
    g->numVertex=num;
    g->adjList[num-1]=NULL;
    printf("\nVertex %d added successfully!",num);
}
void deleteVertex(struct graph *g,int v){
    if( v > g->numVertex || v < 1){
        printf("Invalid vertex !");
        return;
    }

    //Delete edges where it act as a node 
    for(int i=1;i<=g->numVertex;i++){
        if(i!=v){
            deleteEdge(g,i,v);
        }
    }
    deleteEdge(g,v,v);
    printf("Vertex %d deleted successfully!",v);
}
void displayGraph(struct graph *g){
    for(int i=0;i<g->numVertex;i++){
        printf("\nV%d -> ",i+1);
        struct node *ptr=g->adjList[i];
        while (ptr!=NULL)
        {
            printf("%d ",ptr->vertex);
            ptr=ptr->next;
        }
    }
}
int main(){
    int ch ,s,d,num;
    printf("Enter the number of vertices in the graph=");
    scanf("%d",&num);
    struct graph *g=createGraph(num);
    while (1)
    {
        printf("\n-----------Graph AL--------\n");
        printf("1)AddEdge \n2)Display \n3)DeleteEdge \n4)PrintOrder \n5)AddVertex \n6)DeleteVertex \n0)Exit");
        printf("\nEnter your choice=");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the sorce=");
            scanf("%d",&s);
            printf("\nEnter the destination=");
            scanf("%d",&d);
            insertEdge(g,s,d);
            break;
        case 2:
            displayGraph(g);
            break;
        case 3:
            printf("\nEnter the sorce=");
            scanf("%d",&s);
            printf("\nEnter the destination=");
            scanf("%d",&d);
            deleteEdge(g,s,d);
            break;
        case 4:
            printDegree(g);
            break;
        case 5:
            addVertex(g);
            break;
        case 6:
            printf("\nEnter the vertex to be deleted:");
            scanf("%d",&s);
            deleteVertex(g,s);
            break;
        case 0:
            exit(0);
        default:
            break;
        }
    }
    
}