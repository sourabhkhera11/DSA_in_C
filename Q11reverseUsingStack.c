#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
//Max size of the array 
#define max 100
//stack 
char stack[max];
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
char pop(){
    if(isempty()){
        printf("Underflow!");
        return -1;
    }
    char item=stack[top];
    top-=1;
    return item;
}
char peek(){
    if(isempty()){
        printf("Underflow!");
        return -1;
    }
    char item=stack[top];
    return item;
}
void display(){
    if(isempty()){
        printf("Underflow!");
        return ;
    }
    printf("\nStack=");
    for(int i=top;i>=0;i--){
        printf("%c",stack[i]);
    }
}
int main(){
    char string[10];
    printf("Enter a string of characters=");
    scanf("%s",string);
    int len=strlen(string);
    for(int i=0;i<len;i++){
        push(string[i]);
    }
    display();
}