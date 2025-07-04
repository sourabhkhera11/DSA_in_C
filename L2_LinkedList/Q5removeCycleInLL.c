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
void findAndRemoveCycle(struct node *head){
    if(head==NULL){
        printf("Empty!");
        return;
    }
    struct node *slow=head;
    struct node *fast =head;
    int found=0;
    while (fast!=NULL && fast->next!=NULL )
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            found=1;
            printf("Cycle detected!");
            //To remove the cycle 
            while (fast->next!=slow)
            {
                fast=fast->next;
            }
            fast->next=NULL;
            printf("\nAlso cycle is remove successfully!");
            
        }

    }
    if(found==0){
        printf("\nNo cycle detected!");
    }
    
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
int main(){
    int ch,item;
    struct node *head=create(1);
    head->next=create(2);
    head->next->next=create(3);
    head->next->next->next=create(4);
    head->next->next->next->next=create(5);
    head->next->next->next->next->next=create(6);
    head->next->next->next->next->next->next=head->next->next->next;
    findAndRemoveCycle(head);
    display(head);
    
}