#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data ;
    struct node *next;
};

struct node *stack=NULL;
bool isempty(){
    if(stack==NULL){
        return true;
    }
    return false;
}
struct node *create(int item){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc failed! NO more memory!");
        exit(0);
    }
    temp->data=item;
    temp->next=NULL;
    return temp;
}

void push(int item){
    if(stack==NULL){
        stack=create(item);
        return;
    }
    struct node *temp=create(item);
    temp->next=stack;
    stack=temp;
}
void pop(){
    if(isempty()){
        printf("Underflow!");
        return;
    }
    struct node *temp=stack;
    stack=stack->next;
    printf("Pop element is %d",temp->data);
    free(temp);
}
void peek(){
    if(isempty()){
        printf("Underflow!");
        return;
    }
    printf("Peek element is %d",stack->data);
}
void display(){
    if(isempty()){
        printf("Underflow!");
        return;
    }
    struct node *ptr=stack;
    printf("\nStack =");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    push(35);
    push(30);
    push(25);
    push(20);
    push(15);
    push(10);
    push(5);
    display();
    pop();
    display();
    peek();
}