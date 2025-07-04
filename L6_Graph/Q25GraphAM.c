//Here we work on vertex index not vertex number

//Adjacency Matrix 2D Array
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 100
int graph[max][max];
//Number of vertex in the matrix
int v=0; //No vertex

void insertOfVertex(){
    if(v==max){
        printf("No more vertex can be taken! Memory Full!");
        return;
    }
    for(int i=0;i<=v;i++){
        graph[v][i]=0;
        graph[i][v]=0;
    }
    printf("\nVetex is added at index %d",v);
    v++;
}
void insertOfEdge(int i,int j){
    if(i>=v || j>=v || i<0 || j<0){
        printf("Invalid indexes!");
        return;
    }
    //undirected graph
    graph[i][j]=1;
    graph[j][i]=1;
    printf("\nEdge is added between %d & %d",i,j);
}

//Here vertex is the index of that vertex
void deleteVertex(int vertex){
    if(vertex >=  v || vertex < 0){
        printf("\nInvalid vertex index !");
        return;
    }
    //Row Up
    for(int i=vertex;i<v-1;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=graph[i+1][j];
        }
    }
    //column left
    for(int i=vertex;i<v-1;i++){
        for(int j=0;j<v-1;j++){
            graph[j][i]=graph[j][i+1];
        }
    }
    //set last row and column to 0
    v--;
    for(int i=0;i<=v;i++){
        graph[i][v]=0;
        graph[v][i]=0;
    }
}

void deleteEdege(int i,int j){
    if(i >= v || j>= v || i<0 || j<0){
        printf("\nNot a valid index!");
        return;
    }
    graph[i][j]=0;
    graph[j][i]=0;
    printf("\nEdge deleted between %d & %d",i,j);
}

void degreeOfvertex(){
    for(int i=0;i<v;i++){
        int degree=0;
        for(int j=0;j<v;j++){
            degree+=graph[i][j];
        }
        //2 degree for loop 
        if(graph[i][i]==1){
            degree++;
        }
        printf("\nDegree of vertex %d is %d",i,degree);
    }
}
void noOfSelfLoop(){
    int count=0;
    for(int i=0;i<v;i++){
        if(graph[i][i]==1){
            count++;
        }
    }
    printf("No of self loops %d",count);
}

void displayMatrix(){
    printf("\nMatrix:\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice, u, v;
    while (1) {
        printf("\n--- Undirected Graph Menu ---\n");
        printf("1. Insert Vertex \n");
        printf("2. Insert Edge\n");
        printf("3. Delete Vertex \n");
        printf("4. Delete Edge\n");
        printf("5. Calculate Degree of Each Vertex \n");
        printf("6. Count Number of Self-Loops \n");
        printf("7. Display Adjacency Matrix\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertOfVertex();
                break;
            case 2:
                printf("Enter edge (u v): ");
                scanf("%d %d", &u, &v);
                insertOfEdge(u, v);
                break;
            case 3:
                printf("Enter vertex index to delete: ");
                scanf("%d", &v);
                deleteVertex(v);
                break;
            case 4:
                printf("Enter edge to delete (u v): ");
                scanf("%d %d", &u, &v);
                deleteEdege(u, v);
                break;
            case 5:
                degreeOfvertex();
                break;
            case 6:
                noOfSelfLoop();
                break;
            case 7:
                displayMatrix();
                break;
            case 0:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}