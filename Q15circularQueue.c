#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 10

int queue[max];
int f=-1;
int r=-1;

bool isempty(){
    return (f==-1 && r==-1);
}
bool isfull(){
    return ((r+1)%max ==f);
}
void enqueue(int item){
    if(isfull()){
        printf("Overflow!");
        return;
    }
    if(isempty()){
        f++;
        r++;
        queue[r]=item;
        return;
    }
    r=(r+1)%max;
    queue[r]=item;
}
int dequeue(){
    if(isempty()){
        printf("Underflow!");
        return -1;
    }
    int item=queue[f];
    f=(f+1)%max;
    return item;
}
int peek(){
    if(isempty()){
        printf("Underflow!");
        return -1;
    }
    int item=queue[f];
    return item;
}
void display(){
     if(isempty()){
        printf("Underflow!");
        return;
    }
    printf("\nQueue= ");
    if(f<r){
        for(int i=f;i<=r;i++){
            printf("%d ",queue[i]);
        }
    }
    else{
        for(int i=f;i<max;i++){
            printf("%d ",queue[i]);
        }
        for(int i=0;i<=r;i++){
            printf("%d ",queue[i]);
        }
    }
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    display();
    printf("\nPop element is %d",dequeue());
    printf("\nPop element is %d",dequeue());
    printf("\nPop element is %d",dequeue());
    printf("\nPop element is %d",dequeue());
    display();
    enqueue(11);
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    display();
    printf("\nPeek element is %d",peek());
    printf("\nPop element is %d",dequeue());
}