#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Heap : Complete BT : No internal fragmentation : array
#define max 100
int heap[max];
int size=-1;

void swap(int i1,int i2){
    int temp=heap[i1];
    heap[i1]=heap[i2];
    heap[i2]=temp;
}
void heapifyup(){
    int i=size;
    int parent=(i-1)/2;
    while (parent>=0 && heap[i]>heap[parent])
    {
        swap(i,parent);
        i=parent;
        parent=(i-1)/2;
    }
    
}
void insert(int item){
    if(size== max-1){
        printf("Overflow!");
        return;
    }
    heap[++size]=item;
    heapifyup();
}
void heapifydown(int i){
    int largest=i;
    int left=(i*2)+1;
    int right=(i*2)+2;
    if(left<=size && heap[left]>heap[largest]){
        largest=left;
    }
    if(right<=size && heap[right]>heap[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(largest,i);
        heapifydown(largest);
    }
}
int delete(){
    if(size==-1){
        printf("Underflow!");
        exit(0);
    }
    int m=heap[0];
    printf("\nRemoving the max element: %d",m);
    swap(0,size);
    size--;
    heapifydown(0);
    return m;
}
void display(){
    printf("\nHeap= ");
    for(int i=0;i<=size;i++){
        printf("%d ",heap[i]);
    }
}

int main(){
    int c=1;
    int ch,val;
    while (c!=0)
    {
        printf("\n-------------Heap-----------\n");
        printf("1)Insert\n2)Delete\n3)Display\n4)Exit");
        printf("\nEnter you choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case  1:
            printf("\nEnter the value to be inserted =");
            scanf("%d",&val);
            insert(val);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
        printf("\nEnter 0 to break and 1 to continue! ");
        scanf("%d",&c); 
    }
    return 0;
}