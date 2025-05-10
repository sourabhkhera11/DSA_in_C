#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Max size of the array 
#define max 100
//stack 
int stack[max];
//pointer to maintain insertion and deletion
int top1=-1;
int top2=max;
bool isempty1(){
    if(top1==-1){
        return true;
    }
    return false;
}
bool isempty2(){
    if(top2==max){
        return true;
    }
    return false;
}
bool isfull(){
    if(top1==top2-1){
        return true;
    }
    return false;
}
void push(int item,int choice){
    if(isfull()){
        printf("Overflow!");
        return;
    }
    if(choice==1){
        stack[++top1]=item;
    }else{
        stack[--top2]=item;
    }
}
int pop(int choice){
    if(choice==1){
        if(isempty1()){
            printf("Underflow!");
            return -1;
        }
        int item=stack[top1];
        top1--;
        return item;
    }
    else{
        if(isempty2()){
            printf("Underflow!");
            return -1;
        }
        int item=stack[top2];
        top2++;
        return item;
    }
}
int peek(int choice){
    if(choice==1){
        if(isempty1()){
            printf("Underflow!");
            return -1;
        }
        int item=stack[top1];
        return item;
    }
    else{
        if(isempty2()){
            printf("Underflow!");
            return -1;
        }
        int item=stack[top2];
        return item;
    }
}
void display(int choice){
    if(choice==1){
        if(isempty1()){
            printf("Underflow!");
            return;
        }
        printf("Forward Stack = ");
        for(int i=top1;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
    else{
        if(isempty2()){
            printf("Underflow!");
            return;
        }
        printf("Backward Stack = ");
        for(int i=top2;i<max;i++){
            printf("%d ",stack[i]);
        }
    }
}
int main(){
    int ch=1;
    int c,p;
    printf("\n1)Forward stack \n2)Backward Stack \n3)Exit");
    printf("\nEnter your choice=");
    scanf("%d",&ch);
    while(ch!=3)
    {
        printf("\n1)Push \n2)Pop \n3)Peek \n4)Display \n5)Exit");
        printf("\nEnter your choice=");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter push value=");
            scanf("%d",&p);
            push(p,ch);
            break;
        case 2:
            printf("\nPop element is %d",pop(ch));
            break;
        case 3:
            printf("\nPeek element is %d",peek(ch));
            break;
        case 4:
            display(ch);
            break;
        default:
            break;
        }
        printf("\n1)Forward stack \n2)Backward Stack \n3)Exit");
        printf("\nEnter your choice=");
        scanf("%d",&ch);
    } 
    
}