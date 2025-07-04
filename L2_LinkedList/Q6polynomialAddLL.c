#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node*next;
};
struct node * create(int c,int e ){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc failed! Memory is not assigned!");
        exit(0);
    }
    temp->coef=c;
    temp->exp=e;
    temp->next=NULL;
    return temp;
}
struct node * insertElement(struct node *head,int c,int e){
    if(head==NULL){
        head=create(c,e);
    }
    else{
        struct node *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=create(c,e);
    }
    return head;
}
void display(struct node *head){
    if(head==NULL){
        printf("Already Empty LL!");
    }
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%dx^%d",ptr->coef,ptr->exp);
        if(ptr->next!=NULL){
            printf("+");
        }
        ptr=ptr->next;
    }
}
void addTwoPoly(struct node *p1,struct node *p2){
    struct node * result=NULL;
    while(p1 && p2){
        if(p1->exp>p2->exp){
            result=insertElement(result,p1->coef,p1->exp);
            p1=p1->next;
        }
        else if(p1->exp<p2->exp){
            result=insertElement(result,p2->coef,p2->exp);
            p2=p2->next;
        }
        else{
            result=insertElement(result,(p1->coef+p2->coef),p1->exp);
            p1=p1->next;
            p2=p2->next;
        }
    }
    while (p1)
    {
        result=insertElement(result,p1->coef,p1->exp);
        p1=p1->next;
    }
    while (p2)
    {
        result=insertElement(result,p2->coef,p2->exp);
        p2=p2->next;
    }
    display(result);
}

int main(){
    printf("Enter the first polynomial!\n");
    struct node *p1=NULL;
    struct node *p2=NULL;
    int ch=1;
    do{
        int c,e;
        printf("Enter the value of coef=");
        scanf("%d",&c);
        printf("Enter the value of exp=");
        scanf("%d",&e);
        p1=insertElement(p1,c,e);
        printf("Enter 1 to continue and 0 to break!");
        scanf("%d",&ch);
    }while(ch!=0);
    printf("Polynomial 1=");
    display(p1);
    ch=1;
    printf("\nEnter the Second polynomial!\n");
    do{
        int c,e;
        printf("Enter the value of coef=");
        scanf("%d",&c);
        printf("Enter the value of exp=");
        scanf("%d",&e);
        p2=insertElement(p2,c,e);
        printf("Enter 1 to continue and 0 to break!");
        scanf("%d",&ch);
    }while(ch!=0);
    printf("Polynomial 2=");
    display(p2);
    printf("\nAfter Addition!\n");
    addTwoPoly(p1,p2);
}