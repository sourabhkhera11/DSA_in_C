#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 10
int heap[max];

void read(){
    printf("Enter the values in the array:\n");
    for(int i=0;i<max;i++){
        printf("Enter at %d index =",i);
        scanf("%d",&heap[i]);
    }
}
void display(){
    printf("\nHeap = ");
    for(int i=0;i<max;i++){
        printf("%d ",heap[i]);
    }
}
void swap(int i1,int i2){
    int temp=heap[i1];
    heap[i1]=heap[i2];
    heap[i2]=temp;
}
void heapifydown(int i){
    int largest=i;
    int left=(i*2)+1;
    int right=(i*2)+2;
    if(left <= max && heap[left]>heap[largest]){
        largest=left;
    }
    if(right <= max && heap[right]>heap[largest]){
        largest=right;
    }
    if(largest != i){
        swap(i,largest);
        heapifydown(largest);
    }
}
void heapify(){
    //last non leaf node
    int p=(max-1)/2;
    while (p>=0)
    {
        heapifydown(p);
        p--;
    }
    
}
int main(){
    read();
    printf("\nBefore Heap:");
    display();
    heapify();
    printf("\nAfter Build Heap:");
    display();
}