#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
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
    printf("\nStack=");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
}
int main(){
    char str[10];
    printf("Enter a expression=");
    scanf("%s",str);
    int len=strlen(str);
    printf("Length =%d \n",len);
    for (int i = 0; i < len; i++)
    {
        char ch=str[i];
        if(isdigit(ch)){
            push(ch-'0');
        }
        else{
            int op2=pop();
            int op1=pop();
            switch (ch)
            {
            case '+':
                push(op1+op2);
                break;
            case '-':
                push(op1-op2);
                break;
            case '*':
                push(op1*op2);
                break;
            case '/':
                if(op2==0){
                    printf("Divisible by zero Error!");
                    exit(1);
                }
                push(op1/op2);
                break;
            default:
                printf("Invalid operator!");
                exit(1);
            }
        }
    }
    printf("Evaluated value= %d",pop());
}