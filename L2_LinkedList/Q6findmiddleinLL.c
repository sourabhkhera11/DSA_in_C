#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};

struct node * create(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc failed!");
        exit(0);
    }
    temp->data=data;
    temp->next=NULL;
    return temp;
}

struct node *insert(struct node * head,int data){
    if(head==NULL){
        return create(data);
    }
    struct node * ptr=head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=create(data);
    return head;
    
}
void findMiddle(struct node *head){
    if(head==NULL){
        printf("Empty!");
        return;
    }
    struct node *slow=head;
    struct node *fast =head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("Middle element is %d",slow->data);
}
void display(struct node *head){
    if(head==NULL){
        printf("Empty!");
        return;
    }
    struct node * ptr=head;
    printf("\nLinked list=");
    while (ptr!=NULL)
    {
        printf("%d ->",ptr->data);
        ptr=ptr->next;
    }
}
struct node * mn(struct node *head,int m,int n){
    //retain m nodes and delete n node 
    if(head==NULL){
        printf("Empty ll");
        exit(0);
    }
    struct node *ptr=head;
    while (ptr!=NULL && ptr->next!=NULL)
    {
        //Move m-1 nodes ahead
        for(int i=0;i<m-1;i++){
            ptr=ptr->next;
            if(ptr==NULL){
                break;
            }
        }
        //Delete n nodes 
        for(int i=0;i<n;i++){
            if(ptr->next!=NULL){
                struct node *temp=ptr->next;
                ptr->next=ptr->next->next;
                free(temp);
            }
            else{
                break;;
            }
        }
        if(ptr->next!=NULL) ptr=ptr->next;
    }
    printf("\nSuccess!");
    return head;
}
int main(){
    int ch,item,m,n;
    struct node *head=NULL;
    while (1)
    {
        printf("\n1)Insert \n2)display \n3)findmiddle\n4)MN \n0)Exit");
        printf("\nEnter your choice =");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the value to be inserted=");
            scanf("%d",&item);
            head=insert(head,item);
            break;
        case 2:
            display(head);
            break;
        case 3:
            findMiddle(head);
            break;
        case 4:
            printf("\nEnter the value of m=");
            scanf("%d",&m);
            printf("\nEnter the value of n=");
            scanf("%d",&n);
            head=mn(head,m,n);
            break;
        case 0:
            exit(0);
        default:
            break;
        }
    }
    
}