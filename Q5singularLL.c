#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
struct node *head=NULL;
struct node * create(int item){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc failed! Memory is not assigned!");
        exit(0);
    }
    temp->info=item;
    temp->next=NULL;
    return temp;
}
//Insert at beg
void addToHead(int item){
    if(head==NULL){
        head=create(item);
    }
    else{
        struct node * temp=create(item);
        temp->next=head;
        head=temp;
    }
}
void addToTail(int item){
    if(head==NULL){
        head=create(item);
    }
    else{
        struct node * ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        struct node *temp=create(item);
        ptr->next=temp;
    }
}
void deleteFromHead(){
    if(head==NULL){
        printf("LL is already empty!");
    }
    else{
        struct node * temp=head;
        head=head->next;
        printf("Head element is deleted ie %d",temp->info);
        free(temp);
    }
}
void deleteFromTail(){
    if(head==NULL){
        printf("LL is already empty!");
    }
    else if(head->next==NULL){
        deleteFromHead();
    }
    else{
        struct node * ptr=head;
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        struct node * temp=ptr->next;
        ptr->next=NULL;
        printf("Tail element is deleted ie %d",temp->info);
        free(temp);
    }
}
void search(int item){
    if(head==NULL){
        printf("LL is empty!");
    }
    else{
        int pos=0;
        struct node * ptr=head;
        while(ptr!=NULL){
            pos++;
            if(ptr->info==item){
                printf("Found at %d position!",pos);
                return;
            }
            ptr=ptr->next;
        }
        printf("Not found!");
    }
}
void display(){
    if(head==NULL){
        printf("LL is empty!");
    }
    else{
        struct node *ptr=head;
        printf("LL =");
        while(ptr!=NULL){
            printf("%d ",ptr->info);
            ptr=ptr->next;
        }
    }
}
int main(){
    int choice=0;
    do{
        printf("\n-----------------Linear Linked List!------------------");
        printf("\n1)Add to head\n2)Add to tail\n3)Delete from head\n4)Delete from tail\n5)search \n9)Display\n10)exit");
        printf("\nEnter you choice=");
        scanf("%d",&choice);
        int item;
        switch (choice)
        {
        case 1:
            printf("\nEnter the element to be added=");
            scanf("%d",&item);
            addToHead(item);
            break;
        case 2:
            printf("\nEnter the element to be added=");
            scanf("%d",&item);
            addToTail(item);
            break;
        case 3:
            deleteFromHead();
            break;
        case 4:
            deleteFromTail();
            break;
        case 5:
            printf("\nEnter the element to be searched=");
            scanf("%d",&item);
            search(item);
            break;
        case 9:
            display();
            break;
        case 10:
            break;
        default:
            break;
        }
        if(choice==10){
            break;
        }
    }while (choice!=10);
    
    
}