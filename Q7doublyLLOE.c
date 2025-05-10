#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *prev;
    struct node *next;
};

struct node * create(int item){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc Failed! No more memory left!");
        exit(0);
    }
    temp->info=item;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void insertElement(struct node **head , int item){
    if(*head==NULL){
        *head=create(item);
        return;
    }
    struct node *ptr=*head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    struct node * temp=create(item);
    ptr->next=temp;
    temp->prev=ptr;
}
void display(struct node *head){
    if(head==NULL){
        printf("LL is empty!");
        return;
    }
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
}
void displayRev(struct node *tail){
    if(tail==NULL){
        printf("LL is empty!");
        return;
    }
    struct node *ptr=tail;
    printf("\nREVDLL=");
    while (ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->prev;
    }
}
void split(struct node *head,struct node **even,struct node **odd){
    struct node *ptr=head;
    while(ptr!=NULL){
        if(ptr->info %2==0 ){
            insertElement(even,ptr->info);
        }
        else{
            insertElement(odd,ptr->info);
        }
        ptr=ptr->next;
    }
}
int main(){
    struct node *head=NULL;
    insertElement(&head,25);
    insertElement(&head,20);
    insertElement(&head,15);
    insertElement(&head,10);
    insertElement(&head,5);
    insertElement(&head,0);
    display(head);
    struct node *ptr=head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    displayRev(ptr);
    struct node *even=NULL;
    struct node *odd=NULL;
    split(head,&even,&odd);
    printf("\nEven DLL=");
    display(even);
    printf("\nOdd DLL=");
    display(odd);
}