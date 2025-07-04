#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//BFS Brath First Search : For insertion , Deletion and Traverse TC:O(n)
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create(int item){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc failed! No more space available!");
        exit(0);
    }
    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node * insert(struct node *root , int item){
    struct node *newNode=create(item);
    if(root==NULL){
        return newNode;
    }

    //Now we use BFS which require queue 
    #define max 100
    struct node* queue[max];
    int f=0;
    int r=0;
    queue[r++]=root;
    while(f<r){
        struct node *temp=queue[f++];
        if(temp->left){
            queue[r++]=temp->left;
        }
        else{
            temp->left=newNode;
            return root;
        }
        if(temp->right){
            queue[r++]=temp->right;
        }
        else{
            temp->right=newNode;
            return root;
        }
    }
    return root;
}

struct node * delete(struct node *root, int item){
    if(root==NULL){
        return NULL;
    }
    #define max 100
    struct node * queue[max];
    int f=0;
    int r=0;
    struct node *target=NULL;
    struct node *parent=NULL;
    struct node *last=NULL;
    queue[r++]=root;
    while(f<r){
        struct node *temp=queue[f++];
        if(temp->data==item){
            target=temp;
        }
        if(temp->left){
            parent=temp;
            queue[r++]=temp->left;
        }
        if(temp->right){
            parent=temp;
            queue[r++]=temp->right;
        }
        last=temp;
    }
    if(target!=NULL){
        target->data=last->data;
        if(parent->left==last){
            parent->left=NULL;
            free(last);
        }
        if(parent->right==last){
            parent->right=NULL;
            free(last);
        }
    }
    else{
        printf("Not exist !");
    }
    
    return root;
}
//NLR
void preorder(struct node *root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

//LNR
void inorder(struct node *root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
//LRN
void postorder(struct node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int countLeaves(struct node *root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return countLeaves(root->left)+countLeaves(root->right);
}
int main() {
    struct node* root = NULL;
    int choice, val;

    do {
        printf("\n\n--- Binary Tree Menu ---");
        printf("\n1. Insert a node");
        printf("\n2. Delete a node");
        printf("\n3. Inorder Traversal");
        printf("\n4. Preorder Traversal");
        printf("\n5. Postorder Traversal");
        printf("\n6. Count Leaf Nodes");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = delete(root, val);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 6:
                printf("Total Leaf Nodes: %d", countLeaves(root));
                break;
            case 0:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice!");
        }
    } while (choice != 0);

    return 0;
}