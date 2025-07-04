#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Max size of the array 
#define max 100
//stack 
int stack[max];
//pointer to maintain insertion and deletion
int top=-1;

bool isempty(){
    if(top==-1){
        return true;
    }
    return false;
}
bool isfull(){
    if(top==max-1){
        return true;
    }
    return false;
}
void push(int item){
    if(isfull()){
        printf("Overflow!");
        return;
    }
    top+=1;
    stack[top]=item;
}
int pop(){
    if(isempty()){
        printf("Underflow!");
        return -1;
    }
    int item=stack[top];
    top-=1;
    return item;
}
int peek(){
    if(isempty()){
        printf("Underflow!");
        return -1;
    }
    int item=stack[top];
    return item;
}
void display(){
    if(isempty()){
        printf("Underflow!");
        return ;
    }
    printf("\nBinary value=");
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
    }
}
int main(){
    int dec;
    printf("Enter a decimal number=");
    scanf("%d",&dec);
    int num=dec;
    int rem;
    while (num!=1)
    {
        rem=num%2;
        push(rem);
        num/=2;
    }
    push(1);
    display();
    
}