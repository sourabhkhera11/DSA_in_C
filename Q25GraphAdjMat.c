//Here we work on vertex number not vertex index
#include<stdio.h>
#include<stdlib.h>

//Define adjacency matrix
#define max 100
int graph[max][max];
//Number of vertices 
int v=0;

void insertVertex(){
    if(v==max){
        printf("Memory full!");
        return;
    }
    for(int i=0;i<=v;i++){
        graph[v][i]=0;
        graph[i][v]=0;
    }
    v++;
    //Here i display vertex number not vertex index
    printf("\nVertex %d is added successfully!",v);
}
//Here also src and des will be vertex number not index
void insertEdge(int src,int des){
    if(src > v || des >v || src < 1 || des < 1){
        printf("\nInvalid src and des! ");
        printf("\nCurrent range of src and des is %d-%d!",1,v);
        return;
    }
    //Undirected garph
    graph[src-1][des-1]=1;
    graph[des-1][src-1]=1;
    printf("\nEdge is added successfuly between %d and %d",src,des);
}
//Here also vertex is v number not index
void deleteVertex(int vertex){
    if(vertex > v || vertex < 1){
        printf("\nNot a valid vertex number !");
        return;
    }

    //Row up 
    for(int i=vertex-1;i<v-1;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=graph[i+1][j];
        }
    }
    //column left
    for(int i=vertex-1;i<v-1;i++){
        for(int j=0;j<v-1;j++){
            graph[j][i]=graph[j][i+1];
        }
    }
    v--;
}
void deleteEdge(int src ,int des){
    if(src > v || des >v || src < 1 || des < 1){
        printf("\nInvalid src and des! ");
        printf("\nCurrent range of src and des is %d-%d!",1,v);
        return;
    }
    graph[src-1][des-1]=0;
    graph[des-1][src-1]=0;
    printf("\nEdge is added deleted between %d and %d",src,des);
}
void degreeOfEachVertex(){
    printf("\nDegree are=");
    for(int i=0;i<v;i++){
        printf("\nV%d :",i+1);
        int count=0;
        for(int j=0;j<v;j++){
            if(graph[i][j]==1){
                count++;
            }
        }
        if(graph[i][i]==1){
            count++;
        }
        printf("%d",count);
    }
}
void noOfSelfLoops(){
    printf("\nNo of self loops are=");
    int count=0;
    for(int i=0;i<v;i++){
        if(graph[i][i]==1){
            count++;
        }
    }
    printf("%d",count);
}
void displayMatrix(){
    printf("    ");
    for(int i=0;i<v;i++){
        printf("V%d ",i+1);
    }
    for(int i=0;i<v;i++){
        printf("\nV%d :",i+1);
        for(int j=0;j<v;j++){
            printf("%d  ",graph[i][j]);
        }
    }
}
int main(){
    int ch,s,d;
    while (1)
    {
        printf("\n----------Graph AM------------\n");
        printf("1)Addvertex \n2)AddEdge \n3)DisplayGraph \n4)DeleteVertex \n5)DeleteEdge \n6)DegreeOfEachVertex \n7)NoOfSelfLoops  \n0)Exit");
        printf("\nEnter your choice=");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insertVertex();
            break;
        case 2:
            printf("\nEnter the source=");
            scanf("%d",&s);
            printf("\nEnter the destination=");
            scanf("%d",&d);
            insertEdge(s,d);
            break;
        case 3:
            displayMatrix();
            break;
        case 4:
            printf("\nEnter the vertex to be deleted:");
            scanf("%d",&s);
            deleteVertex(s);
            break;
        case 5:
            printf("\nEnter the source=");
            scanf("%d",&s);
            printf("\nEnter the destination=");
            scanf("%d",&d);
            deleteEdge(s,d);
            break;
        case 6:
            degreeOfEachVertex();
            break;
        case 7:
            noOfSelfLoops();
            break;
        case 0:
            printf("\nExiting......");
            exit(0);
        default:
            break;
        }
    }
    
}