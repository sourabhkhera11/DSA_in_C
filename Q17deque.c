#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 10

int deque[max];

int f=-1;
int r=-1;

bool isempty(){
    return (f==-1 && r==-1);
}
bool isfull(){
    return ((f==0 && r==max-1) || (f==r+1));
}

void insertFront(int item){
    if(isfull()){
        printf("Overflow!");
        return;
    }
    if(isempty()){
        f=r=0;
        deque[f]=item;
        return;
    }
    else if(f==0){
        f=max-1;
        deque[f]=item;
    }
    else{
        f=f-1;
        deque[f]=item;
    }
}
void insertRear(int item){
    if(isfull()){
        printf("Overflow!");
        return;
    }
    if(isempty()){
        f=r=0;
        deque[r]=item;
        return;
    }
    else if(r==max-1){
        r=0;
        deque[r]=item;
    }
    else{
        r++;
        deque[r]=item;
    }
}
void deleteFront(){
    if(isempty()){
        printf("Underflow!");
        return;
    }
    if(f==max-1){
        printf("\nDeleted element =%d",deque[f]);
        f=0;
    }
    else{
        printf("\nDeleted element =%d",deque[f]);
        f++;
    }
}
void deleteRear(){
    if(isempty()){
        printf("Underflow!");
        return;
    }
    if(r==0){
        printf("\nDeleted element =%d",deque[r]);
        r=max-1;
    }
    else{
        printf("\nDeleted element =%d",deque[r]);
        r--;
    }
}
void getFront(){
    if(isempty()){
        printf("Underflow!");
        return;
    }
    printf("\nFront element=%d",deque[f]);
}
void getRear(){
    if(isempty()){
        printf("Underflow!");
        return;
    }
    printf("\nRear element=%d",deque[r]);
}
void display(){
    if(isempty()){
        printf("Underflow!");
        return;
    }
    printf("\nDeque= ");
    if(f<r){
        for(int i=f;i<=r;i++){
            printf("%d ",deque[i]);
        }
    }
    else{
        for(int i=f;i<max;i++){
            printf("%d ",deque[i]);
        }
        for(int i=0;i<=r;i++){
            printf("%d ",deque[i]);
        }
    }
}
int main(){
    int choice, item;

    while (1) {
        printf("\n--- Circular Deque Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Get Front Element\n");
        printf("6. Get Rear Element\n");
        printf("7. Display Deque\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                getFront();
                break;
            case 6:
                getRear();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}