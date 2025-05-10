#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *next;
};

struct node *f=NULL;
struct node *r=NULL;

bool isempty(){
    return (f==NULL && r==NULL);
}
struct node * create(int item){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc Failed! No more space available!");
        exit(0);
    }
    temp->data=item;
    temp->next=NULL;
    return temp;
}
void enqueue(int item){
    if(isempty()){
        f=r=create(item);
        return;
    }
    struct node *temp=create(item);
    r->next=temp;
    r=temp;
}
int dequeue(){
    if(isempty()){
        printf("Underflow!");
        return -1;
    }
    struct node * temp=f;
    int info=temp->data;
    f=f->next;
    free(temp);
    return info;
}
int peek(){
    if(isempty()){
        printf("Underflow!");
        return -1;
    }
    return f->data;
}
void display(){
    if(isempty()){
        printf("Underflow!");
        return;
    }
    struct node *ptr=f;
    printf("\nQueue= ");
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
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